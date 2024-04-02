#include "disease.h"

Disease::Disease()
{
    nombre = "N/A";
}

void Disease::setSintomas(string S)
{
    Sintomas.push_back(S);
}

vector <string> Disease::getSintomas()
{
    return Sintomas;
}

void Disease::setEnfermedad(string E)
{
    Enfermedades.push_back(E);
}

vector <string> Disease::getEnfermedad()
{
    return Enfermedades;
}

void Disease::setCantEnf(int n)
{
    size = n;
}

int Disease::getCantEnf()
{
    return size;
}

void Disease::setClase(string N)
{
    nombre = N;
}

string Disease::getClase()
{
    return nombre;
}
