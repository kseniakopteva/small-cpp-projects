//counts inputted array's length, average and sum
//bubble sorts it and finds the inputted element
//also finds the mode but it mostly is not correct

#include <iostream>
#include <conio.h>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::swap;

int main() {
	setlocale(LC_ALL, "Russian");

	int arr[10] = { 2, 5, 3, 9, 2, 6, 8, 10, 4, 7 };
	//int size = (sizeof(arr) / 4);
	//int arr[10];
	const int size = 10;

	cout << "��������� ������ ������� �� 0 �� 10:" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " �������: ";
		while (!(cin >> arr[i])) {
			cin.clear();
			while (cin.get() != '\n');

			cout << i + 1 << " �������: ";
		}
		//cin >> arr[i];
	}
	/*cout << "����������������� ������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)
			cout << " - ";
	}*/

	//����� ����� ���� ���������
	//����� ������� ��������������
	double average;
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum += arr[i];
	};

	average = (double)sum / size;
	cout << endl << "����� �������: " << size << endl;
	cout << "������� ��������������: " << average << endl;
	cout << "�����: " << sum << endl;

	//������������� ���������
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				swap(arr[j], arr[i]);
			}
		}
	}

	cout << "��������������� ������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)
			cout << " - ";
	}

	//����� ����

	int mode[size];
	int n = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[j] == arr[i]) {
				n++;
				mode[i] = n;
			}
		}
		n = 0;
	}
	int max = mode[0];
	for (int i = 0; i < size; i++) {
		if (mode[i] > max) {
			max = mode[i];
			n = i;
		}
	}
	cout << endl << "���� �������: " << arr[n] << endl;

	//����� ������ ������� � �������
	int toFind; // ��� �����
	int found = -1; // ������� ��
	int num = 0; // ����� ��������

	cout << endl << "�����: ";
	cin >> toFind;

	for (int i = 0; i < size; i++) {
		if (found < 0) {
			if (toFind == arr[i]) {
				found = 1; // ������!
				num = i; // ������� ����� �������� � �������
			}
		}
	}

	if (found == 1)
		cout << "����� " << toFind << " ��� " << num + 1 << " ������� �������." << endl;
	else
		cout << "������� ������� �� ������." << endl;


	_getch();
	return 0;
}