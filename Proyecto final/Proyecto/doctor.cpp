#include "doctor.h"

Doctor::Doctor()
      :Persona()
{
}

Doctor::Doctor(string n, string a, string c)
      :Persona(n,a,c)
{

}

string Doctor::getNombres(){
    return nombres;
}

string Doctor::getApellidos(){
    return apellidos;
}

string Doctor::getCedula(){
    return cedula;
}
