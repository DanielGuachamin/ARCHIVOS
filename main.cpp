#include <iostream>

//LIBRERIA PARA TRABAJAR CON ARCHIVOS
#include <fstream>

void Ingresar_info();
void Mostrrar_info();
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
        Ingresar_info();
      break;
      }
      case 2:
      {
        Mostrrar_info();
      break;
      }
    }
  } while (opcion != 3);
  cout << "\nGracias por usar nuestro servicio" << endl;
  return 0;
}
int menu()
{
  int op;
  do
  {
    cout << "\nMENU DE OPCIONES" << endl;
    cout << "1. Ingresar un nuevo contacto" << endl;
    cout << "2. Mostrar todos los contactos" << endl;
    cout << "3. Salir" << endl;
    cout << "Eliga una opcion: ";
    cin >> op;
    if ((op < 1) || (op > 3))
    {
      cout << "\n¡Ingrese una opción correcta!" << endl;
    }
  } while ((op < 1) || (op > 3));
  return op;
}
void Ingresar_info()
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
void Mostrrar_info()
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