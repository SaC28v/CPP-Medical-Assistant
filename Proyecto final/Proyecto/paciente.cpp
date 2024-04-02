#include "paciente.h"

Paciente::Paciente()
        :Persona()
{
    temperatura = 36.5;
    altura = 1.60;
    peso = 65.0;

}

Paciente:: Paciente(string n, string a, string c, float t, float al, float p)
        :Persona(n,a,c)
{
    temperatura = t;
    altura = al;
    peso = p;

}

void Paciente::setTemperatura(float t){
    temperatura = t;
}

float Paciente::getTemperatura(){
    return temperatura;
}

void Paciente::setAltura(float al){
    altura = al;
}

float Paciente::getAltura(){
    return altura;
}

void Paciente::setPeso(float p){
    peso = p;
}

float Paciente::getPeso(){
    return peso;
}

string Paciente::getNombres(){
    return nombres;
}

string Paciente::getApellidos(){
    return apellidos;
}

string Paciente::getCedula(){
    return cedula;
}
