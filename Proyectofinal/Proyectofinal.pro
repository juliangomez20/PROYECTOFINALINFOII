QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    cuerda.cpp \
    disco.cpp \
    enemigos.cpp \
    findeljuego.cpp \
    iniciodesesion.cpp \
    jefe_final.cpp \
    jugador.cpp \
    main.cpp \
    juego.cpp \
    menu.cpp \
    multijugador.cpp \
    plataformas.cpp \
    puntaje.cpp \
    registrarse.cpp \
    vidas.cpp \
    winer.cpp

HEADERS += \
    bullet.h \
    cuerda.h \
    disco.h \
    enemigos.h \
    findeljuego.h \
    iniciodesesion.h \
    jefe_final.h \
    juego.h \
    jugador.h \
    librerias.h \
    menu.h \
    multijugador.h \
    plataformas.h \
    puntaje.h \
    registrarse.h \
    vidas.h \
    winer.h

FORMS += \
    findeljuego.ui \
    iniciodesesion.ui \
    juego.ui \
    menu.ui \
    multijugador.ui \
    registrarse.ui \
    winer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc \
    Musica.qrc
