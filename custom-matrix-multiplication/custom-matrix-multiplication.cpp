//multiplying two matrixes

#include <iostream>
#include <cstring>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

void fillTheMatrix(int* matrixRows, int* matrixColumns, int** arr);
void outputTheMatrix(int* matrixRows, int* matrixColumns, int** arr);
void inputMatrixParameters(int* matrixRows, int* matrixColumns);

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "//////////////////////////////////////////////" << endl;
	cout << "///////  Программа по умножению матриц  //////" << endl;
	cout << "//////////////////////////////////////////////" << endl << endl;

	int R1, C1;
	int R2, C2;

	/*умножить можно только те матрицы, у которых 
	количество столбцов первой матрицы совпадает с 
	количеством рядов второй матрицы*/

	do {
		inputMatrixParameters(&R1, &C1);
		inputMatrixParameters(&R2, &C2);

		if (C1 != R2) {
			cout << "Матрицы невозможно умножить!" << endl;
			_getch();
		}
	} while (C1 != R2);
	

	int** M1 = new int* [R1]; //M - (матрица) это массив

	/*с помощью операции new мы ему выделяем адресное
	пространство, которое способно зранить R  указателей.
	Каждый указатель - массив. То есть это будет массив
	массивов*/

	for (int i = 0; i < R1; i++) {
		M1[i] = new int[C1];
	}

	// заполнение массива
	fillTheMatrix(&R1, &C1, M1);

	// вывод массива
	outputTheMatrix(&R1, &C1, M1);


	int** M2 = new int* [R2];

	for (int i = 0; i < R2; i++) {
		M2[i] = new int[C2];
	}

	//заполнение массива
	fillTheMatrix(&R2, &C2, M2);

	//вывод массива
	outputTheMatrix(&R2, &C2, M2);

	//создание третьей матрицы для результата умножения
	int** M3 = new int* [R1];

	for (int i = 0; i < R1; i++) {
		M3[i] = new int[C2];
	}

	//очистка третьей матрицы от мусора
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			M3[i][j] = 0;
		}
	}

	//умножение
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			for (int m = 0; m < C1; m++) {
				M3[i][j] += M1[i][m] * M2[m][j];
			}
		}
	}
	
	outputTheMatrix(&R1, &C2, M3);
	
	//удаление памяти
	for (int i = 0; i < R1; i++) {
		delete[] M1[i];
	}
	delete[] M1;

	for (int i = 0; i < R2; i++) {
		delete[] M2[i];
	}
	delete[] M2;

	for (int i = 0; i < R1; i++) {
		delete[] M3[i];
	}
	delete[] M3;

	_getch();
	return 0;
}

//функция по задаче параметров матрицы
void inputMatrixParameters(int* matrixRows, int* matrixColumns) {
	cout << "--- Введите параметры матрицы: ---" << endl;
	cout << "Количество рядов: ";
	cin >> *matrixRows;
	cout << "Количество колонок: ";
	cin >> *matrixColumns;

	cout << endl;
}

//функция по заполнению массива
void fillTheMatrix(int *matrixRows, int *matrixColumns, int **arr) {
	for (int i = 0; i < *matrixRows; i++) {
		for (int j = 0; j < *matrixColumns; j++) {
			cout << "Введите " << j + 1 << " элемент " << i + 1 << " ряда: ";
			cin >> arr[i][j];
			
		}
		cout << endl;
	}
}

//функция по выводу массива
void outputTheMatrix(int* matrixRows, int* matrixColumns, int** arr) {
	for (int i = 0; i < *matrixRows; i++) {

		for (int j = 0; j < *matrixColumns; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}