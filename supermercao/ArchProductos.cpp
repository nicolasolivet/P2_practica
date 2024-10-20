#pragma once
#include <string>
#include "ArchProductos.h"

ArchProductos::ArchProductos() {
	fileName = "productos.dat";
}

bool ArchProductos::guardarReg(const Producto &p) {
	
	FILE* pfile;
	bool result;

	pfile = fopen(fileName.c_str(), "ab"); //c_str() devuelve el puntero char, transforma de string a char para que fopen lo pueda leer
	if (pfile == nullptr) { return false; }

	result = fwrite(&p, sizeof(Producto), 1, pfile) == 1; //&p, el lugar de memoria donde quiero guardar
	fclose(pfile);

	return result;
}

Producto ArchProductos::leerReg(int pos) {
	
	Producto reg;
	FILE *pfile;

	pfile = fopen(fileName.c_str(), "rb");
	if (pfile == nullptr) { return reg; }

	fseek(pfile, sizeof(Producto) * pos, SEEK_SET); // el fseek, particularmente "sizeof(Producto) * pos" es lo que me permite "encontrar" el producto para leerlo
	// entonces seria, fseek mueve el "cursor" entre los items, cuando los argumentos encajan con lo que queres encontrar lo lee con fread
	// otra forma sera para leer primero necesito tenerlo 
	
	fread(&reg, sizeof(Producto), 1, pfile);

	fclose(pfile);
	return reg;
}

int ArchProductos::getCantidadDeRegistros() {
	
	int cantidad, total;
	Producto p;
	FILE *pfile;
	pfile = fopen(fileName.c_str(), "rb");
	if (pfile == nullptr) { return 0; }

	fseek(pfile, 0, SEEK_END); //con fseek le decimos al cursor donde queremos que se posicione

	total = ftell(pfile); //ftell indica la posicion del cursor, cada posicion es un registro.
	// ftell, te dice en que BYTE se encuentra el cursor. osea hago un fseek, me voy al final y hago un ftell, cuenta cuantas movientos hace tengo el tamaño del archivo. esa cantidad de BYTES la divido por cuanto mide un registro, tengo el tamaño del archivo.
	
	fclose(pfile);
	return cantidad = total / sizeof(Producto);

	// total es la cantidad de registros en BYTES 
}

bool ArchProductos::verTodosReg(Producto p[], int cantProductos) {
	
	bool result;
	FILE* pfile;
	pfile = fopen(fileName.c_str(), "rb");

	if (pfile == nullptr) { return false; }

	result = fread(p, sizeof(Producto), cantProductos, pfile) == 1;

	fclose(pfile);
	return result;
}

bool ArchProductos::modificarReg(int pos, Producto& p) {
	
	FILE* pfile;
	bool result;

	pfile = fopen(fileName.c_str(), "rb+"); //c_str() devuelve el puntero char, transforma de string a char para que fopen lo pueda leer
	if (pfile == nullptr) { return false; }

	fseek(pfile, pos, SEEK_SET);

	result = fwrite(&p, sizeof(Producto), 1, pfile) == 1; //&p, el lugar de memoria donde quiero guardar
	fclose(pfile);

	return result;
}

int ArchProductos::buscarReg(int id) {
	
	Producto p;
	FILE* pfile;
	int pos = 0;

	pfile = fopen(fileName.c_str(), "rb"); //c_str() devuelve el puntero char, transforma de string a char para que fopen lo pueda leer
	if (pfile == nullptr) { return false; }

	while (fread(&p, sizeof(Producto), 1, pfile) == 1) //&p, el lugar de memoria donde quiero guardar
	{  
		if (p.getId() == id) {
			break;
		}
		pos++; // 
	} 
	
	fclose(pfile); 
	
	if (p.getId() == id) { // dos posibilidades, o que haya llegado al final porque lo encontro e hizo el break o porque trato de leer y no pudo
		return pos;
	}
	else { // significa que no lo encontro
		return -1;
	}
}