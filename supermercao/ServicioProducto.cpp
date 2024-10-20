#include <iostream>
#include <string>
#include "ServicioProducto.h"

ServicioProducto::ServicioProducto() {}

Producto ServicioProducto::ingresarProducto() {

	std::string nombre;
	int stockMin, stockAct;
	float precio;

	//std::cout << "Ingresa los datos del producto." << std::endl;
	//cin.ignore();
	//getline(cin, nombre);

	std::cout << "Nombre del producto: ";
	//std::getline(std::cin, nombre);
	std::cin >> nombre;

	std::cout << "Stock minimo: ";
	std::cin >> stockMin;

	std::cout << "Stock actual: ";
	std::cin >> stockAct;

	std::cout << "Precio: ";
	std::cin >> precio;

	std::cin.ignore();

	return Producto(nombre, stockMin, stockAct, precio);
}

void ServicioProducto::mostrarProducto(Producto p) {

	std::cout << "----------------------" << std::endl;
	std::cout << "ID del producto:     " << p.getId() << std::endl;
	std::cout << "Nombre del producto: " << p.getNombre() << std::endl;
	std::cout << "Stock minimo:        " << p.getStockMinimo() << std::endl;
	std::cout << "Stock actual:        " << p.getStockActual() << std::endl;
	std::cout << "Precio:              " << p.getPrecio() << std::endl;
}

void ServicioProducto::guardarProducto() {
	
	Producto p;
	ArchProductos ap;
	ServicioProducto sp;
	
	//sp.ingresarProducto();
	if (ap.guardarReg(sp.ingresarProducto()))
	{
		std::cout << "PRODUCTO GUARDADO!!!";
	}
	else {
		std::cout << "No se pudo guardar el producto :(  Volve a intentarlo.";
	}
}

void ServicioProducto::listarProductos() {
	
	ArchProductos ap;
	ServicioProducto sp;

	int cantidad = ap.getCantidadDeRegistros(); //obtengo la cantidad de registros del archivo

	// ¿como puedo crear un vector en base a la cantidad de registros? memoria dinamica
	Producto* productos;
	productos = new Producto[cantidad];

	ap.verTodosReg(productos, cantidad);

	for (int i = 0; i < cantidad; i++)
	{
		sp.mostrarProducto(productos[i]);
	}

	delete[] productos;
}

void ServicioProducto::modificarProducto() {
	
	Producto p;
	ServicioProducto sp; 
	ArchProductos ap; 

	int seleccion, cod;
	std::string nombre;
	

	std::cout << " - Ingresa '0' para buscar por codigo o '1' por nombre - ";
	std::cin >> seleccion;

	switch (seleccion)
	{
		case 0:
			std::cout << " - Ingresa el codigo del producto a modificar - ";
			std::cin >> cod;
			
			int pos = ap.buscarReg(cod); // busco en archivo

			if (pos != -1)
			{
				ap.leerReg(pos); // lee en archivo
				std::cout << " --- Datos del producto --- " << std::endl;
				sp.mostrarProducto(p);

				std::cout << " --- Modifica los datos --- " << std::endl;
				sp.ingresarProducto();
				ap.modificarReg(pos, p);
			}
			else {
				std::cout << " --- El producto no existe --- " << std::endl;
			}
			break;

		//case 1:
		//	
		//	break;
	}

	

}