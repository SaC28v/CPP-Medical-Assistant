#ifndef FAMILIA_H
#define FAMILIA_H
#include <iostream>
#include <vector>
using namespace std;

class Familia
{
    string nombre;
    vector <string> Sintomas;

public:
    Familia();
    void setSintomas(string S);
    vector <string> getSintomas();
    void setClase(string N);
    string getClase();
};

#endif // FAMILIA_H
