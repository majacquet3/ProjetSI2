#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <opencv2/opencv.hpp>
#include <QObject>

/** @brief Abstract class which used for show IplImage.
    The method setImage() is called by VideoExtractor each time an IplImage have been handled  */
class VideoView : QObject
{
    Q_OBJECT
public:
    VideoView();
    virtual ~VideoView(){}

public slots :
    /** @brief called when the handle of the current images are finished.
      Don't forget to connect it.
        @param Image result : handle result
        @param Image src1 : first image source
        @param Image src2 : second image source */
    virtual void setImage( IplImage result, IplImage src1 ,  IplImage src2) = 0;
};

#endif // VIDEOVIEW_H
