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
Consulta ;

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
Paciente;               //Estructura para leer los pacientes

typedef struct 
{
    string ID;
    string Nombre;
} 
Obrasoc; 

typedef struct
{
    string matricula;
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
    string medico;  // datos del ultimo medico q atendio 

} 
paciente_full;          // Estructura para guardar todos los datos del paciente

                                    //Declaracion de las funciones\\

//Lectura de archivos:

void leer_pacientes(string nombre, Paciente *array_pacientes, int tam);

void leer_consultas(string nombre3, Consulta *array_consultas, int tam_cons);

void leer_medicos(string nombre, Medico *array_medicos, int tam_med);

void leer_Contactos(string nombre, Contacto* array_contacto, int tam_cont);

//Impresion de archivos:

void Escribir_Archivados(Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10);

void Retornan(Paciente* lista_menos10, int tam_menos10);

//void Escribir_Retornan(Paciente* Lista_mas10, int tam_mas10);

//Clasificaciones por lista de los pacientes:

//Organiza los pacientes en listas segun su ultima consulta (+10años/-10años)
void separar_pacientes(Paciente* array_pacientes, Consulta* array_consultas, int tam, int tam_cons, Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10);

//Organiza los clientes en listas segun si estan internados o fallecieron
void internados_o_fallecidos(Paciente* Lista_menos10, int tam_mas10, Paciente* array_nc, int tam_per, Paciente* array_muertos, int tam_fall);

//Herramientas de apoyo:

tm conversion(string consulta);                               //Convierte una variable de tipo string a tm

float fecha(string fecha);                                   //Retorna en años la diferencia entre 2 fechas

void resize_P(Paciente* lista, int N);                      //Incrementa la dimension de la lista para tipos Paciente
                            
void resize_C(Consulta* array_consultas, int tam_cons);    //Incrementa la dimension de la lista para tipos Consulta

void resize_M(Medico* array_medicos, int tam_med);           //Incrementa la dimension de la lista para tipos Medico

void resize_C(Contacto* array_contactos, int tam_cont);

void resize_PF(paciente_full* array_pacientes, int tam_P);