#include <iostream>
#include <string>
using namespace std;
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
            // Si el producto esta agotado, pregunta si desea agregar mas unidades
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

            // Si ya tiene disponibilidad, procede a vender
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