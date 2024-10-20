#pragma once
#include <string>
#include "Producto.h"

class ArchProductos
{
	private:
		std::string fileName;
	
	public:
		ArchProductos();
		bool guardarReg(const Producto &p);
		bool modificarReg(int pos, Producto &p);
		Producto leerReg(int pos);
		int getCantidadDeRegistros(); //para poder listar, primero necesito saber la cantidad de registros que tengo.
		bool verTodosReg(Producto p[], int);
		int buscarReg(int pos);

};

