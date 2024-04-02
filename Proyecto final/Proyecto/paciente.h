#ifndef PACIENTE_H
#define PACIENTE_H
#include "persona.h"
#include "disease.h"

class Paciente:public Persona
{
protected:
    float temperatura;
    float altura;
    float peso;
    //vector <string> Sintomas;´herencia de disease
    vector <Disease> Enfermedades;

public:
    Paciente();
    Paciente(string n, string a, string c, float t, float al, float p);

    void setTemperatura(float t);
    float getTemperatura();
    void setAltura(float al);
    float getAltura();
    void setPeso(float p);
    float getPeso();

    //funciones overriding
    string getNombres();
    string getApellidos();
    string getCedula();

};

#endif // PACIENTE_H
