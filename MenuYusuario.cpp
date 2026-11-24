#include <iostream>
#include <string>

using namespace std;

struct Usuario {
    string usuario;
    string contrasena;
    string rol;
};

Usuario listaUsuarios[3] = {
    {"Jona.admin", "Jonack123", "jefe"},
    {"Brandon.0", "Brandonx0", "empleado"},
    {"Natali.00", "Natali000", "empleado"}
};
int totalUsuarios = 3;

int iniciarSesion();
void mostrarAyuda();
void mostrarIntegrantes();

void cargarInventarioInicial();
void registrarProducto();
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

// ===== Marcadores temporales de los otros modulos =====
// Borrar cada uno cuando se pegue la funcion real.

void cargarInventarioInicial() {}

void registrarProducto() {
    cout << "[Modulo Brandon: Registrar producto]" << endl;
}

void listarInventario() {
    cout << "[Modulo Brandon: Listar inventario]" << endl;
}

void buscarPorNombre() {
    cout << "[Modulo Brandon: Buscar producto]" << endl;
}

void filtrarPorClasificacion() {
    cout << "[Modulo Brandon: Filtrar clasificacion]" << endl;
}

void realizarVenta() {
    cout << "[Modulo Jonathan: Realizar venta]" << endl;
}

void generarReporte() {
    cout << "[Modulo Jonathan: Generar reporte]" << endl;
}
