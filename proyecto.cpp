#include <iostream>
#include <string>

using namespace std;

struct Usuario {
    string usuario;
    string contrasena;
    string rol;
};

struct Producto {
    string nombre;
    string clasificacion;
    int cantidad = 0;
    float precio = 0.0;
    int vendidos = 0;
};

Usuario listaUsuarios[3] = {
    {"Jona.admin", "Jonack123", "jefe"},
    {"Brandon.0", "Brandonx0", "empleado"},
    {"Natali.00", "Natali000", "empleado"}
};
int totalUsuarios = 3;

Producto inventario[14];
int totalProductos = 0;

float totalCaja = 0;
int totalVentas = 0;

int iniciarSesion();
void mostrarAyuda();
void mostrarIntegrantes();

void cargarInventarioInicial();
void registrarProducto();
void imprimirFilaProducto(int i);
void listarInventario();
void buscarPorNombre();
void filtrarPorClasificacion();

void realizarVenta();
void generarReporte();

int main() {
    cargarInventarioInicial();

    int programaActivo = 1;

    while (programaActivo == 1) {
        int posUsuario = iniciarSesion();

        if (posUsuario == -1) {
            break;
        }

        string usuarioActivo = listaUsuarios[posUsuario].usuario;
        string rolActivo = listaUsuarios[posUsuario].rol;

        int opcion;
        do {
            cout << endl;
            cout << "===== TIENDA JNB | Usuario: " << usuarioActivo
                 << " (" << rolActivo << ") =====" << endl;

            if (rolActivo == "jefe") {
                cout << "1. Registrar producto" << endl;
            }
            cout << "2. Listar inventario" << endl;
            cout << "3. Buscar producto por nombre" << endl;
            cout << "4. Filtrar por clasificacion" << endl;
            cout << "5. Realizar venta" << endl;
            if (rolActivo == "jefe") {
                cout << "6. Reporte de resultados" << endl;
            }
            cout << "7. Cerrar sesion" << endl;
            cout << "8. Ayuda" << endl;
            cout << "9. Integrantes" << endl;
            cout << "0. Salir" << endl;
            cout << "Opcion: ";
            cin >> opcion;

            while (cin.fail() || opcion < 0 || opcion > 9) {
                if (cin.fail()) {
                    cin.clear();
                    string limpiar;
                    cin >> limpiar;
                }
                cout << "Opcion no valida. Escriba un numero de las opciones mostradas: ";
                cin >> opcion;
            }

            switch (opcion) {
                case 1:
                    if (rolActivo == "jefe") {
                        registrarProducto();
                    } else {
                        cout << "Acceso denegado: solo el jefe puede registrar productos." << endl;
                    }
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
                case 5:
                    realizarVenta();
                    break;
                case 6:
                    if (rolActivo == "jefe") {
                        generarReporte();
                    } else {
                        cout << "Acceso denegado: solo el jefe puede ver reportes." << endl;
                    }
                    break;
                case 7:
                    cout << "Cerrando sesion..." << endl;
                    break;
                case 8:
                    mostrarAyuda();
                    break;
                case 9:
                    mostrarIntegrantes();
                    break;
                case 0:
                    cout << "Saliendo del sistema..." << endl;
                    programaActivo = 0;
                    break;
            }
        } while (opcion != 0 && opcion != 7);
    }

    return 0;
}

int iniciarSesion() {
    int intentos = 0;
    string usuarioIngresado;
    string passwordIngresada;

    cout << endl;
    cout << "==========================================" << endl;
    cout << "     BIENVENIDO A SISTEMA TIENDA JNB      " << endl;
    cout << "==========================================" << endl;

    while (intentos < 3) {
        cout << endl;
        cout << "Usuario: ";
        cin >> usuarioIngresado;
        cout << "Contrasena: ";
        cin >> passwordIngresada;

        for (int i = 0; i < totalUsuarios; i++) {
            if (listaUsuarios[i].usuario == usuarioIngresado && listaUsuarios[i].contrasena == passwordIngresada) {
                cout << endl;
                cout << "Acceso concedido. Bienvenido/a " << listaUsuarios[i].usuario
                     << " [Rol: " << listaUsuarios[i].rol << "]" << endl;
                return i;
            }
        }

        intentos++;
        cout << "Datos incorrectos. Intentos realizados: " << intentos << " de 3" << endl;
    }

    cout << endl;
    cout << "Superaste el limite de intentos. Sistema bloqueado." << endl;
    return -1;
}

void mostrarAyuda() {
    cout << endl;
    cout << "==========================================" << endl;
    cout << "           AYUDA DEL SISTEMA              " << endl;
    cout << "==========================================" << endl;
    cout << "Como usar el programa:" << endl;
    cout << "- Escriba el numero de la opcion y presione Enter." << endl;
    cout << "- Escriba los nombres en minusculas y sin espacios (ej. coca_cola)." << endl;
    cout << endl;
    cout << "Opciones del menu:" << endl;
    cout << "1. Registrar producto (Solo Jefe): Agrega un nuevo articulo." << endl;
    cout << "2. Listar inventario: Muestra todos los productos y precios." << endl;
    cout << "3. Buscar producto: Busca un articulo por su nombre." << endl;
    cout << "4. Filtrar por clasificacion: Muestra productos por categoria." << endl;
    cout << "5. Realizar venta: Cobra productos y resta el inventario." << endl;
    cout << "6. Reporte de resultados (Solo Jefe): Muestra ventas y stock bajo." << endl;
    cout << "7. Cerrar sesion: Permite cambiar de usuario (Jefe/Empleado)." << endl;
    cout << "8. Ayuda: Muestra esta explicacion." << endl;
    cout << "9. Integrantes: Muestra los datos del equipo." << endl;
    cout << "0. Salir: Cierra el programa." << endl;
}

