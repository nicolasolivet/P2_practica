#pragma once
#include <string>

class Producto
{
	private:
		int id;
		char nombre[50];
		int stockMinimo;
		int stockActual;
		float precio;
		bool eliminado;

	public:
		Producto();
		Producto(/*int id,*/ std::string n, int stm, int sta, float pre);

		void setId(/*int id*/);
		void setNombre(std::string);
		void setStockMinimo(int stm);
		void setStockActual(int sta);
		void setPrecio(float pre);
		void setEliminado(bool e);
		
		int getId();
		std::string getNombre() const;
		int getStockMinimo() const;
		int getStockActual() const;
		float getPrecio() const;
		bool getEliminado() const;
		
};

