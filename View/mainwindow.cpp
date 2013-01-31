#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( &m_extractor, SIGNAL(imageHandled(ImageDataPtr,ImageDataPtr,ImageDataPtr)),
             this, SLOT(setImage(ImageDataPtr,ImageDataPtr,ImageDataPtr)));

    ui->sliderCurseur->setTickInterval(1);
    ui->labelCurseur->setNum(0);
    connect(ui->sliderCurseur,SIGNAL(valueChanged(int)),ui->labelCurseur,SLOT(setNum(int)));

    connect(ui->buttonNext, SIGNAL(clicked()), ui->labelImage,
            SLOT(setPixmap
                 (QPixmap("/home/mathieu/Dropbox/ProjetSI/ImagesVolcan/cam49-05-10-2012_time_21-38-54-0193$/TIFF_Image_2012-10-05-21h39m14s947.TIFF"))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setImage(const ImageDataPtr result, const ImageDataPtr , const ImageDataPtr)
{
    ui->labelImage->setPixmap(result->toPixmap());
}

