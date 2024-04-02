#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <vector>
using namespace std;

class Persona //clase abstracta -> Herencia para Paciente, Enfermero y Doctor
{
protected:
    string nombres;
    string apellidos;
    string cedula;

public:
    Persona();
    Persona(string n, string a, string c);
    virtual string getNombres() = 0;
    virtual string getApellidos() = 0;
    virtual string getCedula() = 0;

};

#endif // PERSONA_H