void mostrarIntegrantes() {
    cout << endl;
    cout << "========================================================" << endl;
    cout << "                 INTEGRANTES DEL EQUIPO                 " << endl;
    cout << "========================================================" << endl;
    cout << "1. Nathali Beatriz Lopez Mejia      - Carnet: [00364526]" << endl;
    cout << "2. Brandon Anthonio Salguero Avelar - Carnet: [00371926]" << endl;
    cout << "3. Jonathan Gerardo Guzman Guevara  - Carnet: [00092523]" << endl;
    cout << "========================================================" << endl;
}

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

void realizarVenta() {
    float totalCliente = 0;
    int seguirComprando = 1;
    int seVendioAlgo = 0;

    cout << endl;
    cout << "--- NUEVA VENTA ---" << endl;

    do {
        string nombreProd;
        cout << "Ingrese el nombre del producto a vender: ";
        cin >> nombreProd;

        int pos = -1;
        for (int i = 0; i < totalProductos; i++) {
            if (inventario[i].nombre == nombreProd) {
                pos = i;
            }
        }

        if (pos == -1) {
            cout << "Producto no encontrado." << endl;
        } else {
            if (inventario[pos].cantidad == 0) {
                cout << "Este producto esta AGOTADO." << endl;
                int agregarMas;
                cout << "Desea agregar mas unidades al inventario? (1 = Si, 0 = No): ";
                cin >> agregarMas;
                while (cin.fail() || (agregarMas != 0 && agregarMas != 1)) {
                    if (cin.fail()) {
                        cin.clear();
                        string limpiar;
                        cin >> limpiar;
                    }
                    cout << "Opcion invalida. Escriba 1 (Si) o 0 (No): ";
                    cin >> agregarMas;
                }

                if (agregarMas == 1) {
                    int nuevasUnidades;
                    cout << "Cuantas unidades desea agregar?: ";
                    cin >> nuevasUnidades;
                    while (cin.fail() || nuevasUnidades < 1) {
                        if (cin.fail()) {
                            cin.clear();
                            string limpiar;
                            cin >> limpiar;
                        }
                        cout << "Cantidad invalida. Ingrese 1 o mas: ";
                        cin >> nuevasUnidades;
                    }
                    inventario[pos].cantidad = inventario[pos].cantidad + nuevasUnidades;
                    cout << "Stock actualizado! Ahora hay " << inventario[pos].cantidad << " unidades." << endl;
                }
            }

            if (inventario[pos].cantidad > 0) {
                cout << "Producto: " << inventario[pos].nombre
                     << " | Precio: $" << inventario[pos].precio
                     << " | Disponibles: " << inventario[pos].cantidad << endl;

                int cantVender;
                cout << "Cantidad a vender: ";
                cin >> cantVender;
                while (cin.fail() || cantVender < 1 || cantVender > inventario[pos].cantidad) {
                    if (cin.fail()) {
                        cin.clear();
                        string limpiar;
                        cin >> limpiar;
                    }
                    cout << "Cantidad no valida o stock insuficiente (disponibles: "
                         << inventario[pos].cantidad << "). Ingrese otra cantidad: ";
                    cin >> cantVender;
                }

                float subtotal = cantVender * inventario[pos].precio;
                inventario[pos].cantidad = inventario[pos].cantidad - cantVender;
                inventario[pos].vendidos = inventario[pos].vendidos + cantVender;
                totalCliente = totalCliente + subtotal;
                seVendioAlgo = 1;

                cout << "Agregado! Subtotal: $" << subtotal << endl;
            }
        }

        cout << "Desea agregar otro producto a la venta? (1 = Si, 0 = No): ";
        cin >> seguirComprando;
        while (cin.fail() || (seguirComprando != 0 && seguirComprando != 1)) {
            if (cin.fail()) {
                cin.clear();
                string limpiar;
                cin >> limpiar;
            }
            cout << "Opcion invalida. Escriba 1 (Si) o 0 (No): ";
            cin >> seguirComprando;
        }

    } while (seguirComprando == 1);

    if (seVendioAlgo == 1) {
        totalCaja = totalCaja + totalCliente;
        totalVentas++;
        cout << endl;
        cout << "===============================" << endl;
        cout << "VENTA FINALIZADA" << endl;
        cout << "Total a pagar: $" << totalCliente << endl;
        cout << "===============================" << endl;
    } else {
        cout << "No se realizo ninguna venta." << endl;
    }
}

void generarReporte() {
    cout << endl;
    cout << "==========================================" << endl;
    cout << "          REPORTE DE RESULTADOS           " << endl;
    cout << "==========================================" << endl;
    cout << "Ventas realizadas: " << totalVentas << endl;
    cout << "Total recaudado en caja: $" << totalCaja << endl;

    cout << endl;
    cout << "--- Productos Vendidos ---" << endl;
    int huboVentas = 0;
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].vendidos > 0) {
            cout << "- " << inventario[i].nombre
                 << " | Vendidos: " << inventario[i].vendidos
                 << " | Ingreso: $" << (inventario[i].vendidos * inventario[i].precio) << endl;
            huboVentas = 1;
        }
    }
    if (huboVentas == 0) {
        cout << "Aun no se han vendido productos." << endl;
    }

    cout << endl;
    cout << "--- Alerta de Stock Bajo (5 o menos unidades) ---" << endl;
    int hayBajos = 0;
    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].cantidad <= 5) {
            cout << "- " << inventario[i].nombre
                 << " | Quedan: " << inventario[i].cantidad << endl;
            hayBajos = 1;
        }
    }
    if (hayBajos == 0) {
        cout << "Todos los productos tienen buen stock." << endl;
    }
    cout << "==========================================" << endl;
}
