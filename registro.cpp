#include <iostream>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    string clasificacion;
    int cantidad = 0;
    float precio = 0.0;
    int vendidos = 0;
};

Producto inventario[14];
int totalProductos = 0;

void cargarInventarioInicial() {
    inventario[0]  = {"coca_cola",  "bebida",   10, 1.50, 0};
    inventario[1]  = {"pepsi",      "bebida",    5, 1.20, 0};
    inventario[2]  = {"agua",       "bebida",   20, 0.80, 0};
    inventario[3]  = {"lays",       "snack",     8, 1.30, 0};
    inventario[4]  = {"m&m's",      "snack",     6, 1.20, 0};
    inventario[5]  = {"gomitas",    "snack",    10, 0.50, 0};
    inventario[6]  = {"detergente", "limpieza",  3, 2.50, 0};
    inventario[7]  = {"lejia",      "limpieza",  0, 1.80, 0};
    inventario[8]  = {"jabon",      "limpieza",  5, 1.00, 0};
    inventario[9]  = {"leche",      "lacteos",  10, 1.20, 0};
    inventario[10] = {"queso",      "lacteos",   5, 2.00, 0};
    inventario[11] = {"yogurt",     "lacteos",   8, 1.50, 0};

    totalProductos = 12;
}

void registrarProducto() {
    if (totalProductos >= 14) {
        cout << "El inventario esta lleno." << endl;
        return;
    }

    Producto nuevo;
    cout << endl;
    cout << "--- REGISTRAR PRODUCTO ---" << endl;
    cout << "Nombre del producto (sin espacios): ";
    cin >> nuevo.nombre;

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].nombre == nuevo.nombre) {
            int extra;
            cout << "El producto ya existe. Cantidad a sumar: ";
            cin >> extra;
            while (cin.fail() || extra < 1) {
                if (cin.fail()) {
                    cin.clear();
                    string limpiar;
                    cin >> limpiar;
                }
                cout << "Dato invalido. Ingrese un numero mayor a 0: ";
                cin >> extra;
            }
            inventario[i].cantidad = inventario[i].cantidad + extra;
            cout << "Stock actualizado! Ahora hay " << inventario[i].cantidad << " unidades." << endl;
            return;
        }
    }

    cout << "Clasificacion (bebida, snack, limpieza, lacteos): ";
    cin >> nuevo.clasificacion;

    cout << "Cantidad: ";
    cin >> nuevo.cantidad;
    while (cin.fail() || nuevo.cantidad < 0) {
        if (cin.fail()) {
            cin.clear();
            string limpiar;
            cin >> limpiar;
        }
        cout << "Cantidad invalida. Ingrese un numero (0 o mas): ";
        cin >> nuevo.cantidad;
    }

    cout << "Precio: $";
    cin >> nuevo.precio;
    while (cin.fail() || nuevo.precio <= 0) {
        if (cin.fail()) {
            cin.clear();
            string limpiar;
            cin >> limpiar;
        }
        cout << "Precio invalido. Ingrese un numero mayor a 0: $";
        cin >> nuevo.precio;
    }

    nuevo.vendidos = 0;
    inventario[totalProductos] = nuevo;
    totalProductos++;

    cout << "Producto registrado con exito!" << endl;
}

void imprimirFilaProducto(int i) {
    if (i + 1 < 10) {
        cout << (i + 1) << "    ";
    } else {
        cout << (i + 1) << "   ";
    }

    cout << inventario[i].nombre;
    for (int s = inventario[i].nombre.length(); s < 15; s++) {
        cout << " ";
    }

    cout << inventario[i].clasificacion;
    for (int s = inventario[i].clasificacion.length(); s < 13; s++) {
        cout << " ";
    }

    if (inventario[i].cantidad < 10) {
        cout << inventario[i].cantidad << "       ";
    } else {
        cout << inventario[i].cantidad << "      ";
    }

    cout << "$" << inventario[i].precio << "     ";

    if (inventario[i].cantidad == 0) {
        cout << "AGOTADO";
    } else if (inventario[i].cantidad <= 5) {
        cout << "Stock bajo";
    } else {
        cout << "Disponible";
    }
    cout << endl;
}

void listarInventario() {
    cout << endl;
    cout << "=================================================================" << endl;
    cout << "                   INVENTARIO DE TIENDA JNB                      " << endl;
    cout << "=================================================================" << endl;
    cout << "No.  Producto       Categoria    Stock   Precio   Estado" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 0; i < totalProductos; i++) {
        imprimirFilaProducto(i);
    }
    cout << "=================================================================" << endl;
}

void buscarPorNombre() {
    string buscado;
    cout << endl;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin >> buscado;

    int encontrado = 0;
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].nombre == buscado) {
            cout << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "No.  Producto       Categoria    Stock   Precio   Estado" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            imprimirFilaProducto(i);
            cout << "-----------------------------------------------------------------" << endl;
            encontrado = 1;
        }
    }

    if (encontrado == 0) {
        cout << "Producto no encontrado." << endl;
    }
}

void filtrarPorClasificacion() {
    string categoria;
    cout << endl;
    cout << "Ingrese la clasificacion a mostrar: ";
    cin >> categoria;

    int encontrados = 0;
    cout << endl;
    cout << "=================================================================" << endl;
    cout << " CATEGORIA: " << categoria << endl;
    cout << "=================================================================" << endl;
    cout << "No.  Producto       Categoria    Stock   Precio   Estado" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].clasificacion == categoria) {
            imprimirFilaProducto(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "No hay productos en esa clasificacion." << endl;
    }
    cout << "=================================================================" << endl;
}

// Menu minimo solo para probar las funciones de inventario.
int main() {
    cargarInventarioInicial();

    int opcion;
    do {
        cout << endl;
        cout << "1. Registrar producto" << endl;
        cout << "2. Listar inventario" << endl;
        cout << "3. Buscar producto por nombre" << endl;
        cout << "4. Filtrar por clasificacion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        while (cin.fail() || opcion < 0 || opcion > 4) {
            if (cin.fail()) {
                cin.clear();
                string limpiar;
                cin >> limpiar;
            }
            cout << "Opcion no valida. Escriba un numero de las opciones mostradas: ";
            cin >> opcion;
        }

        switch (opcion) {
            case 1: registrarProducto(); break;
            case 2: listarInventario(); break;
            case 3: buscarPorNombre(); break;
            case 4: filtrarPorClasificacion(); break;
        }
    } while (opcion != 0);

    return 0;
}