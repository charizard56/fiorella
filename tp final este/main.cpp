#define _CRT_SECURE_NO_WARNINGS 
#include "Funciones.h"

using namespace std;

int main() {


    Indata1.open("IRI_Consultas.csv");
    Indata2.open("IRI_Pacientes.csv");
    Indata3.open("IRI_Contatos.csv");
    Indata4.open("IRI_Medicos.csv");
    Indata5.open("IRI_ObraSocial.csv");

    int tam  = 0;
    int tam2 = 0;
    int tam3 = 0;
    int tam4 = 0;
    int tam5 = 0; 
    int tam6 = 0; 


    Paciente* array_pacientes = new Paciente[tam];

    leer_pacientes("IRI_Pacientes.csv", array_pacientes, tam); // aca tengo el array_pacientes cargado !!

    Paciente* lista_mas10 = new Paciente[tam2]; // lista que guarda los pacientes cuya ultima consulta fue hace + de 10 años

    ultima_consulta* array_consultas = new ultima_consulta[tam5]; 

    paciente_full* lista_paciente_full = new paciente_full[tam6]; // lista que guarda TODOS LOS DATOS DEL PACIENTE 

    getchar;

    return 0;
}