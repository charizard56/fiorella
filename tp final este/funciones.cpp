#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize(Paciente * array_pacientes, int tam) // incrementa la dimension de 1 en 1 del array
{
    Paciente* array_paciente_aux = new Paciente[tam + 1];

    for (int i = 0; i < tam; i++)
    {
        array_paciente_aux[i] = array_pacientes[i]; 
    }

    delete[] array_pacientes;
    array_pacientes = array_paciente_aux;
} // aumenta dimension de pacientes 

void leer_pacientes(string Nombre2, Paciente* array_pacientes, int tam)
{
    
    int i = 0;
    string dummy;
    char coma = ',';
    fstream Indata2;
    Indata2.open("IRI_Pacientes.csv", ios::in); 

    while (! Indata2.eof())
    {
        Indata2 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; 
        resize(array_pacientes, tam);
        // hago el resize ya que no se la cantidad de personas en la lista 
        Indata2 >> array_pacientes[i].dni >> coma >> array_pacientes[i].Nombre >> coma
                >> array_pacientes[i].Apellido >> array_pacientes[i].sexo >>coma >>
                   array_pacientes[i].Nacimiento >> coma >> array_pacientes[i].os >> coma; 

        i++;

    }
    Indata2.close(); 
}

void resize2(ultima_consulta* array_consultas, int tam5)
{
    ultima_consulta* array_consultas_aux = new ultima_consulta[tam5 + 1];

    for (int i = 0; i < tam5; i++)
    {
        array_consultas_aux[i] = array_consultas[i];
    }

    delete[] array_consultas;
    array_consultas = array_consultas_aux;
} // aumenta dimension de consultas

void leer_consultas(string nombre3, ultima_consulta* array_consultas, int tam5)
{
    int i = 0;

    string dummy;
    string aux;

    char coma = ',';

    fstream Indata3;

    Indata3.open("IRI_Consultas.csv", ios::in );

    while (! Indata2. eof () ) // mientras que el archivo sea distinto del final 
    {
        Indata2 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado
       
        resize2 (array_consultas, tam5);

        // hago el resize ya que no se la cantidad de personas en la lista 

        Indata2 >> array_consultas[i].dni_1 >> coma >> aux >> coma
            >> array_consultas[i].Asistencia >> array_consultas[i].Medico >> coma;

        //array_consultas[i].fecha = aux;

        i++;

    }
    Indata2.close(); // cierro el archivo 
}

float fecha(ultima_consulta * Consulta)
{
    time_t auxiliar_fecha = time(0); 

    tm* hoy = localtime(&auxiliar_fecha); 

    tm fecha_hoy;

    fecha_hoy.tm_mday = hoy ->  tm_mday;
    fecha_hoy.tm_mon  = hoy ->  tm_mon;
    fecha_hoy.tm_year = hoy ->  tm_year; 

    int dif = 0; 

    time_t aux_fin = mktime(&fecha_hoy); 
    time_t aux_inicio = mktime(&Consulta-> fecha);
    dif = difftime(aux_fin, aux_inicio) / (3153600); 
  
    return dif; // retorna la diferencia ( en anios) 
   
}

void separar_pacientes(Paciente* array_pacientes, ultima_consulta* array_consultas, int tam, int tam5, Paciente* Lista_mas10, int tam2, Paciente* Lista_menos10, int tam3)
{
   
     // le paso las listas de los pacientes y de las consultas 
    // y las listas vacias donde voy separar

    tam2 = 0;  //Para +10 años
    tam3 = 0;  //Para -10 años

  
  for (int i = 0; i < tam; i++)

  {   
      for (int j = 0; j < tam5; j++)
      {
          if (array_consultas[j].dni_1 == array_pacientes[i].dni)
          {
              
              {  
                 
                  float diferencia = fecha(&array_consultas[j]);
                  if ( diferencia < 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                   //Para intentar recuperarlos posteriormente
                  { 
                     if(tam2 == 0) Lista_menos10[tam2] = array_pacientes[i];

                     resize(Lista_menos10, tam2);

                     Lista_menos10[tam2] = array_pacientes[i];
                  
                  }

                  if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                  //Para intentar recuperarlos posteriormente
                  {
                      if (tam2 == 0) Lista_mas10[tam3] = array_pacientes[i];

                      resize(Lista_mas10, tam3);

                      Lista_mas10[tam3] = array_pacientes[i];

                  }

              }
          }
      }
        
  }

}