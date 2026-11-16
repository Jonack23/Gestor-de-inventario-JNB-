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

// nombre | clasificacion | cantidad | precio
// coca cola | bebida | 10 | 1.5
// pepsi | bebida | 5 | 1.2
// agua | bebida | 20 | 0.8
// lays | snack | 8 | 1.3
// m&m's | snack | 6 | 1.2
// gomitas | snack | 10 | 0.5
// detergente | limpieza | 3 | 2.5
// lejia | limpieza | 0 | 1.8
// jabon | limpieza | 5 | 1.0
// leche | lacteos | 10 | 1.2
// queso | lacteos | 5 | 2.0
// yogurt | lacteos | 8 | 1.5

void cargarInventarioInicial()
{
    nombres[0] = "coca cola";
    clasificaciones[0] = "bebida";
    cantidades[0] = 10;
    precios[0] = 1.5;

    nombres[1] = "pepsi";
    clasificaciones[1] = "bebida";
    cantidades[1] = 5;
    precios[1] = 1.2;

    nombres[2] = "agua";
    clasificaciones[2] = "bebida";
    cantidades[2] = 20;
    precios[2] = 0.8;

    nombres[3] = "lays";
    clasificaciones[3] = "snack";
    cantidades[3] = 8;
    precios[3] = 1.3;

    nombres[4] = "m&m's";
    clasificaciones[4] = "snack";
    cantidades[4] = 6;
    precios[4] = 1.2;

    nombres[5] = "gomitas";
    clasificaciones[5] = "snack";
    cantidades[5] = 10;
    precios[5] = 0.5;

    nombres[6] = "detergente";
    clasificaciones[6] = "limpieza";
    cantidades[6] = 3;
    precios[6] = 2.5;

    nombres[7] = "lejia";
    clasificaciones[7] = "limpieza";
    cantidades[7] = 0;
    precios[7] = 1.8;

    nombres[8] = "jabon";
    clasificaciones[8] = "limpieza";
    cantidades[8] = 5;
    precios[8] = 1.0;

    nombres[9] = "leche";
    clasificaciones[9] = "lacteos";
    cantidades[9] = 10;
    precios[9] = 1.2;

    nombres[10] = "queso";
    clasificaciones[10] = "lacteos";
    cantidades[10] = 5;
    precios[10] = 2.0;

    nombres[11] = "yogurt";
    clasificaciones[11] = "lacteos";
    cantidades[11] = 8;
    precios[11] = 1.5;

    totalProductos = 12;
}

void registrarProducto()
{
    if (totalProductos >= MAX)
    {
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
void listarInventario()
{
    if (totalProductos == 0)
    {
        cout << "El inventario está vacío." << endl;
        return;
    }
    for (int i = 0; i < totalProductos; i++)
    {
        cout << nombres[i] << " | " << clasificaciones[i] << " | "
             << cantidades[i] << " | " << precios[i] << endl;
    }
}

int main()
{
    cargarInventarioInicial();
    listarInventario();
    return 0;
}
