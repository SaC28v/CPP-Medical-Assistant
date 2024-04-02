TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        disease.cpp \
        doctor.cpp \
        enfermero.cpp \
        main.cpp \
        paciente.cpp \
        persona.cpp \
        receta.cpp

HEADERS += \
    disease.h \
    doctor.h \
    enfermero.h \
    paciente.h \
    persona.h \
    receta.h
