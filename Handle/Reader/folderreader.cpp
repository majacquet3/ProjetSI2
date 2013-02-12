#include "folderreader.h"
#include <QRegExp>
#include <QStringList>


FolderReader::FolderReader(const std::string & path)
{
    QDir dir( path.c_str() );

    bool rep = isPossible(path);

    if(rep == false)
        throw Exception::buildException("Attention le dossier " + path + " n'existe pas ou vous n'avez pas les droits pour y accéder.", "FolderReader", "Folderreader", EPC);

    QFileInfoList liste = dir.entryInfoList(QDir::Files);

    int i = 0;

    for( auto info : liste)
    {
        std::cout << info.fileName().toStdString() << std::endl;

        m_listePath[parseFileName(info.fileName())] = info.fileName();
        QDateTime t = parseFileName(info.fileName());

        std::cout << t.isValid() << std::endl;
    }

    std::cout << m_listePath.size() << ":" << i <<std::endl;

    m_iterator = m_listePath.end();
}



QDateTime FolderReader::parseFileName(QString fileName){
    QRegExp reg;
    QDateTime time;
    QStringList dataList;
    reg.setPattern("._(\\d+)-(\\d+)-(\\d+)-(\\d+)h(\\d+)m(\\d+)s(\\d+).*");
    fileName.replace(reg,"\\0\n\\1\n\\2\n\\3\n\\4\n\\5\n\\6\n\\7");
    dataList = fileName.split('\n');

    if(dataList.size() != 8)
        throw ParseException::buildParseException("The file's name : "+ fileName.toStdString() +" is incorrect.", "FolderReader", "parseFileName",EP);

    time.addYears(dataList[1].toInt());
    time.addMonths(dataList[2].toInt());
    time.addDays(dataList[3].toInt());

    QTime test(dataList[4].toInt(),dataList[5].toInt(),dataList[6].toInt(),dataList[7].toInt());
    time.setTime(test);

    /*
    time.addSecs(dataList[4].toInt() * 3600);
    time.addSecs(dataList[5].toInt() * 60);
    time.addSecs(dataList[6].toInt());

    time.addMSecs(dataList[7].toInt());
    */

    return time;
}


void FolderReader::grab()
{
    if(m_iterator == m_listePath.end() )
        m_iterator = m_listePath.begin();

    ++m_iterator;
}



bool FolderReader::acceptSeek(void)
{
    return true;
}


void FolderReader::remplissage(const std::string nom, QDateTime date, QString s)
{
    std::map<QDateTime, QString> listePath;

    bool rep = isPossible(nom);

    if(rep == false)
        throw Exception::buildException("Attention ce n'est pas un nom de dossier valide !!!", "FolderReader", "remplissage", EPC);

    for(ListPath::iterator it = listePath.begin() ; it != listePath.end() ; ++it)
    {
        if(it->first == date)
            it->second = s;
    }
}



bool FolderReader::isPossible(const std::string nom)
{
    QDir dir( nom.c_str() );

    if( (!(dir.isReadable())) )
        return false;

    return true;
}



IplImage * FolderReader::getImage(void)
{
    static IplImage * data = NULL;

    if( data )
    {
        cvReleaseImage(&data);
    }

    if( m_iterator == m_listePath.end() )
    {
        throw Exception::buildException("Pas d'images restantes", "FolderReader", "getImage", EPC);
    }

    data = cvLoadImage( m_iterator->second.toStdString().c_str() );

    return data;
}


