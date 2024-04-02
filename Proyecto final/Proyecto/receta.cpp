#include "receta.h"

Receta::Receta(vector<string>Dat, string fecha) {   // Datos del paciente y la cantidad de medicamentos (Suele ser de 1 a 2)
    // Rellenar los cuadrantes con los encabezados
    Med = Dat;
    Recopilar[0].insert(make_pair(Encabezados.at(0),fecha));
}

void Receta::setPaciente(Paciente *P, Disease *D)
{
    Recopilar[1].insert(make_pair(Encabezados.at(1),P->getNombres()+" "+P->getApellidos()));
    Recopilar[2].insert(make_pair(Encabezados.at(2),D->getClase()));
}

void Receta::setMedicacion()
{
    Recopilar[3].insert(make_pair(Encabezados.at(3),Med.at(0)));
    Recopilar[4].insert(make_pair(Encabezados.at(4),Med.at(1)));
    Recopilar[5].insert(make_pair(Encabezados.at(5),Med.at(2)));
}

void Receta::setDoctor(Doctor *D)
{
    Recopilar[6].insert(make_pair(Encabezados.at(6),D->getNombres()+" "+D->getApellidos()));
    Recopilar[7].insert(make_pair(Encabezados.at(7),D->getCedula()));
}

void Receta::generarReceta()
{
    cout<<" - - - - - [Hospital] - - - - - "<<endl;
    for(auto const& I : Recopilar){
        if(I.first == 3)
            cout<<endl<<" - - - - - Medicacion - - - - - "<<endl;
        else if (I.first == n-2)
            cout<<" - - - - - - - - - - - - - - - - "<<endl<<endl;
        for(auto const& J : I.second)
            cout<<J.first<<": "<<J.second<<endl;
    }

}

map<int, map<string,string>> Receta::getMap()
{
    return Recopilar;
}
