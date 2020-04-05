HEADERS       = mainwindow.h \
    dialog_addmodule.h \
    dialog_editmodule.h \
    dialog_editport.h \
    dialog_editrule.h \
    dialog_serial.h \
    myplc.h \
    myplcmodel.h
SOURCES       = main.cpp \
                dialog_addmodule.cpp \
                dialog_editmodule.cpp \
                dialog_editport.cpp \
                dialog_editrule.cpp \
                dialog_serial.cpp \
                mainwindow.cpp \
                myplc.cpp \
                myplcmodel.cpp
QT           += widgets serialport
requires(qtConfig(filedialog))

EXAMPLE_FILES = example.vmrss

# install
target.path = C:\GD\RMS\software\vipex
INSTALLS += target

FORMS += \
    dialog_addmodule.ui \
    dialog_editmodule.ui \
    dialog_editport.ui \
    dialog_editrule.ui \
    dialog_serial.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc
