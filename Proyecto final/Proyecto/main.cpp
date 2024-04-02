#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <map>
#include <array>
#include <cstdlib>

#include "disease.h"
#include "persona.h"
#include "paciente.h"
//#include "enfermero.h"
#include "doctor.h"
#include "receta.h"

using namespace std;

void clearCin();    // Esta funcion se creo especificamente para usar cin y getline
bool IngresarAdmin(string, string, string);
void Enfermedad(int num, Disease *d);
void GeneratePatient(Paciente p);
void ModificatePatient(Paciente p);
void EscribirSintomas(Disease *d, Paciente *p, string date, int n1);
bool SearchPerson(string c);
void Diagnostico(Disease *d, Paciente *p, string date);
void GenerarReceta(Receta r, Paciente *p);

// Utilizar el método de lectura para leer los datos del nombre del usuario e ingresar los dos datos, NombreUsuario y cedula, para luego comparar
int main()
{
    string nombres;
    string apellidos;
    string cedula;
    string NombreUsuario;
    string ApellidoUsuario;
    float temperatura;
    float altura;
    float peso;
    bool menup = false;
    bool menu = false;

    int opcion;

    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<" - - - - - - - - - - - {Medical Corporation} - - - - - - - - - - - "<<endl;

    Doctor *D;
    do{
        cout<<"Ingresar Nombre de Usuario: ";
        getline(cin, NombreUsuario);
        cout<<"Ingresar Apellido de Usuario: ";
        getline(cin, ApellidoUsuario);
        cout<<"Ingresar Cedula: ";
        getline(cin, cedula);

        menup = IngresarAdmin(NombreUsuario,ApellidoUsuario,cedula);

        if (menup)
            cout << "Acceso permitido al programa.\n" << endl;
        else
            cout << "Nombre de usuario o ID incorrecto.\n" << endl;

    } while (!menup);

    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\tBienvenido a nuestro consultorio medico"<<endl;

    D = new Doctor (NombreUsuario,ApellidoUsuario,cedula);

    do {
        cout<<" 1. Agregar paciente"<<endl;
        cout<<" 2. Anadir sintomatologia"<<endl;
        cout<<" 3. Diagnostico"<<endl;
        cout<<" 4. Generar receta"<<endl;
        cout<<" 5. Cerrar sesion "<<endl;

        cout<<"Opcion: ";
        cin>>opcion;
        clearCin();
        cout<<endl;

        cout<<"----------------------------------------------------------------------"<<endl;
        Paciente *P;
        Disease *A;
        Disease *A2;

        if (opcion == 1) {
            cout<<"Ingresar nombres del paciente: ";
            getline(cin, nombres);
            cout<<"Ingresar apellidos del paciente: ";
            getline(cin, apellidos);
            cout<<"Ingresar cedula del paciente: ";
            getline(cin, cedula);

            cout<<endl;
            cout<<"Altura (cm): ";
            cin>>altura;
            cout<<"Peso (kg): ";
            cin>>peso;
            cout<<"Temperatura (Grados C): ";
            cin>>temperatura;
            clearCin();

            Paciente Pacient(nombres,apellidos,cedula,temperatura,altura,peso);
            P = new Paciente (Pacient);
            cout<<"Datos registrados exitosamente!"<<endl<<endl;

            if (SearchPerson(cedula)){
                cout<<"Paciente registrad@ en la base de datos"<<endl<<endl;
                ModificatePatient(Pacient);
            }
            else{
                cout<<""<<nombres<<" "<<apellidos<<" Ingresad@ exitosamente!"<<endl<<endl;
                GeneratePatient(Pacient);
            }
            cout<<endl<<"----------------------------------------------------------------------"<<endl;

        }

        else if (opcion == 2) {
            string fecha;
            cout<<"Ingrese la fecha de la consulta: "; getline(cin,fecha);

            string s;
            int n1;
            cout<<endl<<"Ingrese la cantidad de sintomas del paciente: "<<endl;
            cin>>n1;
            clearCin();

            Disease d;

            cout<<endl<<"Ingrese los sintomas: "<<endl;
            for(int i=0; i<n1; i++){
                getline(cin, s);
                d.setSintomas(s);
            }

            A2 = new Disease (d);

            Enfermedad(n1, A2);  // Se busca por las enfermedades posiblemente relacionadas con los sintomas
            EscribirSintomas(A2, P, fecha, n1);

            delete A2;
            cout<<endl<<"----------------------------------------------------------------------"<<endl;
        }

        else if (opcion == 3){
            string fecha;
            cout<<"Ingrese la fecha de la consulta: "; getline(cin,fecha);

            Disease D;
            string Diag;
            cout<<endl<<"Ingrese el diagnostico del paciente: "<<endl;
            getline(cin,Diag);
            D.setClase(Diag);

            A = new Disease (D);

            Diagnostico(A, P, fecha);
            cout<<endl<<"----------------------------------------------------------------------"<<endl;
        }

        else if (opcion == 4){
            // Normalmente se suele trabajar con un medicamento por lo que el programa solo tomará en cuenta un medicamento para la receta
            string fecha;
            cout<<"Ingrese la fecha de la consulta: "; getline(cin,fecha);

            cout<<endl<<"Ingresar los datos del medicamento"<<endl<<endl;
            vector<string>Med;
            string med;
            cout<<"Nombre general del medicamento: "<<endl;
            getline(cin,med);
            Med.push_back(med);
            cout<<"Cantidad: "<<endl;
            getline(cin,med);
            Med.push_back(med);
            cout<<"Indicaciones: "<<endl;
            getline(cin,med);
            Med.push_back(med);

            Receta Rec(Med,fecha);
            Rec.setPaciente(P,A);
            Rec.setMedicacion();
            Rec.setDoctor(D);

            //Rec.generarReceta();
            GenerarReceta(Rec, P);

            cout<<endl<<"----------------------------------------------------------------------"<<endl;
        }

        else if (opcion == 5){
            cout<<endl<<"Cerrando sesion..."<<endl<<endl;
            menu = true;
            delete P;
        }

        else
             cout<<"No tenemos registrada esa opcion. Por favor, intentelo denuevo.\n"<<endl;

    } while(!menu);

}


