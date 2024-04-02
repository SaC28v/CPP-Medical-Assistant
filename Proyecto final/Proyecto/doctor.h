#ifndef DOCTOR_H
#define DOCTOR_H
#include "paciente.h"
#include "enfermero.h"

class Doctor:public Persona
{
public:
    Doctor();
    Doctor(string n, string a, string c);

    //void show();
    string getNombres();
    string getApellidos();
    string getCedula();

};

#endif // DOCTOR_H
