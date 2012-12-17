#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <opencv2/opencv.hpp>

/** @brief Abstract class which used for show IplImage.
    The method setImage() is called by VideoExtractor each time an IplImage have been handled  */
class VideoView
{
public:
    VideoView();
    virtual ~VideoView(){}

    /** @brief Set the new Image to the View.
        @param IplImage * src1 : source 1, NULL if unused.
        @param IplImage * src2 : source 2, NULL if unused.
        @param IplImage * result : handle's result, NULL if unused. */
    virtual void setImage( IplImage * src1 , IplImage * src2 , IplImage * result) = 0;
};

#endif // VIDEOVIEW_H
