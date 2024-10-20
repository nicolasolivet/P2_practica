#pragma once
#include "Producto.h"
#include "ArchProductos.h"

class ServicioProducto
{
	private:
		ArchProductos archivo_p;

	public:
		ServicioProducto();
		Producto ingresarProducto();
		void mostrarProducto(Producto);
		void guardarProducto();
		void listarProductos();
		void modificarProducto();
};

