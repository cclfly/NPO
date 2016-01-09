#---------------------------------------------------
#	NPO
#	Network Public Opinion
#	Created 2016-01-07T18:56:53
#---------------------------------------------------

TEMPLATE	=	app

QT	+=	core widgets gui

TARGET	=	NPO

QMAKE_CXXFLAGS	+=	-std=c++11

SOURCES	+= \	
    npo.cpp \
    main.cpp \
    result.cpp \
    resultitem.cpp
HEADERS	+= \	
    npo.h \
    result.h \
    resultitem.h
