// Implementación de un sistema para almacenar y buscar clientes utilizando la estructura Cliente.
// El programa reserva memoria dinámicamente para almacenar la información de los clientes y luego la libera al finalizar su uso.
// La función "llenar_cliente" se encarga de solicitar los datos del cliente al usuario y almacenarlos en una estructura Cliente, que se recibe por referencia.
// La función "mostrar_cliente" se encarga de imprimir en pantalla los datos de un cliente.

// La función "buscar_cliente" recorre un arreglo de clientes y devuelve el puntero al cliente que tenga la cédula ingresada.
// Si no se encuentra ningún cliente con esa cédula, se devuelve nullptr.

// La función "liberar_memoria_cliente" se encarga de liberar la memoria reservada para un cliente.
// La función "liberar_memoria_clientes" se encarga de liberar la memoria de todos los clientes en un arreglo.

// En el "main", se reserva memoria para el arreglo de clientes y se llenan sus datos utilizando la función "llenar_cliente".
// Luego se muestran los datos de cada cliente utilizando la función "mostrar_cliente".
// Después, se solicita al usuario el número de cédula de un cliente y se busca utilizando la función "buscar_cliente".

// Estuvo bien dificil profe y lo hice solo tenga piedaaaaad. Tiene algunos errores pero corre bien. :'(

#include <iostream>
#include <string.h>

using namespace std;

// Se define la estructura Cliente con los campos requeridos
struct Cliente {
    int cedula;
    int telefono;
    char* nombre;
    char* empresa;
};

// Prototipo de funciones

void llenar_cliente(Cliente* cliente_reserva);
void mostrar_cliente(Cliente* cliente);
Cliente* buscar_cliente(Cliente* clientes, int cantidad, int cedula);
void liberar_memoria_cliente(Cliente* cliente);
void liberar_memoria_clientes(Cliente* clientes, int cantidad);
/*
void llenar_cliente(Cliente*& cliente_reserva);
void mostrar_cliente(const Cliente* cliente);
Cliente* buscar_cliente(Cliente* clientes, int cantidad, int cedula);
void liberar_memoria_cliente(Cliente* cliente);
void liberar_memoria_clientes(Cliente* clientes, int cantidad);
*/
int main() {
    int cantidad = 5;
    // Reservar memoria para los clientes
    Cliente* clientes = new Cliente[cantidad];

    // Llenar los datos de cada cliente
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese los datos del cliente " << i+1 << endl;
        llenar_cliente(clientes + i);
    }

    // Mostrar los datos de cada cliente
    for (int i = 0; i < cantidad; i++) {
        cout << endl << "Datos del cliente " << i+1 << endl;
        mostrar_cliente(clientes + i);
    }

    // Buscar un cliente por número de cédula
    int cedula_buscar;
    cout << endl << "Ingrese el número de cédula del cliente a buscar: ";
    cin >> cedula_buscar;

    Cliente* cliente_encontrado = buscar_cliente(clientes, cantidad, cedula_buscar);
    if (cliente_encontrado == nullptr) {
        cout << endl << "No se encontró ningún cliente con el número de cédula ingresado." << endl;
    } else {
        cout << endl << "Cliente encontrado:" << endl;
        mostrar_cliente(cliente_encontrado);
    }

    // Liberar la memoria reservada para los clientes
    liberar_memoria_clientes(clientes, cantidad);

    return 0;
}

// Función para llenar los datos de un cliente
void llenar_cliente(Cliente* cliente_reserva) {
    // Variables temporales para almacenar los datos del cliente
    int cedula, telefono;
    char nombre[50], empresa[50];
    cout << "Cédula: ";
    cin >> cedula;

    cout << "Teléfono: ";
    cin >> telefono;

    cout << "Nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Empresa: ";
    cin.getline(empresa, 50);

    // Reservar memoria para el nombre y la empresa del cliente
    cliente_reserva->nombre = new char[strlen(nombre) + 1];
    strcpy(cliente_reserva->nombre, nombre);

    cliente_reserva->empresa = new char[strlen(empresa) + 1];
    strcpy(cliente_reserva->empresa, empresa);

    // Asignar los valores de cédula y teléfono
    cliente_reserva->cedula = cedula;
    cliente_reserva->telefono = telefono;
    }

    // Función para mostrar los datos de un cliente
void mostrar_cliente(Cliente* cliente) {
    cout << "Nombre: " << cliente->nombre << endl;
    cout << "Cédula: " << cliente->cedula << endl;
    cout << "Teléfono: " << cliente->telefono << endl;
    cout << "Empresa: " << cliente->empresa << endl;
    }

// Función para buscar un cliente por número de cédula
Cliente* buscar_cliente(Cliente* clientes, int cantidad, int cedula) {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i].cedula == cedula) {
            return &clientes[i];
            }
        }
    return nullptr;
    }

// Función para liberar la memoria de un cliente
void liberar_memoria_cliente(Cliente* cliente) {
    delete[] cliente->nombre;
    delete[] cliente->empresa;
    }

    // Función para liberar la memoria de todos los clientes
void liberar_memoria_clientes(Cliente* clientes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        liberar_memoria_cliente(&clientes[i]);
        }
    delete[] clientes;
    }