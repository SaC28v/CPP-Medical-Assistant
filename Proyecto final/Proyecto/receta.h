#ifndef RECETA_H
#define RECETA_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <map>
#include <array>

#include "doctor.h"
#include "paciente.h"
#include "disease.h"
using namespace std;

class Receta : public Doctor, public Paciente, public Disease
{
    int n = 8;  // Cantidad de datos de la receta
    vector<string>Med;
    vector<string>Encabezados = {"Fecha","Nombre del paciente","Diagnostico",   // Paciente
                                  "Medicamento","Cantidad","Indicaciones",      // Medicamento
                                  "Nombre del doctor","Cedula"};                // Doctor
    map<int, map<string,string>>Recopilar;  // Recopila todos los datos para ordenarlos en un map

public:
    Receta(vector<string>Dat, string fecha);
    void setPaciente(Paciente *P, Disease *D);
    void setMedicacion();
    void setDoctor(Doctor *D);
    void generarReceta();
    map<int, map<string,string>> getMap();
};

#endif // RECETA_H
