#pragma once

#include <iostream>
#include <string.h>
#include <ctime>
#include <fstream>

using namespace std;

//Declaramos las estructuras de datos

typedef struct 
{

    string Telefono;
    string celular;
    string Direccion;
    string Mail;
    string id_consulta;

}
Contacto;

typedef struct
{
    string dni_1;
    tm fecha;
    string Medico;
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
    string nombre;
    string apellido;
    string especialidad;

}
Medico;

typedef struct
{
    string Nombre;
    string Apellido;
    string dni;
    string Nacimiento;
    string sexo;
    string os; // obra social
    enum estado { archivado, activo };
    ultima_consulta last_consulta;
} paciente_full; // struct que almacena todos los datos del paciente 




fstream Indata1;
fstream Indata2; 
fstream Indata3; 
fstream Indata4; 
fstream Indata5; 
fstream Indata6; // archivo donde voy a guardar pacientes archivados


void resize(Paciente* lista, int N);
void leer_pacientes(string Indata2, Paciente* array_pacientes, int tam);
float fecha(ultima_consulta * Consulta); // verifica si la fecha es menor o mayor a 10 años 
//void separar_pacientes(Paciente* array_pacientes, )