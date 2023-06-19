// proyecto2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "racional.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int MAX_ROWS = 10;    // Tamaño máximo de filas
const int MAX_COLS = 10;    // Tamaño máximo de columnas

class Matrix {
private:
	int m;                   // Número de filas
	int n;                   // Número de columnas
	Racional matrix[MAX_ROWS][MAX_COLS];

public:
	// Constructor
	Matrix(int rows, int cols) {
		if (rows <= MAX_ROWS && cols <= MAX_COLS) {
			m = rows;
			n = cols;
			initializeMatrix();
		}
		else {
			// Manejar el error de dimensiones inválidas de la matriz
			std::cout << "Error: Las dimensiones exceden los límites máximos." << std::endl;
			m = 0;
			n = 0;
		}
	}


	// Llenar la matriz con numeros racionales generados al azar
	void fillRandomRational() {
		srand(time(0));  // Inicializar la semilla aleatoria con el tiempo actual

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int numerator = rand() % 100;   // Numerador aleatorio entre 0 y 99
				int denominator = rand() % 100 + 1;  // Denominador aleatorio entre 1 y 100

				Racional rational(numerator, denominator);
				this->matrix[i][j] = rational;
			}
		}
	}

	// Llenar la matriz con valores enteros entre 1 y n*m eligiendo al azar las posiciones de asignación
	void fillRandomInteger() {
		srand(time(0));  // Inicializar la semilla aleatoria con el tiempo actual

		initializeMatrix();

		Racional count(1, 1);
		Racional totalElements = Racional(m * n, 1);

		while (count <= totalElements) {
			int row = rand() % m;
			int col = rand() % n;

			if (matrix[row][col] == Racional(0, 1)) {
				std::cout << this->matrix[row][col].num();
				matrix[row][col] = count;

				count += Racional(1, 1);
			}
		}
	}

	// Sobrecarga del operador de suma (+)
	Matrix operator+(const Matrix& other) {
		// 1 2   2 4   1+2 2+4
		// 5 8 + 8 4 + 5+8 ...

		Matrix result(m, n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}

		return result;
	}

	// Sobrecarga del operador de asignación (=)
	Matrix& operator=(const Matrix& other) {
		if (this != &other) {
			m = other.m;
			n = other.n;

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = other.matrix[i][j];
				}
			}
		}

		return *this;
	}

	// Desplegar la matriz en la pantalla dentro de un marco construido con caracteres de la tabla ASCII
	void displayMatrix() {
		// Imprimir el borde superior
		for (int i = 0; i < n + 2; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;

		// Imprimir las filas
		for (int i = 0; i < m; i++) {
			std::cout << "|";
			for (int j = 0; j < n; j++) {
				int num = matrix[i][j].num();
				int den = matrix[i][j].den();
				
				std::cout << num;
				std::cout << ((den != 1) ? "/" + std::to_string(den) + " " : " ");
			}
			std::cout << "|" << std::endl;
		}

		// Imprimir el borde inferior
		for (int i = 0; i < n + 2; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}

	// Retornar la matriz transpuesta
	Matrix transpose() {
		// TODO: hacer la validación requerida
		Matrix result(n, m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result.matrix[i][j] = matrix[j][i];
			}
		}

		return result;
	}

	// Calcular la suma de las entradas de una fila dada
	Racional sumRow(int row) {
		Racional sum(0, 1);

		if (row >= 0 && row < m) {
			for (int j = 0; j < n; j++) {
				sum += matrix[row][j];
			}
		}
		return sum;
	}

	// Calcular la suma de las entradas de una columna dada
	Racional sumColumn(int col) {
		Racional sum(0, 1);

		if (col >= 0 && col < n) {
			for (int i = 0; i < m; i++) {
				sum += matrix[i][col];
			}
		}

		return sum;
	}

private:
	// Inicializar la matriz con ceros
	void initializeMatrix() {
		for (int i = 0; i < MAX_ROWS; i++) {
			for (int j = 0; j < MAX_COLS; j++) {
				matrix[i][j] = Racional(0, 1);
			}
		}
	}
};

int main() {
	int m, n;

	std::cout << "Ingrese el numero de filas: ";
	std::cin >> m;

	std::cout << "Ingrese el numero de columnas: ";
	std::cin >> n;

	//Matrix myMatrix(m, n);
	//myMatrix.fillRandomRational();
	//std::cout << "Matriz generada con numeros racionales aleatorios:" << std::endl;
	//myMatrix.displayMatrix();

	//Matrix otherMatrix(m, n);
	//otherMatrix.fillRandomInteger();
	//std::cout << "Otra matriz generada con valores enteros aleatorios:" << std::endl;
	//otherMatrix.displayMatrix();

	//Matrix sumMatrix = myMatrix + otherMatrix;
	//std::cout << "Resultado de la suma de las dos matrices:" << std::endl;
	//sumMatrix.displayMatrix();

	//Matrix transposedMatrix = myMatrix.transpose();
	//std::cout << "Matriz transpuesta de la primera matriz:" << std::endl;
	//transposedMatrix.displayMatrix();

	//int row;
	//std::cout << "Ingrese el número de fila para calcular la suma de sus entradas: ";
	//std::cin >> row;
	//Racional sumRow = myMatrix.sumRow(row);
	//std::cout << "Suma de las entradas de la fila " << row << ": ";
	//std::cout << "Suma de las entradas de la fila " << sumRow.num() << "/" << sumRow.den();

	//int col;
	//std::cout << "Ingrese el número de columna para calcular la suma de sus entradas: ";
	//std::cin >> col;
	//Racional sumColumn = myMatrix.sumColumn(col);
	//std::cout << "Suma de las entradas de la columna " << col << ": ";
	//std::cout << "Suma de las entradas de la fila " << sumColumn.num() << "/" << sumColumn.den();

	return 0;
}
