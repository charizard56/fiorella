#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize_P(Paciente * array_pacientes, int tam_P) // incrementa la dimension de 1 en 1 del array
{
    Paciente* array_paciente_aux = new Paciente[tam_P + 1];  // icremento de a 1

    for (int i = 0; i < tam_P; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i]; 
    }

    delete[] array_pacientes; // libero memoria 

    array_pacientes = array_paciente_aux;

} // aumenta dimension de pacientes  

void leer_pacientes(string Nombre2, Paciente* array_pacientes, int tam_P)
{
    
    int i = 0;

    string dummy;

    char coma = ',';

    fstream Indata2;

    Indata2.open("IRI_Pacientes.csv", ios::in);  // abro el archivo en modo lectura

    Indata2 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma;

    while (! Indata2.eof()) // reviso que el archivo sea distinto de end of file
    {
     
        resize_P(array_pacientes, tam_P);
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

void resize_C(Consulta* array_consultas, int tam_cons)
{
    Consulta* array_consultas_aux = new Consulta[tam_cons + 1];

    for (int i = 0; i < tam_cons; i++)
    {
        array_consultas_aux[i] = array_consultas[i];
    }

    delete[] array_consultas;
    array_consultas = array_consultas_aux;
} // aumenta dimension de consultas

void resize_O(Obrasoc* array_ObraSocial, int tam_obr)
{
    Obrasoc* array_ObraSocial_aux = new Obrasoc[tam_obr + 1];

    for (int i = 0; i < tam_obr; i++)
    {
        array_ObraSocial_aux[i] = array_ObraSocial[i];
    }

    delete[] array_ObraSocial;
    array_ObraSocial = array_ObraSocial_aux;
} // aumenta dimension de consultas

void leer_consultas(string nombre3, Consulta* array_consultas, int tam_cons)
{
    int i = 0;

    string dummy;
    string aux;

    char coma = ',';

    fstream Indata3;

    Indata3.open("IRI_Consultas.csv", ios::in ); // abro el archivo de consultas en modo lectura 

    while (! Indata3. eof () ) // mientras que el archivo sea distinto del final 
    {
        Indata3 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado
       
        resize_C (array_consultas, tam_cons);

        // hago el resize ya que no se la cantidad de personas en la lista 

        Indata3 >> array_consultas[i].dni_1 >> coma >> array_consultas[i].fecha_solicitado >> coma 
                >> array_consultas[i].fecha_consulta >> array_consultas[i].Asistencia >> coma >> array_consultas[i].matricula >> coma; 

        i++;

    }
    Indata3.close(); // cierro el archivo 
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

void separar_pacientes(Paciente* array_pacientes, Consulta* array_consultas, int tam_P, int tam_cons, Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10)
{

    // le paso las listas de los pacientes y de las consultas 
   // y las listas vacias donde voy separar 

    int n1 = 0; // para falso_Archivado
    int n2 = 0; // para si_fue_menos10 

    Paciente* falso_archivado   =    new Paciente[n1]; // listas donde voy a guardar los parcientes que SI fueron 
    Paciente* si_fue_menos10    =    new Paciente[n2]; // los separo tambien + 10 años  y - 10 años, 

    tam_mas10 = 0;  //Para +10 años
    tam_menos10 = 0;  //Para -10 años 

    string aux; 

  
  for (int i = 0; i < tam_P; i++)

  {   
      for (int j = 0; j < tam_cons; j++)
      {
          if (array_consultas[j].dni_1 == array_pacientes[i].dni)
          {
              
              {   aux = array_consultas[j].fecha_consulta; 
                 
                  float diferencia = fecha(aux); // se le pasa direccion de memoria
                 
                  if ( diferencia < 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                   //Para intentar recuperarlos posteriormente
                  { 
                     if(tam_mas10 == 0) Lista_menos10[tam_mas10] = array_pacientes[i];

                     resize_P(Lista_menos10, tam_mas10);

                     Lista_menos10[tam_mas10] = array_pacientes[i];
                  
                  }  

                  if (diferencia < 10 && array_consultas[j].Asistencia == true)  //Solo guardamos los pacientes que SI asistieron
                                                                                   //Para tenerlos catalogados tambien 
                  {
                      if (n1 == 0) falso_archivado[n1] = array_pacientes[i];

                      resize_P(falso_archivado, n1);

                      falso_archivado[n1] = array_pacientes[i];

                  }


                  if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                                                                                  //Para intentar recuperarlos posteriormente
                  {
                      if (tam_mas10 == 0) Lista_mas10[tam_menos10] = array_pacientes[i];

                      resize_P(Lista_mas10, tam_menos10);

                      Lista_mas10[tam_menos10] = array_pacientes[i]; 

                  } 

                  if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que si asistieron
                                                                                 //Para llevar control, no hacer nada con estos pacientes no es opcion ;) 
                  {
                      if (n2 == 0) si_fue_menos10[tam_menos10] = array_pacientes[i];

                      
                          resize_P(si_fue_menos10, n2);

                          Lista_mas10[tam_menos10] = array_pacientes[i];
                     

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

void internados_o_fallecidos(Paciente* Lista_menos10, int tam_mas10, Paciente* array_nc, int tam_per, Paciente* array_muertos, int tam_fall)

{
    int cont_muertos = 0;
    int cont_nc = 0; 

    for (int i = 0; i < tam_mas10; i++)
    {
        if (Lista_menos10[i].estado == "fallecido")
        {
            resize_P(array_muertos, tam_fall);
            array_muertos[cont_muertos] = Lista_menos10[i];
            cont_muertos++;
        }

        if (Lista_menos10[i].estado == "n/c")
        {
            resize_P(array_nc, tam_per);
            array_nc[cont_nc] = Lista_menos10[i];
            cont_nc++;

        }
                
    }
}

void resize_M(Medico* array_medicos, int tam_med)
{
    Medico * array_medicos_aux = new Medico [tam_med + 1];

    for (int i = 0; i < tam_med; i++)
    {
        array_medicos_aux[i] = array_medicos[i];
    }

    delete[] array_medicos;
    array_medicos = array_medicos_aux;
}

void leer_medicos(Medico* array_medicos, int tam_med)

{
    int i = 0;

    string dummy;
    string aux;

    char coma = ',';

    fstream Indata4;

    Indata4.open("IRI_Medicos.csv", ios::in); // abro el archivo de consultas en modo lectura 

    while (!Indata4.eof()) // mientras que el archivo sea distinto del final 
    {
        Indata4 >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado

        resize_M(array_medicos, tam_med);

        // hago el resize ya que no se la cantidad de docs en la lista 

        Indata4 >> array_medicos[i].matricula >> coma >> array_medicos[i].nombre >> coma
                >> array_medicos[i].apellido >> array_medicos[i].teldoc >> coma >> array_medicos[i].especialidad >> coma
                >> array_medicos[i].actividad;
          
        i++;

    } // ya tengo mi lista de doctores cargada 
    Indata4.close(); // cierro el archivo 
}

void leer_ObrasSociales(Obrasoc* ObraSocial, int tam_obr) {

    
    int i = 0;

    string dummy;

    char coma = ',';

    fstream Indata5;

    Indata5.open("IRI_ObraSocial.csv", ios::in);  // abro el archivo en modo lectura

    while (!Indata5.eof()) // reviso que el archivo sea distinto de end of file
    {
        Indata5 >> dummy >> coma >> dummy >> coma;
        resize_O(ObraSocial, tam_obr);
        // hago el resize ya que no se la cantidad de personas en la lista

        Indata5 >> ObraSocial[i].ID >> coma >> ObraSocial[i].Nombre >> coma;
        // guardo a medida que voy leyendo en mi lista 

        i++; // incremento las iteraciones ! 

    }
    Indata5.close(); // cierro el archivo 

    
}