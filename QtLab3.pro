QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/Source/dataloader.cpp \
    Model/Source/figureselector.cpp \
    Model/Source/rectangle.cpp \
    Model/Source/transform.cpp \
    Model/Source/ellipse.cpp \
    Model/Source/datasaver.cpp \
    Model/Source/appdata.cpp \
    Model/Source/figure.cpp \
    View/Source/ellipsesetupview.cpp \
    View/Source/ellipserenderer.cpp \
    View/Source/figurerenderer.cpp \
    View/Source/rectanglerenderer.cpp \
    app.cpp \
    ellipsesetupdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    transformationdialog.cpp

HEADERS += \
    Model/Headers/dataloader.h \
    Model/Headers/datasaver.h \
    Model/Headers/appdata.h \
    Model/Headers/ellipse.h \
    Model/Headers/figure.h \
    Model/Headers/figureselector.h \
    Model/Headers/rectangle.h \
    Model/Headers/transform.h \
    View/Headers/ellipserenderer.h \
    View/Headers/ellipsesetupview.h \
    View/Headers/figurerenderer.h \
    View/Headers/rectanglerenderer.h \
    app.h \
    ellipsesetupdialog.h \
    mainwindow.h \
    transformationdialog.h

FORMS += \
    ellipsesetupdialog.ui \
    mainwindow.ui \
    transformationdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
