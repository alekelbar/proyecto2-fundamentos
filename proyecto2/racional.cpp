#include "racional.hpp"

int getMCD(int numero1, int numero2)
{
	// Asegurarse de que ambos números sean positivos
	numero1 = abs(numero1);
	numero2 = abs(numero2);

	// Realizar el algoritmo de Euclides de forma iterativa
	while (numero2 != 0) {
		int temp = numero2;
		numero2 = numero1 % numero2;
		numero1 = temp;
	}
	// El MCD se encuentra en numero1
	return numero1;
}

Racional Racional::simplificar()
{
	// Pueden consultar el porque aquí: https://www.youtube.com/watch?v=0opNDyuqCfg
	int mcd = getMCD(this->n, this->m);
	return Racional(this->n / mcd, this->m / mcd);
}

Racional::Racional(int dividendo, int divisor) : n(dividendo), m(divisor) {}

Racional::~Racional(){}


// UNARIOS...
Racional Racional::operator+() {
	// ¿Que cambia? 
	return *this;
}

Racional Racional::operator-() {
	// ¿Que cambia? 
	return Racional(this->n * -1, this->m * -1);
}

// BINARIOS...
Racional Racional::operator+(Racional racional) {
	// ¿Como se suman fracciones?
	// a   c   ad + bc
	// b + d =   bd
	int mul_num = this->n * racional.den();
	int mul_den = this->m * racional.num();
	return Racional(mul_num + mul_den, this->m * racional.den());
}

Racional Racional::operator-(Racional racional) {
	// ¿Como se restan fracciones?
	// a   c   ad - bc
	// b - d =   bd
	int mul_num = this->n * racional.den();
	int mul_den = this->m * racional.num();
	return Racional(mul_num - mul_den, this->m * racional.den());
}

Racional Racional::operator*(Racional racional)
{
	// ¿Como se multiplican fracciones?
	// a   c     ac
	// b * d =   bd
	return Racional(this->n * racional.num(), this->m * racional.den());
}

Racional Racional::operator/(Racional racional)
{
	// ¿Como se dividen fracciones?
	// a/b
	// c/d = a*d/b*c
	return Racional(this->n * racional.den(), this->m * racional.num());
}

void Racional::operator-=(Racional racional)
{
	*this = *this - racional;
}

void Racional::operator+=(Racional racional)
{
	*this = *this + racional;
}

void Racional::operator*=(Racional racional)
{
	*this = *this * racional;
}

void Racional::operator/=(Racional racional)
{
	*this = *this / racional;
}

// Porque las comparaciones las hago así: https://www.youtube.com/watch?v=u1XSGdyX4XQ y tambien
// https://www.youtube.com/watch?v=DkIeIJFpJUY

bool Racional::operator==(Racional racional)
{
	Racional simplifyRational = this->simplificar();
	Racional aux = racional.simplificar();

	return (simplifyRational.num() == aux.n) && (simplifyRational.den() == aux.m);
}

bool Racional::operator!=(Racional racional)
{
	racional = racional.simplificar();
	return !(*this == racional);
}

bool Racional::operator>(Racional racional)
{
	return (this->n * racional.m) > (this->m * racional.n);
}

bool Racional::operator>=(Racional racional)
{
	return (this->n * racional.m) >= (this->m * racional.n);
}

bool Racional::operator<(Racional racional)
{
	return (this->n * racional.m) < (this->m * racional.n);
}

bool Racional::operator<=(Racional racional)
{
	return (this->n * racional.m) <= (this->m * racional.n);
}

