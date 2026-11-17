#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
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

// ---------- Funciones auxiliares ----------

// Convierte un texto a minusculas (para comparar nombres sin importar mayusculas)
string aMinusculas(string texto)
{
    for (int i = 0; i < (int)texto.length(); i++)
    {
        texto[i] = tolower((unsigned char)texto[i]);
    }
    return texto;
}

// Busca un producto por nombre. Devuelve su posicion o -1 si no existe
int buscarProducto(string nombre)
{
    string buscado = aMinusculas(nombre);
    for (int i = 0; i < totalProductos; i++)
    {
        if (aMinusculas(nombres[i]) == buscado)
        {
            return i;
        }
    }
    return -1;
}

// Pide un texto que no puede quedar vacio
string leerTexto(string mensaje)
{
    string texto;
    do
    {
        cout << mensaje;
        getline(cin >> ws, texto);
        if (texto.empty())
        {
            cout << "El texto no puede estar vacio." << endl;
        }
    } while (texto.empty());
    return texto;
}

// Pide un entero >= minimo. Repite hasta que el dato sea valido
int leerEntero(string mensaje, int minimo)
{
    int valor;
    while (true)
    {
        cout << mensaje;
        if (cin >> valor && valor >= minimo)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "Dato invalido. Ingrese un numero entero mayor o igual a " << minimo << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Pide un decimal > 0. Repite hasta que el dato sea valido
float leerPrecio(string mensaje)
{
    float valor;
    while (true)
    {
        cout << mensaje;
        if (cin >> valor && valor > 0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "Dato invalido. Ingrese un precio mayor que 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ---------- Funciones principales ----------

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
        cout << "Inventario lleno. No se pueden agregar mas productos." << endl;
        return;
    }

    string nombre = leerTexto("Ingrese el nombre del producto: ");

    if (buscarProducto(nombre) != -1)
    {
        cout << "Ese producto ya existe en el inventario." << endl;
        return;
    }

    string clasificacion = leerTexto("Ingrese la clasificacion del producto: ");
    int cantidad = leerEntero("Ingrese la cantidad del producto: ", 0);
    float precio = leerPrecio("Ingrese el precio del producto: ");

    nombres[totalProductos] = nombre;
    clasificaciones[totalProductos] = clasificacion;
    cantidades[totalProductos] = cantidad;
    precios[totalProductos] = precio;

    totalProductos++;
    cout << "Producto registrado correctamente." << endl;
}

void listarInventario()
{
    if (totalProductos == 0)
    {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    cout << left << setw(5) << "No."
         << setw(14) << "Nombre"
         << setw(16) << "Clasificacion"
         << setw(10) << "Cantidad"
         << setw(10) << "Precio"
         << "Estado" << endl;

    cout << string(62, '-') << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < totalProductos; i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(14) << nombres[i]
             << setw(16) << clasificaciones[i]
             << setw(10) << cantidades[i]
             << setw(10) << precios[i];

        if (cantidades[i] == 0)
        {
            cout << "AGOTADO";
        }
        else if (cantidades[i] <= 5)
        {
            cout << "Stock bajo";
        }
        else
        {
            cout << "Disponible";
        }
        cout << endl;
    }
}

// Menu temporal para probar tus funciones (luego se integra con el menu de Nathali)
int main()
{
    cargarInventarioInicial();

    int opcion;
    do
    {
        cout << "\n===== TIENDA JNB (prueba) =====" << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Listar inventario" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Opcion: ", 0);

        switch (opcion)
        {
        case 1:
            registrarProducto();
            break;
        case 2:
            listarInventario();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}