void clearCin(){    // Esta funcion se creo especificamente para usar cin y getline
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
}

bool IngresarAdmin(string Name, string Apellido, string RUC){    // Ingresar el Nombre y la Cedula de Identidad
    ifstream archivo;
    string texto;
    bool menu = false;
    archivo.open("Administradores.txt",ios::in); // Abrir el archivo


    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    while(!archivo.eof()){ // Mientras no sea el final del archivo
        getline(archivo,texto);

        size_t pos = texto.find(",");
        string token;

        token = texto.substr(0,pos);
        if(token == Name){
            pos++;
            texto.erase(0,pos);
            pos = texto.find(",");
            token = texto.substr(0,pos);
        }
        if(token == Apellido){
            pos++;
            texto.erase(0,pos);
            token = texto;
        }
        if(token == RUC){
            menu=true;
        }
    }

    archivo.close(); // Cerramos el programa

    return menu;
}

void Enfermedad(int num, Disease *d){  //string *p[]
    ifstream archivo;
    string texto;
    int n = 0, s = 0;

    // Comienzo del códgio del archivo de lectura
    archivo.open("Sintomas.txt",ios::in); // Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    map<int, map<int ,string>> MapS; // Mapa de los síntomas de todas las enfermedades
    map<int, string>sin; // Se almacenara el nombre de la enfermedad si tiene más de tres síntomas similares
    int cnt;    // Contador de las enfermedades relaciones

    string enf, name_enf;   // Variables para guardar el nombre de la enfermedad

    while(!archivo.eof()){ // Mientras no sea el final del archivo
        getline(archivo,texto);
        size_t lin_pos = texto.find("-");
        enf = texto.substr(0, lin_pos);

        if(enf == "Enfermedad"){
            n++;    // Número de la enfermedad
            s = 0;  // Se resetean los síntomas con cada enfermedad
            name_enf = texto.substr(lin_pos+1);
        }
        else{
            for(int i=0; i<num; i++){   // Comparar los síntomas ingresados con la lista
                if (texto == d->getSintomas().at(i)){
                    s++;
                    MapS[n][s] = texto;
                    cout<<endl<<"Sintoma detectado: "<<texto<<endl;
                }
            }
            if(s >= 3){
                sin[n] = name_enf;
                cnt++;
                d->setEnfermedad(sin[n]);
            }
        }
    }

    int n1;

    cout<<endl<<" - - - - - Fin de la busqueda - - - - - "<<endl;
    cout<<"Enfermedades relacionadas:"<<endl;

    if(cnt >= 1){
        for(auto const& p : sin)
            for(auto const& map1 : MapS){
                if(map1.first == p.first){
                    cout<<p.second<<endl;
                    n1++;
                    cout<<"Sintomas relacionados con la enfermedad:"<<endl;
                    for(auto const& map2 : map1.second)
                        cout<<map2.first<<" ---> "<<map2.second<<endl;
                    cout<<endl;
                }
            }
    }
    else
        cout<<"En la base de datos no existen enfermedades relacionadas"<<endl;

    d->setCantEnf(n1);
    cout<<endl;

    archivo.close(); // Cerramos el programa
}

