# Módulo de Inventario (rama `registro`)

Parte del proyecto **Gestor de Inventario "Tienda JNB"**, desarrollada por Brandon Anthonio Salguero Avelar.

Este módulo se encarga de gestionar los productos de la tienda: qué hay, cuántos hay y a qué precio.

## Funciones

- Carga inicial de productos al iniciar el programa
- Registro de nuevos productos
- Validación de duplicados (si el producto ya existe, se suma al stock)
- Listado del inventario en formato de tabla
- Detección de stock crítico (menos de 5 unidades)

## Datos de cada producto

Cada producto se guarda en un `struct Producto` con nombre, clasificación, cantidad, precio y unidades vendidas.

## Cómo ejecutarlo

```bash
g++ registro.cpp -o registro
./registro
```

## Archivos

- `registro.cpp`: código del módulo de inventario
- `.gitignore`: ignora los ejecutables (`*.exe`)
