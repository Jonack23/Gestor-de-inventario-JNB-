// sistema de ventas

float totalRecaudado = 0.0;
int totalVentas = 0;
int unidadesVendidas[MAX] = {0};

void realizarVenta()
{
    if (totalProductos == 0)
    {
        cout << "No hay productos registrados para vender." << endl;
        return;
    }

    float totalCompraActual = 0.0;
    int seguirComprando = 1;
    bool seVendioAlgo = false;

    cout << "\n--- NUEVA VENTA ---" << endl;

    do
    {
        string nombre;
        cout << "Ingrese el nombre del producto a vender: ";
        getline(cin >> ws, nombre);

        int pos = buscarProducto(nombre);

        if (pos == -1)
        {
            cout << "Producto no encontrado en el inventario." << endl;
        }
        else if (cantidades[pos] == 0)
        {
            cout << "El producto '" << nombres[pos] << "' esta AGOTADO." << endl;
        }
        else
        {
            cout << fixed << setprecision(2);
            cout << "Producto: " << nombres[pos]
                 << " | Precio: $" << precios[pos]
                 << " | Stock disponible: " << cantidades[pos] << endl;

            int cantidadVender = leerEntero("Cantidad a vender (0 para cancelar este articulo): ", 0);

            if (cantidadVender == 0)
            {
                cout << "Articulo omitido." << endl;
            }
            else if (cantidadVender > cantidades[pos])
            {
                cout << "Stock insuficiente. Solo hay " << cantidades[pos] << " unidades disponibles." << endl;
            }
            else
            {
                float subtotal = cantidadVender * precios[pos];
                cantidades[pos] -= cantidadVender;
                unidadesVendidas[pos] += cantidadVender;
                totalCompraActual += subtotal;
                seVendioAlgo = true;

                cout << "Agregado: " << cantidadVender << " x " << nombres[pos]
                     << " = $" << subtotal << endl;
            }
        }

        seguirComprando = leerEntero("Desea agregar otro producto a esta venta? (1 = Si, 0 = No): ", 0);

    } while (seguirComprando == 1);

    if (seVendioAlgo)
    {
        totalRecaudado += totalCompraActual;
        totalVentas++;
        cout << fixed << setprecision(2);
        cout << "\n===============================" << endl;
        cout << "VENTA FINALIZADA CON EXITO" << endl;
        cout << "Total a pagar: $" << totalCompraActual << endl;
        cout << "===============================" << endl;
    }
    else
    {
        cout << "No se realizo ninguna venta." << endl;
    }
}

void generarReporte()
{
    cout << fixed << setprecision(2);
    cout << "\n===== REPORTE DE RESULTADOS =====" << endl;
    cout << "Ventas realizadas:       " << totalVentas << endl;
    cout << "Total recaudado en caja: $" << totalRecaudado << endl;

    cout << "\n--- Resumen de Productos Vendidos ---" << endl;
    bool huboVentas = false;
    for (int i = 0; i < totalProductos; i++)
    {
        if (unidadesVendidas[i] > 0)
        {
            cout << "- " << left << setw(15) << nombres[i]
                 << " | Vendidos: " << setw(4) << unidadesVendidas[i]
                 << " | Ingreso: $" << (unidadesVendidas[i] * precios[i]) << endl;
            huboVentas = true;
        }
    }
    if (!huboVentas)
    {
        cout << "Aun no se han registrado ventas de productos." << endl;
    }

    cout << "\n--- Alerta de Stock Critico (<= 5 unidades) ---" << endl;
    bool hayCriticos = false;
    for (int i = 0; i < totalProductos; i++)
    {
        if (cantidades[i] <= 5)
        {
            cout << "- " << left << setw(15) << nombres[i]
                 << " [" << clasificaciones[i] << "] -> Quedan: "
                 << cantidades[i] << " (" << estadoStock(cantidades[i]) << ")" << endl;
            hayCriticos = true;
        }
    }
    if (!hayCriticos)
    {
        cout << "Todos los productos tienen stock suficiente." << endl;
    }
}