HEADERS       = mainwindow.h \
                dialog_editmodule.h \
                dialog_editport.h \
                dialog_editrule.h \
                dialog_serialsync.h \
                myplc.h \
                myplcmodels.h


SOURCES       = main.cpp \
                dialog_editmodule.cpp \
                dialog_editport.cpp \
                dialog_editrule.cpp \
                dialog_serialsync.cpp \
                mainwindow.cpp \
                myplc.cpp \
                myplcmodels.cpp
QT           += widgets serialport
requires(qtConfig(filedialog))

EXAMPLE_FILES = example.vmrss

# install
target.path = C:\GD\RMS\software\vipex
INSTALLS += target

FORMS += \
    dialog_editmodule.ui \
    dialog_editport.ui \
    dialog_editrule.ui \
    dialog_serialsync-popup.ui \
    dialog_serialsync.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc
