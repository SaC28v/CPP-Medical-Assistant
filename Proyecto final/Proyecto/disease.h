#ifndef DISEASE_H
#define DISEASE_H
#include <iostream>
#include <vector>
using namespace std;

class Disease
{
    int size;
    string nombre;
    vector <string> Sintomas;
    vector <string> Enfermedades;
public:
    Disease();
    void setSintomas(string S);
    vector <string> getSintomas();

    void setEnfermedad(string E);
    vector <string> getEnfermedad();
    void setCantEnf(int n);
    int getCantEnf();

    void setClase(string N);
    string getClase();
};

#endif // DISEASE_H
