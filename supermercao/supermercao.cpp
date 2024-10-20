#include <iostream>
#include "Producto.h"
#include "ArchProductos.h"
#include "ServicioProducto.h"
using namespace std;

//Producto cargar() {
//   
//   string nombre;
//   int stockMin, stockAct;
//   float precio;
//
//   cout << "Ingresa los datos del producto." << endl;
//   //cin.ignore();
//   //getline(cin, nombre);
//
//   cout << "Nombre del producto: ";
//   getline(cin, nombre);
//   //cin >> nombre;
//
//   cout << "Stock minimo: ";
//   cin >> stockMin;
//
//   cout << "Stock actual: ";
//   cin >> stockAct;
//
//   cout << "Precio: ";
//   cin >> precio;
//
//   cin.ignore();
//
//   return Producto(nombre, stockMin, stockAct, precio);

//void mostrar(Producto p) {
//   
//   cout << "----------------------" << endl;
//   cout << "ID de producto:" << p.getId() << endl;
//   cout << "Nombre de producto" << p.getNombre() << endl;
//   cout << "Stock minimo: " << p.getStockMinimo() << endl;
//   cout << "Stock actual: " << p.getStockActual() << endl;
//   cout << "Precio: " << p.getPrecio() << endl;
//}

//void mostrarTodos() {
//    
//    ArchProductos ap;
//    ServicioProducto sp;
//
//    int cantidad = ap.getCantidadDeRegistros(); //obtengo la cantidad de registros del archivo
//
//    // ¿como puedo crear un vector en base a la cantidad de registros? memoria dinamica
//    Producto *productos;
//    productos = new Producto[cantidad];
//
//    ap.verTodos(productos, cantidad);
//
//    for (int i = 0; i < cantidad; i++)
//    {
//        sp.mostrarProducto(productos[i]);
//    }
//
//    delete[] productos;
//}


int main()
{
    // MENU //
    // Cargar (id/codigo autonumerico)
    // Mostrar todo  
    // Mostrar todo por nombre
    // Modificar por codigo
    // Eliminar por codigo
    // Buscar 
    // Salir
    
    Producto p; 
    ArchProductos ap;
    ServicioProducto sp;

    sp.guardarProducto();
    //sp.listarProductos();
    
   

    return 0;
}
