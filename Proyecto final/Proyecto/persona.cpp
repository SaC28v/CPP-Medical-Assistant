#include "persona.h"

Persona::Persona()
{
   nombres = "N/A";
   apellidos = "N/A";
   cedula = "0000000000";

}

Persona::Persona(string n, string a, string c)
{
    nombres = n;
    apellidos = a;
    cedula = c;

}
