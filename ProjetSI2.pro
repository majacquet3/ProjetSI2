SOURCES += \
    main.cpp \
    Handle/virtualhandle.cpp \
    Handle/modelhandle.cpp \
    Handle/videoview.cpp

HEADERS += \
    Handle/Handle.h \
    Handle/virtualhandle.h \
    Handle/modelhandle.h \
    Handle/videoview.h

LIBS += -lopencv_core \
        -lopencv_gpu \
        -lopencv_video \
        -lopencv_legacy \
        -lopencv_imgproc \
        -lopencv_highgui
