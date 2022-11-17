#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"


using namespace std;

int main() {

    fstream Indata1;
    fstream Indata2;
    fstream Indata3;
    fstream Indata4;
    fstream Indata5;
    fstream Indata6;


    Indata1.open(base_path, "IRI_Consultas.csv", ios::out);
    Indata2.open("IRI_Pacientes.csv", ios :: out);
    Indata3.open("IRI_Contatos.csv", ios :: out);
    Indata4.open("IRI_Medicos.csv", ios :: out);
    Indata5.open("IRI_ObraSocial.csv", ios :: out);
    Indata6.open("IRI_archivo_pc.csv", ios::out); 

   
    int tam = 0;
    int tam2 = 0;
    int tam3 = 0;
    int tam4 = 0;
    int tam5 = 0; 
    int tam6 = 0; 
    int tam7 = 0; 
    int tam8 = 0; 
    int tam9 = 0; 


    Paciente  * array_pacientes = new Paciente[tam];

    leer_pacientes("IRI_Pacientes.csv", array_pacientes, tam); // aca tengo el array_pacientes cargado !!

    Paciente  * lista_mas10 = new Paciente[tam2]; // lista que guarda los pacientes cuya ultima consulta fue hace + de 10 años

    ultima_consulta * array_consultas = new ultima_consulta[tam5]; 

    Paciente* lista_menos10 = new Paciente[tam3]; 

    //paciente_full* lista_paciente_full = new paciente_full[tam6]; // lista que guarda TODOS LOS DATOS DEL PACIENTE 

    Paciente * array_vivos   = new Paciente[tam7]; 

    Paciente * array_muertos = new Paciente[tam8]; 

    Medico   * array_medicos = new Medico[tam9]; 

    separar_pacientes(array_pacientes, array_consultas, tam, tam5, lista_mas10, tam2, lista_menos10, tam3);


    delete[] array_pacientes; 
    delete[] lista_mas10;
    delete[] lista_menos10; 
    delete[] array_consultas;
    delete[] array_muertos; 
    delete[] array_vivos; 
    

    getchar();

    return 0;
 

    Indata1.close(); 
    Indata2.close();
    Indata3.close(); 
    Indata4.close();
    Indata5.close();
    Indata6.close();

    return 0; 
}