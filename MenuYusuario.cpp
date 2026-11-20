//Estudiante 1 : Longueo y Menu

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string Nombre_Tienda = "Tienda JNB";
const string version = "1.0";
const int Max_intentos = 3; // Numero maximo de intentos de longin permitidos
const int Max_usuarios = 20; // Numero maximo para arreglo de usuarios

const int Rol_Admin = 1;
const int Rol_vendedor = 2;


const int ACC_agregar_Producto = 1;
const int ACC_consultar_Inventario = 2;
const int ACC_Ayuda = 3;
const int ACC_Integrantes = 3;

const int total_integrantes = 3;

const string nombres_integrantes[total_integrantes] = {"Jonathan", "Brando", "Nathali"};

const string carnets_integrantes[total_integrantes] = {"00092523", "00371926", "00364526"};


// Datos de usuarios 

string usuarios[Max_usuarios];

string contrasenas[Max_usuarios];

int roles[Max_usuarios];

int total_usuarios = 0;


int usuarioActual = -1; // longueo del usuario actual, -1 indica que no hay usuario logueado

const int Max = 100;

string nombres_productos[Max];

string calsificaciones_productos[Max];

int cantidadesPproductos[Max];

float preciosProductos[Max];

int totalProductos = 0;

string aMinuscula(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = tolower((unsigned char)texto[i]);
    }
    return texto;
}

int buscarProducto(string nombre) {
    string buscar = aMinuscula(nombre);
    for (int i = 0; i < totalProductos; i++) {
        if (aMinuscula(nombres_productos[i]) == buscar) {
            return i; // Retorna el índice del producto encontrado
        }
    }
    return -1; // Retorna -1 si el producto no se encuentra
}

int leerEntero(string mensaje, int min) {
    int valor;
    bool valido;

    do {
        cout << mensaje;
        cin >> valor;

       valido = !cin.fail() && valor >= min;

        if (!valido) {
            cout << "Entrada invalida. Por favor, ingrese un numero entero mayor o igual a " << min << "." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n');
        }
    }
        while (!valido);
        cin.ignore(10000, '\n');
        return valor;    
        
}

float leerPrecio (string mensaje) {
    float valor;
    bool valido;

    do {
        cout << mensaje
        cin << valor;
        valido = !cin.fail() && valor > 0;
        if(valido) {
            
            cout << "Dato invalido. Ingrese un precio mayor que 0." << endl;
            cin.clear();
            cin.ingore(1000, '/n');
        }
    }
    while (!valido)
    cin.ingore(1000, '/n');
    return valor;
}

void InventarioInicial() {

    string n[]= {"coca cola", "pepsi", "agua", "lays", "m&m's", "gomitas", "detergente", "lejia", "jabon", "leche", "queso", "yogurt"};

    string h[] = {"bebida", "bebida", "bebida", "snack", "snack", "snack", "limpieza", "limpieza", "limpieza", "lacteos", "lacteos", "lacteos"};

    int c [] = {10, 5, 20, 8, 6, 10, 3, 0, 5, 10, 5, 8};
    float d [] = {1.5, 1.2, 0.8, 1.3, 1.2, 0.5, 2.5, 1.8, 1.0, 1.2, 2.0, 1.5};


    totalProductos = 12;
    for (int i = 0; i < totalProductos; i++) {
        nombres [i] = n [i];
        clasificaciones [i] = h [i];
        cantidades [i] = c [i];
        precios [i] = d [i];

    }

}

