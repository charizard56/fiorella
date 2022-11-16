#pragma once

#include <iostream>
#include <string.h>
#include <ctime>
#include <fstream>

using namespace std;

//Declaramos las estructuras de datos

typedef struct 
{

    string dni; 
    string Telefono;
    string celular;
    string Direccion;
    string Mail;
}
Contacto;

typedef struct
{
    string dni_1;
    string fecha_consulta;
    string fecha_solicitado; 
    string matricula;
    bool Asistencia; 
}
ultima_consulta ;

typedef struct
{
    string Nombre;
    string Apellido; 
    string dni;
    string Nacimiento;
    string sexo; 
    string os; // obra social
    string  estado ; // internado, fallecido, nc
}
Paciente; 

typedef struct 
{
    enum os { Medicus, OSDE, IOSFA, italiano, Aleman, Espanyol };
} 
Obrasoc; 

typedef struct
{
    string  id;
    string teldoc; 
    string nombre;
    string apellido;
    string especialidad;
    bool actividad; 

}
Medico;

typedef struct
{
    string Nombre;
    string Apellido;
    string dni;
    string os; // obra social
    bool retorna; // si el paciente retorna o no. 
    Medico medico;  // datos del ultimo medico q atendio 

} paciente_full; // struct que almacena todos los datos del paciente 

fstream Indata1;
fstream Indata2; 
fstream Indata3; 
fstream Indata4; 
fstream Indata5; 
fstream Indata6; // archivo donde voy a guardar pacientes archivados


void resize(Paciente* lista, int N);

void leer_pacientes(string Indata2, Paciente* array_pacientes, int tam);

tm conversion(string consulta); 

float fecha(string fecha); // verifica si la fecha es menor o mayor a 10 años 
                            
void resize2(ultima_consulta* array_consultas, int tam5); 

void leer_consultas(string nombre3, ultima_consulta* array_consultas, int tam5); 

void separar_pacientes(Paciente* array_pacientes, ultima_consulta* array_consultas, int tam, int tam5, Paciente* Lista_mas10, int tam2, Paciente* Lista_menos10, int tam3); 

void internados_o_fallecidos(Paciente* Lista_menos10, int tam2, Paciente* array_nc, int tam7, Paciente* array_muertos, int tam8);  // clasifica segun vivos o muertos a partir de menos de 10 años de la utlima consulta

//void crear_archivos ( string archivo, Paciente)