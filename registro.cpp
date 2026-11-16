#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

string nombres[MAX];
string clasificaciones[MAX];
int cantidades[MAX];
float precios[MAX];
int totalProductos = 0;

void registrarProducto() {
    if (totalProductos >= MAX) {
        cout << "Inventario lleno. No se pueden agregar más productos." << endl;
        return;
    }

    string nombre;
    string clasificacion;
    int cantidad;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    getline(cin >> ws, nombre);
    cout << "Ingrese la clasificación del producto: ";
    getline(cin >> ws, clasificacion);
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    nombres[totalProductos] = nombre;
    clasificaciones[totalProductos] = clasificacion;
    cantidades[totalProductos] = cantidad;
    precios[totalProductos] = precio;

    totalProductos++;
}

int main() {
    registrarProducto();   
    cout << nombres[0] << " - " << cantidades[0] << endl;
    return 0;
}