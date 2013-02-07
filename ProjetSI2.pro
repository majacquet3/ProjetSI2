Qt += system

QMAKE_CXXFLAGS += -std=c++0x
CXXFLAGS="-std=c++11"

SOURCES += \
    main.cpp \
    Handle/virtualhandle.cpp \
    Handle/modelhandle.cpp \
    Handle/videoview.cpp \
    Handle/videoextractor.cpp \
    Handle/videoreader.cpp \
    Handle/imagedata.cpp \
    View/mainwindow.cpp \
    exception.cpp \
    Handle/putyourcodehere.cpp \
    Handle/Reader/folderreader.cpp

HEADERS += \
    Handle/Handle.h \
    Handle/virtualhandle.h \
    Handle/modelhandle.h \
    Handle/videoview.h \
    Handle/videoextractor.h \
    Handle/videoreader.h \
    Handle/imagedata.h \
    View/mainwindow.h \
    exception.h \
    Handle/putyourcodehere.h \
    Handle/Reader/folderreader.h

LIBS += -lopencv_core \
        -lopencv_gpu \
        -lopencv_video \
        -lopencv_legacy \
        -lopencv_imgproc \
        -lopencv_highgui

OTHER_FILES += \
    README.md

FORMS += \
    View/mainwindow.ui
