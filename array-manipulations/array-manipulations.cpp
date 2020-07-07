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

	cout << "Наполните массив цифрами от 0 до 10:" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " элемент: ";
		while (!(cin >> arr[i])) {
			cin.clear();
			while (cin.get() != '\n');

			cout << i + 1 << " элемент: ";
		}
		//cin >> arr[i];
	}
	/*cout << "Неотсортированный массив: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)
			cout << " - ";
	}*/

	//Найти сумму всех элементов
	//Найти среднее арифметическое
	double average;
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum += arr[i];
	};

	average = (double)sum / size;
	cout << endl << "Длина массива: " << size << endl;
	cout << "Среднее арифметическое: " << average << endl;
	cout << "Сумма: " << sum << endl;

	//Отсортировать пузырьком
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				swap(arr[j], arr[i]);
			}
		}
	}

	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)
			cout << " - ";
	}

	//Найти моду

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
	cout << endl << "Мода массива: " << arr[n] << endl;

	//Найти нужный элемент в массиве
	int toFind; // что найти
	int found = -1; // найдено ли
	int num = 0; // номер элемента

	cout << endl << "Найти: ";
	cin >> toFind;

	for (int i = 0; i < size; i++) {
		if (found < 0) {
			if (toFind == arr[i]) {
				found = 1; // найден!
				num = i; // запомни номер элемента в массиве
			}
		}
	}

	if (found == 1)
		cout << "Число " << toFind << " это " << num + 1 << " элемент массива." << endl;
	else
		cout << "Искомый элемент не найден." << endl;


	_getch();
	return 0;
}