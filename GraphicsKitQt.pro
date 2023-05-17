TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        button.cpp \
        examplecheckbox.cpp \
        gamemaster.cpp \
        listbox.cpp \
        main.cpp \
        graphics/graphics.cpp \
        numberinput.cpp \
        textbox.cpp \
        textinput.cpp \
        tile.cpp \
        widgets.cpp \
        window.cpp


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2_ttf.dll


INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

HEADERS += \
    board.hpp \
    button.hpp \
    examplecheckbox.hpp \
    gamemaster.hpp \
    listbox.hpp \
    numberinput.hpp \
    textbox.hpp \
    textinput.hpp \
    tile.hpp \
    widgets.hpp \
    window.hpp
