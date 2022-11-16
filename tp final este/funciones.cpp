#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize(Paciente * array_pacientes, int tam) // incrementa la dimension de 1 en 1 del array
{
    Paciente* array_paciente_aux = new Paciente[tam + 1];  // icremento de a 1

    for (int i = 0; i < tam; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i]; 
    }

    delete[] array_pacientes; // libero memoria 

    array_pacientes = array_paciente_aux;

} // aumenta dimension de pacientes  

void leer_pacientes(string Nombre2, Paciente* array_pacientes, int tam)
{
    
    int i = 0;

    string dummy;

    char coma = ',';

    fstream Indata2;

    Indata2.open("IRI_Pacientes.csv", ios::in);  // abro el archivo en modo lectura

    while (! Indata2.eof()) // reviso que el archivo sea distinto de end of file
    {
        Indata2 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; 
        resize(array_pacientes, tam);
        // hago el resize ya que no se la cantidad de personas en la lista

        Indata2 >> array_pacientes[i].dni    >> coma >> array_pacientes[i].Nombre >> coma
            >> array_pacientes[i].Apellido   >> array_pacientes[i].sexo >> coma >>
               array_pacientes[i].Nacimiento >> coma >> array_pacientes[i].os >> coma
            >> array_pacientes[i].estado     >> coma; 
        // guardo a medida que voy leyendo en mi lista 

        i++; // incremento las iteraciones ! 

    }
    Indata2.close(); // cierro el archivo 
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

    Indata3.open("IRI_Consultas.csv", ios::in ); // abro el archivo de consultas en modo lectura 

    while (! Indata2. eof () ) // mientras que el archivo sea distinto del final 
    {
        Indata2 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado
       
        resize2 (array_consultas, tam5);

        // hago el resize ya que no se la cantidad de personas en la lista 

        Indata2 >> array_consultas[i].dni_1 >> coma >> array_consultas[i].fecha_solicitado >> coma 
                >> array_consultas[i].fecha_consulta >> array_consultas[i].Asistencia >> coma >> array_consultas[i].matricula >> coma; 

        i++;

    }
    Indata2.close(); // cierro el archivo 
}

tm conversion(string consulta)
{
    fstream Fecha_str(consulta);

    int Dia = 0;
    int Mes = 0;
    int Año = 0;

    string separador = "/";

    Fecha_str >> Dia >> separador >> Mes >> separador >> Año;

    tm Fecha_tm;

    Fecha_tm.tm_mday = Dia;
    Fecha_tm.tm_mon = Mes;
    Fecha_tm.tm_year = Año;

    return Fecha_tm;

}

float fecha(string fecha)
{
   tm Fecha = conversion(fecha); // primero convierto de string a tm 
   time_t auxiliar_fecha = time(0); 

    tm* hoy = localtime(&auxiliar_fecha); 

    tm fecha_hoy;

    fecha_hoy.tm_mday = hoy ->  tm_mday;
    fecha_hoy.tm_mon  = hoy ->  tm_mon;
    fecha_hoy.tm_year = hoy ->  tm_year; 

    int dif = 0; 

    time_t aux_fin = mktime(&fecha_hoy); 
    time_t aux_inicio = mktime(&Fecha);
    dif = difftime(aux_fin, aux_inicio) / (3153600); 
  
    return dif; // retorna la diferencia ( en anios) 
   
}

void separar_pacientes(Paciente* array_pacientes, ultima_consulta* array_consultas, int tam, int tam5, Paciente* Lista_mas10, int tam2, Paciente* Lista_menos10, int tam3)
{

    // le paso las listas de los pacientes y de las consultas 
   // y las listas vacias donde voy separar 

    int n1 = 0; // para falso_Archivado
    int n2 = 0; // para si_fue_menos10 

    Paciente* falso_archivado   =    new Paciente[n1]; // listas donde voy a guardar los parcientes que SI fueron 
    Paciente* si_fue_menos10    =    new Paciente[n2]; // los separo tambien + 10 años  y - 10 años, 

    tam2 = 0;  //Para +10 años
    tam3 = 0;  //Para -10 años 

    string aux; 

  
  for (int i = 0; i < tam; i++)

  {   
      for (int j = 0; j < tam5; j++)
      {
          if (array_consultas[j].dni_1 == array_pacientes[i].dni)
          {
              
              {   aux = array_consultas[j].fecha_consulta; 
                 
                  float diferencia = fecha(aux); // se le pasa direccion de memoria
                 
                  if ( diferencia < 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                   //Para intentar recuperarlos posteriormente
                  { 
                     if(tam2 == 0) Lista_menos10[tam2] = array_pacientes[i];

                     resize(Lista_menos10, tam2);

                     Lista_menos10[tam2] = array_pacientes[i];
                  
                  }  

                  if (diferencia < 10 && array_consultas[j].Asistencia == true)  //Solo guardamos los pacientes que SI asistieron
                                                                                   //Para tenerlos catalogados tambien 
                  {
                      if (n1 == 0) falso_archivado[n1] = array_pacientes[i];

                      resize(falso_archivado, n1);

                      falso_archivado[n1] = array_pacientes[i];

                  }


                  if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                  //Para intentar recuperarlos posteriormente
                  {
                      if (tam2 == 0) Lista_mas10[tam3] = array_pacientes[i];

                      resize(Lista_mas10, tam3);

                      Lista_mas10[tam3] = array_pacientes[i]; 

                  } 

                  if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que si asistieron
                                                                                 //Para llevar control, no hacer nada con estos pacientes no es opcion ;) 
                  {
                      if (n2 == 0) si_fue_menos10[tam3] = array_pacientes[i];

                      
                          resize(si_fue_menos10, n2);

                          Lista_mas10[tam3] = array_pacientes[i];
                     

                  }
                   
              }
          }
      }
        
  }

  cout << "----- LISTA DE PACIENTES INACTIVOS -----" << endl; 
  cout << endl; 
  cout << endl; 

  for (int i = 0; i < n1; i++)
  {
      cout << "Paciente : " << falso_archivado[i].Apellido << "  DNI: " << falso_archivado[i].dni << endl; 
      cout << endl; 
  }

  cout << "----- LISTA DE PACIENTES RESPONSABLES QUE ASISTEN A SUS CONSULTAS -----" << endl; 
  cout << endl; 
  cout << endl; 

  for (int i = 0; i < n2; i++)
  {
      cout << "Paciente :  " << si_fue_menos10[i].Apellido << "  DNI : " << si_fue_menos10[i].dni << endl; 
      cout << endl; 
  }

  delete[] si_fue_menos10; 
  delete[] falso_archivado; 
}

void internados_o_fallecidos(Paciente* Lista_menos10, int tam2, Paciente* array_nc, int tam7, Paciente* array_muertos, int tam8)

{
    int cont_muertos = 0;
    int cont_nc = 0; 

    for (int i = 0; i < tam2; i++)
    {
        if (Lista_menos10[i].estado == "fallecido")
        {
            array_muertos[cont_muertos] = Lista_menos10[i];
            cont_muertos++;
        }

        if (Lista_menos10[i].estado == "n/c")
        {
            array_nc[cont_nc] = Lista_menos10[i];
            cont_nc++;

        }
                
    }
}