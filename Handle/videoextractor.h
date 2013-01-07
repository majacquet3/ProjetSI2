#ifndef VIDEOEXTRACTOR_H
#define VIDEOEXTRACTOR_H

#include <QThread>


/** @brief Extract one or two video stream and call VideoView::setImage after handle the image with the MainHandle
  specified in Handle.h.
  Have his own thread.
  */
class VideoExtractor : public QThread
{
public :
    /** @brief Create a new VideoExtractor
      @param bool dual : true if we use two camera, false if we use only one camera */
    VideoExtractor(bool dual = true); // hérite de QThread


    /** @brief stop the video stream handle */
    inline void stop(void);

    /** @brief return true if the handle is stopped
      @return bool : true if the handle is stopped else return false.
      */
    inline bool isStopped(void);

    /** @brief start the video stream handle in his own thread. */
    void start(void);
private :

    /** @brief true if the handle is stopped else return false */
    bool m_stopped;

    /** @brief true if we use two camera, false if we use only one camera */
    bool m_dual;

    /** @brief start the VideoExtractor's thread */
    void run(void);

};

inline bool VideoExtractor::isStopped(void)
{
    return m_stopped;
}

inline void VideoExtractor::stop(void)
{
    m_stoped = true;
}

#endif // VIDEOEXTRACTOR_H
