#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_extractor(new VideoExtractor() )
{
    VideoReader * cam1 = new VideoReader();
    cam1->useCamera();
    ui->setupUi(this);
    qRegisterMetaType<ImageDataPtr>("ImageDataPtr");/* obligatoire, Ã  n'appeler qu'une fois et dans une fonction /!\ */
    connect( m_extractor, SIGNAL(imageHandled(ImageDataPtr,ImageDataPtr,ImageDataPtr)),
             this, SLOT(setImage(ImageDataPtr,ImageDataPtr,ImageDataPtr)));
    FolderReader * f = new FolderReader("/home/mathieu/Dropbox/ProjetSI/ImagesVolcan/cam49-05-10-2012_time_21-38-54-0193");
    m_extractor->useSource(f, 0);
    //m_extractor->useSource(cam1, 0);
    m_extractor->start(200000000);
}

MainWindow::~MainWindow()
{
    m_extractor->stop();
    delete ui;
}

void MainWindow::setImage(const ImageDataPtr result, const ImageDataPtr , const ImageDataPtr)
{
    if(result)
    {
    result->toPixmap();
    ui->labelImage;
    ui->labelImage->setPixmap(result->toPixmap());
    }
}
