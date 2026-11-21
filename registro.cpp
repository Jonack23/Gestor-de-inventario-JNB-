#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

const int MAX = 100;
const int STOCK_CRITICO = 5; // menos de este valor = stock critico (compartido con reportes)
const int MAX_CANTIDAD = 1000;
const float MAX_PRECIO = 500;

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

// Pide un entero entre minimo y maximo. Repite con do-while hasta que el dato sea valido
int leerEntero(string mensaje, int minimo, int maximo)
{
    int valor;
    bool valido;
    do
    {
        cout << mensaje;
        cin >> valor;
        valido = !cin.fail() && valor >= minimo && valor <= maximo;
        if (!valido)
        {
            cout << "Dato invalido. Ingrese un numero entero entre " << minimo
                 << " y " << maximo << "." << endl;
            cin.clear();            // quita el error de cin (por si escribieron letras)
            cin.ignore(1000, '\n'); // descarta lo que quedo escrito en la linea
        }
    } while (!valido);
    cin.ignore(1000, '\n');
    return valor;
}

// Pide un precio entre 0 (sin incluir) y MAX_PRECIO. Repite con do-while hasta que sea valido
float leerPrecio(string mensaje)
{
    float valor;
    bool valido;
    do
    {
        cout << mensaje;
        cin >> valor;
        valido = !cin.fail() && valor > 0 && valor <= MAX_PRECIO;
        if (!valido)
        {
            cout << "Dato invalido. Ingrese un precio mayor que 0 y menor o igual a "
                 << MAX_PRECIO << "." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (!valido);
    cin.ignore(1000, '\n');
    return valor;
}

// ---------- Funciones principales ----------

void cargarInventarioInicial()
{
    string n[] = {"coca cola", "pepsi", "agua", "lays", "m&m's", "gomitas",
                  "detergente", "lejia", "jabon", "leche", "queso", "yogurt"};
    string c[] = {"bebida", "bebida", "bebida", "snack", "snack", "snack",
                  "limpieza", "limpieza", "limpieza", "lacteos", "lacteos", "lacteos"};
    int q[] = {10, 5, 20, 8, 6, 10, 3, 0, 5, 10, 5, 8};
    float p[] = {1.5, 1.2, 0.8, 1.3, 1.2, 0.5, 2.5, 1.8, 1.0, 1.2, 2.0, 1.5};

    totalProductos = 12;
    for (int i = 0; i < totalProductos; i++)
    {
        nombres[i] = n[i];
        clasificaciones[i] = c[i];
        cantidades[i] = q[i];
        precios[i] = p[i];
    }
}

void registrarProducto()
{
    string nombre;
    string clasificacion;

    cout << "Ingrese el nombre del producto: ";
    getline(cin >> ws, nombre);

    // Si ya existe, se suma al stock en lugar de rechazarlo
    int pos = buscarProducto(nombre);
    if (pos != -1)
    {
        int maximoExtra = MAX_CANTIDAD - cantidades[pos];
        if (maximoExtra < 1)
        {
            cout << "Ese producto ya tiene el stock maximo (" << MAX_CANTIDAD << ")." << endl;
            return;
        }
        int extra = leerEntero("El producto ya existe. Cantidad a sumar: ", 1, maximoExtra);
        cantidades[pos] += extra;
        cout << "Stock actualizado. " << nombres[pos] << " ahora tiene "
             << cantidades[pos] << " unidades." << endl;
        return;
    }

    // Producto nuevo: se verifica espacio antes de pedir mas datos
    if (totalProductos >= MAX)
    {
        cout << "Inventario lleno. No se pueden agregar mas productos." << endl;
        return;
    }

    cout << "Ingrese la clasificacion del producto: ";
    getline(cin >> ws, clasificacion);
    int cantidad = leerEntero("Ingrese la cantidad del producto: ", 0, MAX_CANTIDAD);
    float precio = leerPrecio("Ingrese el precio del producto: ");

    nombres[totalProductos] = nombre;
    clasificaciones[totalProductos] = clasificacion;
    cantidades[totalProductos] = cantidad;
    precios[totalProductos] = precio;

    totalProductos++;
    cout << "Producto registrado correctamente." << endl;
}

// Devuelve el estado del stock segun la cantidad
string estadoStock(int cantidad)
{
    if (cantidad == 0)
    {
        return "AGOTADO";
    }
    if (cantidad < STOCK_CRITICO)
    {
        return "Stock bajo";
    }
    return "Disponible";
}

void imprimirEncabezado()
{
    cout << left << setw(5) << "No."
         << setw(14) << "Nombre"
         << setw(16) << "Clasificacion"
         << setw(10) << "Cantidad"
         << setw(10) << "Precio"
         << "Estado" << endl;
    cout << string(62, '-') << endl;
}

void imprimirFila(int i)
{
    cout << fixed << setprecision(2);
    cout << left << setw(5) << (i + 1)
         << setw(14) << nombres[i]
         << setw(16) << clasificaciones[i]
         << setw(10) << cantidades[i]
         << setw(10) << precios[i]
         << estadoStock(cantidades[i]) << endl;
}

void listarInventario()
{
    if (totalProductos == 0)
    {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    imprimirEncabezado();
    for (int i = 0; i < totalProductos; i++)
    {
        imprimirFila(i);
    }
}

void buscarPorNombre()
{
    string nombre;
    cout << "Ingrese el nombre del producto a buscar: ";
    getline(cin >> ws, nombre);

    int pos = buscarProducto(nombre);
    if (pos == -1)
    {
        cout << "Producto no encontrado." << endl;
        return;
    }

    imprimirEncabezado();
    imprimirFila(pos);
}

void filtrarPorClasificacion()
{
    string clasificacion;
    cout << "Ingrese la clasificacion a mostrar: ";
    getline(cin >> ws, clasificacion);
    clasificacion = aMinusculas(clasificacion);

    int encontrados = 0;
    for (int i = 0; i < totalProductos; i++)
    {
        if (aMinusculas(clasificaciones[i]) == clasificacion)
        {
            if (encontrados == 0)
            {
                imprimirEncabezado();
            }
            imprimirFila(i);
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        cout << "No hay productos en esa clasificacion." << endl;
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
        cout << "3. Buscar producto por nombre" << endl;
        cout << "4. Filtrar por clasificacion" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Opcion: ", 0, 4);

        switch (opcion)
        {
        case 1:
            registrarProducto();
            break;
        case 2:
            listarInventario();
            break;
        case 3:
            buscarPorNombre();
            break;
        case 4:
            filtrarPorClasificacion();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
