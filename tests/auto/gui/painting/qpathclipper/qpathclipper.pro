load(qttest_p4)
INCLUDEPATH += .
HEADERS += paths.h
SOURCES  += tst_qpathclipper.cpp paths.cpp
QT += gui-private

requires(contains(QT_CONFIG,private_tests))

unix:!mac:LIBS+=-lm
