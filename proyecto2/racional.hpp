#pragma once
#include <math.h>
#include <iostream>

//get MCD
int getMCD(int numero1, int numero2);

class Racional
{
private:
	int n, m; //m!=0 y n, m tales que: m.c.d.(n,m)==1.
	//miscelaneas
	Racional simplificar();
public:
	// Constructores, destructor
	Racional(int, int);
	Racional(): n(0), m(1) {}
	~Racional();
	//// Proyecciones
	inline int num() { return this->n; } //numerador
	inline int den() { return this->m; } //denominador
	//// Operadores aritmeticos
	////unarios
	Racional operator+();
	Racional operator-();
	////binarios
	Racional operator+(Racional); // adicion
	Racional operator-(Racional); // diferencia
	Racional operator*(Racional); // producto
	Racional operator/(Racional); // cociente (con dividendo diferente de cero)
	////incrementales
	void operator-=(Racional);
	void operator+=(Racional);
	void operator*=(Racional);
	void operator/=(Racional);
	//// Operadores "booleanos"
	bool operator== (Racional); // igualdad
	bool operator!= (Racional); // desigualdad
	bool operator> (Racional); // mayor estricto
	bool operator>= (Racional); // mayor igual
	bool operator< (Racional); // menor estricto
	bool operator<= (Racional); // menor igual
};