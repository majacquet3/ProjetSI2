#include "virtualhandle.h"

VirtualHandle::VirtualHandle(const std::string & name)
    : m_name(name)
{
    m_listHandle[name] = this;
}

VirtualHandle::ListHandle VirtualHandle::m_listHandle;

IplImage * VirtualHandle::executeHandle(const std::string & name, const IplImage * src1, const IplImage * src2)
{
    return m_listHandle[name]->startHandle(src1, src2);
}
