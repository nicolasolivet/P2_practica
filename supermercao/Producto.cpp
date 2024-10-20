#pragma warning(disable : 4996)
#include "Producto.h"
#include <string>
#include <iostream>

Producto::Producto() : id(0) {}

Producto::Producto(/*int id,*/ std::string n, int stm, int sta, float pre) {

	getId(/*int id*/);
	setNombre(n);
	setStockMinimo(stm);
	setStockActual(sta);
	setPrecio(pre);
	//eliminado = false;
}

//void Producto::setId(/*int id*/) {
//	/*if (id > 0) {
//		this->id = id;
//	}*/
//	int id = 0;
//}

void Producto::setNombre(std::string n) {
	
	if (n.size() < 50) {
		strcpy(this->nombre, n.c_str());
	}
	// strcpy (en que variable quiero guardar la cadena de char, al string lo convierto en char)
}

void Producto::setStockMinimo(int stm) {
	stockMinimo = stm;
}

void Producto::setStockActual(int sta) {
	stockActual = sta;
}

void Producto::setPrecio(float pre) {
	if (pre > 0) {
		precio = pre;
	}
}

void Producto::setEliminado(bool eli) {
	eliminado = eli;
}

int Producto::getId() { return ++id; }

std::string Producto::getNombre() const { return nombre; }

int Producto::getStockMinimo() const { return stockMinimo; }

int Producto::getStockActual() const {return stockActual; }

float Producto::getPrecio() const { return precio; }

bool Producto::getEliminado() const { return eliminado; }

