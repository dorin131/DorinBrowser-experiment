QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    browser.cpp \
    canvas.cpp \
    console_in.cpp \
    console_out.cpp \
    main.cpp \
    request.cpp

HEADERS += \
    browser.h \
    canvas.h \
    console_in.h \
    console_out.h \
    request.h

FORMS += \
    browser.ui

# HTML

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../HTML/release/ -lHTML
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../HTML/debug/ -lHTML
else:unix: LIBS += -L$$OUT_PWD/../HTML/ -lHTML

INCLUDEPATH += $$PWD/../HTML
DEPENDPATH += $$PWD/../HTML

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../HTML/release/libHTML.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../HTML/debug/libHTML.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../HTML/release/HTML.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../HTML/debug/HTML.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../HTML/libHTML.a

# JS

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../JS/release/ -lJS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../JS/debug/ -lJS
else:unix: LIBS += -L$$OUT_PWD/../JS/ -lJS

INCLUDEPATH += $$PWD/../JS
DEPENDPATH += $$PWD/../JS

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JS/release/libJS.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JS/debug/libJS.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JS/release/JS.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../JS/debug/JS.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../JS/libJS.a

# curlpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../libs/curlpp-0.8.1/build/release/ -lcurlpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../libs/curlpp-0.8.1/build/debug/ -lcurlpp
else:unix: LIBS += -L$$PWD/../../libs/curlpp-0.8.1/build/ -lcurlpp -lcurl

INCLUDEPATH += $$PWD/../../libs/curlpp-0.8.1/include
DEPENDPATH += $$PWD/../../libs/curlpp-0.8.1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../libs/curlpp-0.8.1/build/release/libcurlpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../libs/curlpp-0.8.1/build/debug/libcurlpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../libs/curlpp-0.8.1/build/release/curlpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../libs/curlpp-0.8.1/build/debug/curlpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../libs/curlpp-0.8.1/build/libcurlpp.a
