#include "exception.h"

Exception::Exception(const std::string &msg,
                     const std::string &MsgError,
                     const std::string &ClassName,
                     const std::string &MethodName,
                     const std::string &FileName,
                     const unsigned int line,
                     const void * const ptr,
                     const std::string & pretty)
        : std::runtime_error(msg),
          MsgError(MsgError),
          ClassName(ClassName),
          MethodName(MethodName),
          FileName(FileName),
          line(line),
          ptr(ptr),
          pretty(pretty)
{
}
