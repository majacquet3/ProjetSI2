#include "videoreader.h"

VideoReader::VideoReader()
    : m_video(nullptr)
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