void registrarProducto() {

    if (totalProductos >= MAX) {

        cout << " inventorio lleno. No se puede agregar mas productos." << endl;
    return ;
    
    }
 string nombre;
 string calificacion;

    cout << "ingrese el nombre del producto:";
    getline(cin>> ws,nombre);

    if (buscarProducto(nombre) !=-1)
    {
        cout << "Ese producto yua existe en el inventario."<< endl;
       return
    }

    cout << "ingrese la clasificacion del producto: ";
    getline(cin>> ws, calsificacion);
    int cantidad = leerEntero(ingrese la cantidad del producto: ",0);
    float precio = leerPrecio("ingrese el precio del producto: "");
    
    
    nombres[totalProductos] = clasificacion;
    cantidadess[totalProductos] = cantidad;
    precios[totalProductos] = precio;

    totaProductos++;
    cout << "Producto registrado correctmante." << endl;

}

string estadoStock (int cantidad) {
    
        if (cantidad ===0) {
            return "Agotado";
        }
        
        if (cantidad <=5) {
            return "stock bajo"
        }

        return "disponible";
    }

    void imprimirEncabezado() {
        
        cout << left << setw << "no."

        << setw(14) << "nombre"

        << setw(16) << "clasificacion"

        <<setw(10) << "cantidad"

        << setw(10) << "precio"

        << "Estado"<< endl;

        cout << string(62,'_') << endl;
    }

    void imprimirFila(int i) {


        cout << arreglo << setprecision(2);
        cout << left << setw(5) (i+ 1)
        <<setw (14) << nombres [i]
        << setw(16) << clafisicaciones [i]
        << setw(10) << cantidades [i]
        << setw(10) << precios [i]
        << estadoStock (cantidad [i]) << end;

    }

    viod ListarInventario() {

        if (totalProductos ==0) {
            cout << " el inventario esta vacio." << endl;
            return;
        }

        imprimirEmcabezado(); {

            for (int i = 0; i < totalProductos; i++) {
                imprimirFila(i);
            }
        }
    }

    void buscarPorNombre () {

        strign nombre;
        cout << "ingrese el nombre del producto a buscar:";
        getline (cin >> ws, nombre);

        int pos = buscarProducto(nombre);
        if (pos==-1)
        {
            cout << "Producto no encontrado." << endl;
            return;
        }

    }


    viod filtrarPorClasificacion ()
    {
        cout << "ingrese la clasificacion a mostrar:";
       
        getline (cin>> ws, clasificacion);
       
        clasificacion = aMinusculas(clasificacion);

        

        int encontrados = 0;
        for (int i= 0; i< totalproductos; i++)
        {
            if (aMinusculas (clasificaciones[i]) == clasificacion)
        {
            if(encontrados ===0)
            {
                imprimiremcabezado();
            }
            imprimirFila(i);
            econtrados++;
        }
    }
 
        if (encontrados == 0)
        {
            cout << " No hya productos en esa clasificacion." << endl;
        }
    }

   // funciones auxiliares de interfaz

   void pausar();
   {
    cout << "\n Presione enter para continuar...";
    cin.get();
   }

   void imprimirTitulo (string titulo)
   {
    cout << "\n==== "<< endl;
    cout << " " <<titulo<< endl;
    cout << "====" <<endl;
   }

    
   // sistema de Longue

    bool agregarUsuario(string nombre, strin contrasena, int rol)
    
    {
    if (totalUsuarios >= Max_ususarios)
    {
        return false;
    }
    for (int i = 0; i< totalUsuarios; i++)
    {
        if (aMinusculas(usuarios[i]) == aMinusculas(nomb))
    {
     return false;
    }
}

 usuarios[totalUsuarios]= nombre;
 contrasenas[totalUsuarios] = contrasena;
 roles[totalUsuarios] = rol;
 totalUsuarios++;
    return true;
}

//usuarios que existen desde el incio

void cargarusuarioIniciales()
{
    agregarUsuario("jef@", "jef@e123, Rol_Jef@");
    agregarUsuario("empleado", "emp123", Rol_empleado);
}


// devolver a su inicio del usuario si nombre y contrasena son correctos, o-1

int validarCredenciales(string nombre, string contrasena)
{
    for( int i =0; i< totalUsuarios; i++)
    {
        if (aMinusculas(usuarios[i]) == aMinusculas(nombre)&& contrasenas[i] == contrasena)
    {
        return i;
    }
}
return -1;
}


// pide credenciales hasta Max_Intentos. devuelve true si el login fue exitoso

bool iniciarSesion()
{
    imprimirTitulo("Inicio de Sesion -" + NOmbreTienda);

    for (int intento = 1; intento <= Max_intentos; intento++)
    {
        string nombre, contrasena;
        
        cout << "Usuario:";
        getline(cin >> ws, nombre);
        cout << "contrasena:";
        getline(cin >> ws, contrasena);

        int pos = validarCredenciales(nombre, contrasena);
        if (pos != -1)
        {
            usuarioActual = pos;
            cout<< "\nBienvenido," << usuarios [pos] <<"!"<< endl;
            return true;
        }

        cout<< "usuario o contrasena incorrectos. Intento "<<intento << "de" << Max_intentos<< "."<< endl;
    }

    cout << "\n agotaron los "Max_Intentos<< " intentos. El programa se cerrara." << endl;
    return false;
}


//control de permisos


string nombreRol(int rol)
{
    if (rol == Rol_jef@)
    {
        return "jef@";
    }
    return "Empleado";
}

// Devuelve true si el rol puede realizar la accion

bool tienePermiso(int rol, int accion)
{
    if(rol == Rol_Jef@)
    {
        return true;
    }

    switch (accion)
    {
        case ACC_consultar_inventario:
        case ACC_ayuda:
        case ACC_integrantes:
        return true;
    }
    return false; // si ingresa como ACC_agregar_producto
}


// verifiar el permiso del usuario actual y avisa si se le niega

bool verificarAcceso (int accion)
{
    if (tienepermiso(roles[ususarioActual], accion))
    {
        return true;
    }
    cout << "\n Acceso denegado: su rol ("<< nombreRol(Roles [usuarioActual])
    << ") no tiene permiso para esta opcion." << endl;
    return false;
}  


// opciones Estaticaso ( ayuda e integrantes)

void mostrarAyuda()
{
    impirmerTItulo("Ayuda-" + Nombre_Tienda);

    cout << " como usar la aplicacion" << endl;
    cout << " 1. inicie sesion con su usuario y contrasena (maximo)" << Max_intentos<< " intentos)." endl;

    cout << " 2. En el menu principal escruba el numero de la opcion y presione enter. " << endl;
    cout << " 3. el menu se mantiene en pantalla hasta que elija la opcion 0 (salir)." << endl;
    cout << " 4.  si escribe un dato erronio, el pgroma se lo vuelve a pedir." << endl;


    cout << " \nOpciones del Menu" << endl;

    cout << " listar inventario : muestra todos los productos con su estado de stock." << endl;

   cout << " Buscar producto : busco producto por su nombre." endl;

   cout << " filtrar por calificacion: muestra los producto de una categoria." << endl;

   cout << " Agregar producto : registra un producto nuevo (permitido solo el jef@.)" << endl;
   
   cout << " Ayuda a integrantes: imformacion del sistema y del grupo." endl;

   cout << " \nroles" << endl;

   cout << " Jef@ : acceso total. puedo consultar el inventarioy agregar producto." endl;

   cout << " Empleado : acceso restringido. puede consultar el inventario (listar" endl;

   cout <<" Buscar y filtrar), pero no se puede anadir productor." endl;

   cout << " \n Estado de Stock"<< endl;

   cout << " Agotado : 0 unidades | Stock bajo : 1 a 5 unidades | Disponibles : mas de 5." endl;

}


void mostrarIntegrantes()
{
    imprimirTitulo("Integrantes del Grupo");

    cout << lef << sewt(5) << "no." << setw(30) << "nombre" << "Carnet" << endl;

    cout << string (50,'_') << endl;

    for(int i = 0; i < TOtal_Integrantes; i++)
    {
        cout << left << setw (5) << (i + 1)
        
            cout << left << setw (5) << (i + 1)
            << setw(30) << nombre_integrantes[i]
            << Carnets_Integrantes[i] << endl;
        
    }
}


// Menu Principla 

void MostrarMenuPrincipal()
{
    int rol = roles [usuarioActual];

    cout <<"\n==== "<< Nombre_Tienda<<" - Menu Principal === " << endl;
    
    cout << "usuario:" << Usuarios[usuariosActual] << " ( " << nombreRol(rol) << ")" << endl;

    cout << " ----------" endl;

    cout << "1. listar inventario" << endl;
    cout << "2. Buscar producto por nombre" << endl;
    cout << "3. Filtrar por clasificacion" << endl;
    cout << "4. Ayuda" << endl;
    cout << "5. Integrantes" << endl;

    // si es empleado quien ingreso se oculta

    if (tienepermiso(rol, ACC_agregar_producto))
    {
        cout << "6. agregar producto" << endl;
    }
    
    cout << "0.salir" << endl;
}


// repite hasa cuando el usuario elija salir


void ejecutarMenuPrincpial ()
{
    int opcion;
    do
    {
     
        mostrarMenuPrincipal();
        opcion = leerEntero("opcion:",0);

        switch (opcion)
    {
        case 1:
             listarInventario();
              break;

        case2:
            listarPornombre();
            break;

       case 3:
            filtarPorClasificacion();
            break;
            
      case 4: 
            mostrar Ayuda();
            break;
            
     case 5: 
            mostrarIntegrantes();
            break;

     case 6 :
     
        if (verificarAcceso (ACC_Agregar_Producto))
        {
            registrarproducto();
        }

        break;

        case 0:
            cout << "\n Saliendo del sistema..." << endl;
            break;
            
          default :
             cout << "opcion invalida." << endl;  
        
    }

    if (opcion != 0)
    {
        pausar();
    }

 } while (opcion !=0);
    
}

//programa principal


int main()
{
    cargarInventarioIncial();
    cargarusuariosIniciales();

    if(iniciarSesion())
    {
        ejecutarMenuPrincpial();
    }

    cout << "\n Gracias por usar" << Tienda JNB << "Te esperamos nuevamente!" << endl;
    
    return 0;
}