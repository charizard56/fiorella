#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"


using namespace std;

int main() {

    //Declaramos todas las variables que utilizaremos para almacenar las dimensiones de cada lista.

    int tam_P  = 0;
    int tam_mas10 = 0;
    int tam_menos10 = 0;
    int tam_cons = 0; 
    int tam_per = 0; 
    int tam_fall = 0; 
    int tam_med = 0; 
    int tam_obr = 0;

                                         //Declaracion de Listas en memoria\\

    /*
    Listas de tipos Paciente :
    Declaramos la lista que usamos para leer a los parcientes de los archivos y las listas para clasificarlos
    segun su ultima consulta(+10/-10 y si asistio).
    Tambien declaramos listas para clasificarlos segun su estado.
    */

    Paciente  * array_pacientes = new Paciente[tam_P];

    Paciente  * lista_mas10 = new Paciente[tam_mas10]; 

    Paciente* lista_menos10 = new Paciente[tam_menos10]; 

    Paciente* array_perdidos = new Paciente[tam_per];

    Paciente* array_fallecidos = new Paciente[tam_fall];

    /*
    Listas de tipo consulta:
    Declaramos en memoria la lista que utilizamos para leer los datos de las consultas de los pacientes
    */

    Consulta* array_consultas = new Consulta[tam_cons];

   /*
   Listas de tipo Medico:
   Declaramos en memoria la lista que utilizamos para leer los datos de los medicos
   */

    Medico   * array_medicos = new Medico[tam_med]; 

    /*
   Listas de tipo Obra Social:
   Declaramos en memoria la lista que utilizamos para leer los datos de las obras sociales
   */

    Obrasoc* array_ObraSocial = new Obrasoc[tam_obr];

                                                  //Comienzo de acciones\\

    leer_pacientes("IRI_Pacientes.csv", array_pacientes, tam_P);                    // Leemos la lista de pacientes

    leer_consultas("IRI_Consultas.csv", array_consultas, tam_cons);  //Leemos todas las consultas

    leer_medicos(array_medicos, tam_med);                               //Leemos la informacion de los medicos

    leer_ObrasSociales(array_ObraSocial, tam_obr);


    //Liberamos toda la memoria que utilizamos.
    
    delete[] array_pacientes; 
    delete[] lista_mas10;
    delete[] lista_menos10; 
    delete[] array_consultas;
    delete[] array_fallecidos; 
    delete[] array_perdidos; 

    //Fin del codigo
    
    getchar();

    return 0;
 

    Indata1.close(); 
    Indata2.close();
    Indata3.close(); 
    Indata4.close();
    Indata5.close();
    Outdata1.close();
    Outdata2.close();

    return 0; 
}