void GeneratePatient(Paciente p){
    ofstream archivo;
    string nombreP; // La primera variable pertenece al nombre del archivo

    nombreP = "Paciente_ " + p.getCedula() + ".txt";

    archivo.open(nombreP.c_str(),ios::out); // Abrir el archivo

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    archivo<<"Nombres:\t"<<p.getNombres()<<endl;
    archivo<<"Apellidos:\t"<<p.getApellidos()<<endl;
    archivo<<"Cedula:\t\t"<<p.getCedula()<<endl;
    archivo<<"Enfermedad autosomica: N/A"<<endl<<endl;
    archivo<<"Datos del paciente: "<<endl;
    archivo<<"- Temperatura:\t"<<p.getTemperatura()<<" °C"<<endl;
    archivo<<"- Altura:\t"<<p.getAltura()<<endl;
    archivo<<"- Peso:\t\t"<<p.getPeso()<<" kg"<<endl<<endl;
    archivo<<" - - - - - [Historia Medica] - - - - - "<<endl;

    archivo.close(); // Cerrar archivo
}

void ModificatePatient(Paciente p){
    /* En este caso me tocara abrir un archivo de lectura (in) y otro temporal para escribir
     * (out) con el fin de ir copiando cada linea del archivo original al temporal y modificar
     * las lineas que necesito, luego eliminar el archivo original y renombrar el archivo
     * temporal
     */

    string nombreP = "Paciente_ " + p.getCedula() + ".txt"; // La primera variable pertenece al nombre del archivo
    ifstream archivoO(nombreP);  // Archivo original
    remove("temp.txt");
    ofstream archivoT("temp.txt");  // Archivo temporal
    string texto;


    if(archivoO.is_open() && archivoT.is_open()) {
        int i=0;
        while(getline(archivoO,texto)){
            if(i == 6)
                archivoT << "- Temperatura:\t" << p.getTemperatura() << " °C" << endl;
            else if(i == 7)
                archivoT << "- Altura:\t" << p.getAltura() << endl;
            else if(i == 8)
                archivoT << "- Peso:\t\t" << p.getPeso() << " kg" << endl;
            else
                archivoT << texto << endl;
            i++;
        }

        archivoO.close();
        archivoT.close();

        if(archivoT.good()){
            remove(nombreP.c_str());
            rename("temp.txt", nombreP.c_str());
        }
        else
            cout<<"Error al cerrar el archivo temporal"<<endl;
    }

    else
        cout<<"No se pudo abrir uno o ambos archivos"<<endl;
}

void EscribirSintomas(Disease *d, Paciente *p, string date, int n1){
    ofstream archivo;
    string nombreP; // La primera variable pertenece al nombre del archivo

    nombreP = "Paciente_ " + p->getCedula() + ".txt";

    archivo.open(nombreP.c_str(),ios::app); // Abrir el archivo pero solo para añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    archivo<<endl<<"Fecha: "<<date<<endl;
    archivo<<" Sintomatología"<<endl;
    for(int i=0; i<n1; i++)
        archivo<<"* "<<d->getSintomas().at(i)<<endl;
    cout<<endl;
    archivo<<" Posibles enfermedades"<<endl;
    d->getCantEnf();
    int n2 = d->getCantEnf();
    if (n2 > 0)
        for(int i=0; i<n2; i++)
            archivo<<"- "<<d->getEnfermedad().at(i)<<endl;
    cout<<endl<<endl;

    archivo.close(); // Cerrar archivo
}

bool SearchPerson(string c){
    ifstream archivo;
    string nombreP; // La primera variable pertenece al nombre del archivo
    bool test = false;

    nombreP = "Paciente_ " + c + ".txt";

    archivo.open(nombreP.c_str(),ios::in); // Abrir el archivo pero solo para añadir

    if(archivo.fail())
        cout<<"Paciente sin registrar en la base de datos\n";
    else
        test = true;

    archivo.close(); // Cerramos el programa

    return test;
}

void Diagnostico(Disease *d, Paciente *p, string date){
    ofstream archivo;
    string nombreP; // La primera variable pertenece al nombre del archivo

    nombreP = "Paciente_ " + p->getCedula() + ".txt";

    archivo.open(nombreP.c_str(),ios::app); // Abrir el archivo pero solo para añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    archivo<<endl<<"Fecha: "<<date<<endl;
    archivo<<" DIAGNOSTICO"<<endl;
    archivo<<"# "<<d->getClase()<<endl;
    cout<<endl<<endl;

    archivo.close(); // Cerrar archivo
}

void GenerarReceta(Receta r, Paciente *p){
    ofstream archivo;
    string nombreP; // La primera variable pertenece al nombre del archivo

    nombreP = "Receta_ " + p->getCedula() + ".txt";

    archivo.open(nombreP.c_str(),ios::out); // Abrir el archivo

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    map<int, map<string,string>> Recopilar = r.getMap();

    archivo<<" - - - - - [Hospital] - - - - - "<<endl;
    for(auto const& I : Recopilar){
        if(I.first == 3)
            archivo<<endl<<" - - - - - Medicacion - - - - - "<<endl;
        else if (I.first == 6)
            archivo<<" - - - - - - - - - - - - - - - - "<<endl<<endl;
        for(auto const& J : I.second)
            archivo<<J.first<<": "<<J.second<<endl;
    }

    archivo.close(); // Cerrar archivo
}
