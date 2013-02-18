#include "videoextractor.h"

#include <QElapsedTimer>

#include "../exception.h"
#include "Handle.h"

VideoExtractor::VideoExtractor(bool dual, VideoReader * source1, VideoReader * source2 )
    : m_stopped(true), m_dual(dual), m_videoStream{ source1 , source2 },
    m_currentParent(nullptr)
{
    auto lambda = [this]( QVariant Value, HandleParameters * hp )
    {
            hideParameters();
            hp->acceptChanges(Value);
            if( m_currentParent )
                showParameters(m_currentParent);
    };
    m_paramHandle.setActionOnChangeValue( lambda );
    threadLanced = false;
}

void VideoExtractor::showParameters(QWidget *parent)
{
        m_currentParent = parent;
        VirtualHandle::showParameters(parent, m_paramHandle.toString().toStdString());
}

void VideoExtractor::hideParameters(void)
{
    if( m_paramHandle.toString() != "" )
        VirtualHandle::hideParameters(m_paramHandle.toString().toStdString());
}

void VideoExtractor::start(qint64 timeMax, qint64 nbMaxImage)
{
    if( m_stopped != true )
        return;
    m_timeMax = timeMax;
    m_nbMaxImage = nbMaxImage;
    m_stopped = false;
    m_nbImageHandled = 0;
    QThread::start();
}


void VideoExtractor::run(void)
{
    bool stoppedByUser = true;
    QElapsedTimer timer;
    //qint64 endOfCapture;
    //qint64 endOfHandle;
    qint64 begin;
    IplImage * src1, * src2;
    timer.start();
    while( ! m_stopped )
    {
        begin = timer.nsecsElapsed();

        m_videoStream[0]->grab(); // a for for that ... I'm too lazy
        m_videoStream[1]->grab();

        if( m_timeMax && m_timeMax > begin)
        {
            stoppedByUser = false;
            break;
        }

        src1 = m_videoStream[0]->getImage();
        src2 = m_videoStream[1]->getImage();

        ImageDataPtr source1 = nullptr, source2 = nullptr;

        if(src1)
            source1 = ImageDataPtr(new ImageData(*src1));
        if(src2)
            source2 = ImageDataPtr(new ImageData(*src2));
        else if(! src1)
            break;

        //endOfCapture = timer.nsecsElapsed();
        ImageDataPtr result;
        if(isStarted())
            result = VirtualHandle::executeHandle(m_paramHandle.toString().toStdString(), source1, source2);
        else
            result = source1;
        //endOfHandle = timer.nsecsElapsed();
        if( ! result)
        {
            throw Exception::buildException("Votre traitement ne retourne pas de résultat!", "VideoExtractor", "run", EPC);
        }

        m_nbImageHandled++;
        emit imageHandled(result, source1, source2);
        if( m_nbMaxImage && m_nbImageHandled == m_nbMaxImage )
        {
            stoppedByUser = false;
            break;
        }
        qint64 waitTime = ( m_paramPeriod.toInt() - timer.nsecsElapsed() + begin )/1000;
        if(waitTime < 0)
        {
            std::cerr << "Warning : la boucle a du retard : " <<  waitTime
                      << "\nDuree de la boucle : " << m_paramPeriod.toInt()
                      << "\nDuree reelle : " << timer.nsecsElapsed() << std::endl;
        }
        else
            QThread::usleep( waitTime );
    }

    emit finished(stoppedByUser);
    deleteLater();
}

void VideoExtractor::useSource(VideoReader * source, int channel)
{
    delete m_videoStream[channel];
    m_videoStream[channel] = source;
}

VideoExtractor::~VideoExtractor()
{
    delete m_videoStream[0];
    delete m_videoStream[1];
}

void VideoExtractor::changeHandleParameters( SourceParameters * source, QWidget * area)
{
    m_paramHandle.changeSources(source);
    m_paramHandle.showParameters( area );
}

void VideoExtractor::changePeriodeParameters( SourceParameters *source, QWidget * area)
{
    m_paramPeriod.changeSources(source);
    m_paramPeriod.showParameters( area );
}

void VideoExtractor::stopFlux(void)
{
    threadLanced = false;
}

void VideoExtractor::lancerFlux(void)
{
    threadLanced = true;
}

bool VideoExtractor::isStarted(void)
{
    return threadLanced;
}
