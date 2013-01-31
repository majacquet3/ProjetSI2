#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Handle/videoextractor.h"
#include "../Handle/videoview.h"
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    VideoExtractor m_extractor;
    QImage *image;

public slots :
    virtual void setImage(const ImageDataPtr result, const ImageDataPtr src1 , const ImageDataPtr src2);
};

#endif // MAINWINDOW_H
