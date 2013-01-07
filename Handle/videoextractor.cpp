#include "videoextractor.h"

#include "Handle.h"

VideoExtractor::VideoExtractor( bool dual )
    : m_stopped(true), m_dual(dual)
{
    //activer les caméras
}

void VideoExtractor::start(void)
{

}

//grab + wait

//VirtualHandle::executeHandle(MainHandle, recup1, recup2);
//MainHandle
