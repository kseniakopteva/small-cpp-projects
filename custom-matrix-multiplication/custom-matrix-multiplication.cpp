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
	cout << "///////  ��������� �� ��������� ������  //////" << endl;
	cout << "//////////////////////////////////////////////" << endl << endl;

	int R1, C1;
	int R2, C2;

	/*�������� ����� ������ �� �������, � ������� 
	���������� �������� ������ ������� ��������� � 
	����������� ����� ������ �������*/

	do {
		inputMatrixParameters(&R1, &C1);
		inputMatrixParameters(&R2, &C2);

		if (C1 != R2) {
			cout << "������� ���������� ��������!" << endl;
			_getch();
		}
	} while (C1 != R2);
	

	int** M1 = new int* [R1]; //M - (�������) ��� ������

	/*� ������� �������� new �� ��� �������� ��������
	������������, ������� �������� ������� R  ����������.
	������ ��������� - ������. �� ���� ��� ����� ������
	��������*/

	for (int i = 0; i < R1; i++) {
		M1[i] = new int[C1];
	}

	// ���������� �������
	fillTheMatrix(&R1, &C1, M1);

	// ����� �������
	outputTheMatrix(&R1, &C1, M1);


	int** M2 = new int* [R2];

	for (int i = 0; i < R2; i++) {
		M2[i] = new int[C2];
	}

	//���������� �������
	fillTheMatrix(&R2, &C2, M2);

	//����� �������
	outputTheMatrix(&R2, &C2, M2);

	//�������� ������� ������� ��� ���������� ���������
	int** M3 = new int* [R1];

	for (int i = 0; i < R1; i++) {
		M3[i] = new int[C2];
	}

	//������� ������� ������� �� ������
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			M3[i][j] = 0;
		}
	}

	//���������
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			for (int m = 0; m < C1; m++) {
				M3[i][j] += M1[i][m] * M2[m][j];
			}
		}
	}
	
	outputTheMatrix(&R1, &C2, M3);
	
	//�������� ������
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

//������� �� ������ ���������� �������
void inputMatrixParameters(int* matrixRows, int* matrixColumns) {
	cout << "--- ������� ��������� �������: ---" << endl;
	cout << "���������� �����: ";
	cin >> *matrixRows;
	cout << "���������� �������: ";
	cin >> *matrixColumns;

	cout << endl;
}

//������� �� ���������� �������
void fillTheMatrix(int *matrixRows, int *matrixColumns, int **arr) {
	for (int i = 0; i < *matrixRows; i++) {
		for (int j = 0; j < *matrixColumns; j++) {
			cout << "������� " << j + 1 << " ������� " << i + 1 << " ����: ";
			cin >> arr[i][j];
			
		}
		cout << endl;
	}
}

//������� �� ������ �������
void outputTheMatrix(int* matrixRows, int* matrixColumns, int** arr) {
	for (int i = 0; i < *matrixRows; i++) {

		for (int j = 0; j < *matrixColumns; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}