#include "familia.h"

Familia::Familia()
{
    nombre = "N/A";
    //Sintomas.push_back();
}

void Familia::setSintomas(string S)
{
    Sintomas.push_back(S);
}

vector <string> Familia::getSintomas()
{
    return Sintomas;
}

void Familia::setClase(string N)
{
    nombre = N;
}

string Familia::getClase(){
    return nombre;
}
