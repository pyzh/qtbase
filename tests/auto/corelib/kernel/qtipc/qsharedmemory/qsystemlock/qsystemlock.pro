CONFIG += qttest_p4
QT += gui-private

include(../src/src.pri)
win32: CONFIG += console
mac:CONFIG -= app_bundle

wince* {
    DEFINES	+= SRCDIR=\\\"\\\"
} else {
    DEFINES	+= SRCDIR=\\\"$$PWD\\\"
}

DESTDIR = ./

DEFINES	+= QSHAREDMEMORY_DEBUG
DEFINES	+= QSYSTEMSEMAPHORE_DEBUG

SOURCES		+= tst_qsystemlock.cpp 
TARGET		= tst_qsystemlock


