# Tienda JNB – Módulo de ventas y reportes

Parte del sistema de inventario de Tienda JNB (Fundamentos de Programación, UCA).
Responsable: Jonathan Gerardo Guzmán Guevara.

## Qué hace
- **Realizar venta:** vende uno o varios productos, descuenta el stock y muestra el total a pagar.
- **Generar reporte:** muestra ventas realizadas, total en caja, productos vendidos y productos con poco stock.

Este archivo es una versión de prueba con 3 productos de ejemplo. Luego se une al menú y al inventario del equipo.

## Cómo ejecutarlo
```
g++ ventas.cpp -o ventas
./ventas
```

## Cómo usarlo
1. Elige 1 para vender o 2 para ver el reporte.
2. Escribe el nombre del producto en minúsculas y sin espacios (ejemplo: `coca_cola`).
3. Escribe la cantidad y sigue las instrucciones en pantalla.

## Nota
Si el producto está agotado, el sistema permite agregar más unidades.
