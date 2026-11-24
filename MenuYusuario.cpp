#include <iostream>
#include <string>

using namespace std;

struct Usuario {
    string usario;
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

Usuario ListaUsuarios[3] = {
   {" Jona.admin", " Jonack123", " jefe"},
   {" Brandon.0", "Brandox0", "empleado"},
   {" Nathali.00", "Nathali000", "empleado"}
};


int totalusarios = 3;

Producto inventario [14];
int totalProductos = 0;

float totalcaja = 0;
int totalVentas = 0;

int iniciarSesion();
void mostrarAyuda();
void mostrarIntegrantes();

void cargarInventarioInicial() {}

void registrarPorducto() 
{ cout << "[Modulo Brandon: Registrar Producto]" << endl; }

void ListarInventario() 
{ cout << "[Modulo Brandon:  Listar Inventario]" << endl;}

void buscarPornombre()
{ cout << " [Modulo Brandon: Buscar Producto]" << endl;}

cout filtrarPorClasificacion()
{ cout << "[Modulo Brandon: Filtrar clasificacion]" << endl;}

void realizarVenta()
{" [ Modulo Jonathan: Realizar venta]" << enld;}

void generarReporte()
{ cout << "[Modulo Jonathan: Generar reporte]" << endl;}


int main() {
    cargarInventarioInicial();

    int programaActivo = 1;

    while ( ProgramaActivo == 1) {
        int posUsuario = IniciarSesion();


        if ( posUsuario == -1) {
            break;
        }

        string usuarioActivo = listaUsuarios[posUsuario].usuario;
        string rolActivo = listausuarios[posUsuario].rol;


        int opcion;

        do {
            cout << endl;
            cout << "===== TIENDA JNB | Usuario:" usuarioActivo
            << "(" << rolActivo<<") =====" << endl;


            if (rolActivo == "jefe") {
                cout << "1. registrar Producto"<< endl;
            }

            cout <<"2. Listar Inventario"<< endl;
            cout <<"3. Buscar Producto por nombre "<< endl;
            cout << "4. Filtrar por clasificacion" << endl;
            cout << "5. Realizar venta" << endl;
             
            if (rolActivo =="jefe") {
                cout <<"6. reporte de resultados" << endl;
            }
        
            cout << "7. Cerrar sesion" << endl;
            cout << "8. Ayuda" << endl;
            cout << "9. Integrantes" << endl;
            cout << "0. salir" << endl;
            cout << "opcion:";
            cin >> opcion;


            while (cin.fail() || opcion < 0 || opcion > 9) {
                if (cin.fail()) {
                    cin.clear();
                    string limpiar;
                    cin >> limpiar;
                }

                cout << " opcion no valida. Escriba un numero de las opciones mostradas:";
                cin >> opcion;
            }
        
              switch (opcion) {
                case 1:
                if (rolActivo == "jefe") {
                    registrarProducto();
                } else {
                    cout << " Acceso denegado: solo el jefe puede registrar productos." << endl;
                }

                break;
                case 2:
                listarInventario();
                break;
                
                case 3:
                buscarPornombre();
                break;

                case 4:

                filtrarPorclasificacion();
                break;

                case 5:

                realizarVenta();
                break;

                case 6:

                if(rolActivo == "jefe") {
                    generarReporte();
                } else {
                    cout << " Acceso denegado: solo el jefe puede ver reportes." << endl;
                }
                break;

                case 7:

                cout << " Cerrando sesion..." endl;
                break;

                case 8:
                mostrarAyuda();
                break;

                case 9:
                mostrarIntegrantes();
                break;

                case 0 :
                cout << " Saliendo del sistema..." << endl;
                programaActivo = 0;
                break;
              }
        
        } While (opcion ! = 0 && opcion ! = 7);
    }

    return 0;
}

int inciarSesion() {
    int intentos = 0;

    string usuarioIngresando;
    string passwordIngresada;

   cout << endl;
   cout << "================================================="
   << endl;

   cout << " BIENVENIDO A SISTEMA TIENDA JNB " << endl;
   cout << " ===============================================" << endl;


   while (intentos < 3) {
    cout << endl;
    cout << "Usuario:";
    cin >> usuarioIngresado;
    cout << "contrasena:";
    cin >> PasswordIngresada;


    fir (int i = 0; i< totalUsarios;i++) {
        if (listaUsuarios[i].usuario === usuarioIngresado && listaUsuarios[i].contrasena == passwordIngresada) {
            cout << enld;
            cout << " Acceso concedido. Bienvenido/a" << liistaUsuarios[i].usuario
            << "[Rol:" << listaUsuarios[i].rol<<"]" << endl;
            return i;
        }
    }

    intentos++;
    cout << " Datos incorrectos. Intentos realizaso:" << intentos << " de 3" << endl;
   }

   cout << endl;
   cout << " Superaste el limite de intentos. Sistema bloqueado." <<
   endl;
   return -1;
}

void mostrarAyuda() {
    cout << endl;
    cout << "============================================" << endl;
    cout << "   AYUDA DEL SISTEMA   " << endl;
    cout << "============================================" << endl;

    cout << " como usar el programa:" << endl;
    cout << "- Escriba el numero de la opciony presione Enter." << endl;
    cout << "- Escriba los nombres en minusculas y sin espacios (ej.coca_cola)."<< endl;
    cout << endl;

    cout << "Opciones del menu:" << endl;
    cout << "1. Registrar producto(solo jefe): Agrega un nuevo articulo." << endl;
    cout << "2. Listar Inventario: Muestra todos los productos y precios." << endl;
    cout << "3. Buscar producto: Busca un articulo por su nomre." << endl;
    cout << "4. Filtrar por clasificacion: Muestra productos por categorio." << endl;
    cout << "5. Realizar venta: cobra productos y resta el inventario." << endl;
    cout << "6. Reporte de resultadso (solo Jefe): Muestra ventas y stock baje." << endl;
    cout << "7. Cerrar sesion: permite cambiar de usuario(jefe/Empleado)." << endl;
    cout <<"8. Ayuda : muestra esta explicacion." << endl;
    cout << "9. Integrantes: Muestra los datos del equipo." << endl;
    cout << "0. Salir: cierra el programa." << endl;
}


cout mostrarIntegrantes() {
    cout << endl;
    cout << "========================================" << endl;

    cout << "  INTEGRANTES DEL EQUIPO    " << endl;
    cout << "=========================================" << endl;
    cout << "1. Nathali Beatriz Lopez Mejia - Carnet: [00364526]"
    << endl;
    cout << "2. Brandon Anthonio Salguero Avelar - Carnet: [ 00371926]" << endl;
    cout << "3. Jonathan Gerardo Guzman Guevara - Carnet: [00092523]" << endl;
    cout << " ============================================="<< endl;
}