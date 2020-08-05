#include <iostream>

//LIBRERIA PARA TRABAJAR CON ARCHIVOS
#include <fstream>

void Crear_info();
void Añadir_info();
void Mostrar_info();
int menu();

using namespace std;
int main() {
  int opcion;
  do
  {
    opcion = menu();
    switch (opcion)
    {
      case 1:
      {
        cin.ignore();
        Crear_info();
      break;
      }
      case 2:
      {
        cin.ignore();
        Añadir_info();
      break;
      }
      case 3:
      {
        Mostrar_info();
      break;
    }
  } while (opcion != 4);
  cout << "\nGracias por usar nuestro servicio" << endl;
  return 0;
}

int menu()
{
  int op;
  do
  {
    cout << "\nMENU DE OPCIONES" << endl;
    cout << "1. Crear un registro de contactos" << endl;
    cout << "2. Añadir otro contacto" << endl;
    cout << "3. Mostrar todos los contactos" << endl;
    cout << "4. Salir" << endl;
    cout << "Eliga una opcion: ";
    cin >> op;
    if ((op < 1) || (op > 4))
    {
      cout << "\n¡Ingrese una opción correcta!" << endl;
    }
  }while((op < 1) || (op > 4));
  return op;
}
void Crear_info()
{
  string nombre, apellido;
  int edad;
  char r;
  ofstream archivoPrueba;
  string nombreArchivo;
  cout << "\nIngrese el nombre del archivo: ";
  getline(cin, nombreArchivo);

  archivoPrueba.open(nombreArchivo.c_str(), ios::out);

  do
  {
    cout << "Ingrese el nombre: ";
    getline(cin, nombre, '\n');
    cout << "Ingrese el apellido: ";
    getline(cin, apellido, '\n');
    cout << "Ingresa tu edad: ";
    cin >> edad;
    archivoPrueba << nombre << " " << apellido << " " << edad << '\n';

    cout << "\nDesea agregar otro contacto s/n ";
    cin >> r;
    cin.ignore();

  }while ( r == 's');

  archivoPrueba.close();
}
void Añadir_info()
{
  string nombre, apellido;
  int edad;
  char r;
  ofstream archivoPrueba;
  string nombreArchivo;
  cout << "\nIngrese el nombre del archivo: ";
  getline(cin, nombreArchivo);

  archivoPrueba.open(nombreArchivo.c_str(), ios::app);

  do
  {
    cout << "Ingrese el nombre: ";
    getline(cin, nombre, '\n');
    cout << "Ingrese el apellido: ";
    getline(cin, apellido, '\n');
    cout << "Ingresa tu edad: ";
    cin >> edad;
    archivoPrueba << nombre << " " << apellido << " " << edad << '\n';

    cout << "\nDesea agregar otro contacto s/n ";
    cin >> r;
    cin.ignore();

  }while ( r == 's');

  archivoPrueba.close();
}
void Mostrar_info()
{
  string nombre, apellido;
  int edad;
  ifstream archivoLectura("contactos.txt");
  string texto;
  cout << "\n\tCONTACTOS" << endl;
  while(!archivoLectura.eof())
  {
    archivoLectura >> nombre >> apellido >> edad;
    if(!archivoLectura.eof())
    {
      getline(archivoLectura, texto);
      cout << "\n*************************" << endl;
      cout << "Nombre: " << nombre << endl;
      cout << "Apellido: " << apellido << endl;
      cout << "Edad: " << edad << endl;
    }
  }
  archivoLectura.close();
}
}