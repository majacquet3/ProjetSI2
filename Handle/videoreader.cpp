#include "videoreader.h"

VideoReader::VideoReader()
{
}


IplImage * VideoReader::getImage(void)
{
    return cvQueryFrame(m_video);
    /*
    if (webcam)
        cvFlip(frame, frame, 1);
        */
}
