#ifndef MODELHANDLE_H
#define MODELHANDLE_H

//you must include this header
#include "Handle.h"

/** @brief model for create a new handle. */
class ModelHandle : public VirtualHandle //all handle must herit by VirtualHandle
{
public:
    /** @brief Create a new ModelHandle<br>
    A modelHandle is an handle test which explain how write his own handle class. */
    ModelHandle(void);

    /** @brief Handle one or two IplImage<br>
        An ModelHandle's startHandle() will call startHandle one more time.
        @param IplImage * src1  : first image
        @param ImplImage * src2 : second image, NULL if unused
        @return IplImage * : handle's result.
      */
    virtual IplImage * startHandle(IplImage * src1, IplImage * src2);

    /** @brief For exemple */
    int tour;
};

#endif // MODELHANDLE_H
