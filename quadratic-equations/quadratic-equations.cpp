#include <iostream>
#include <cmath>
#include <conio.h>

#include <Windows.h>
using namespace std;

using std::cout;//директива пространства имен объявляем cout в глобальной области
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");

	double a, b, c;
	char calc, quit;

	do {
		system("cls");
		cout << "\t***Программа по решению квадратных кравнений***" << endl << endl;

		cout << endl << "Показывать вычисления?(y/n)" << endl;
		cin >> calc;

		cout << "Введите a, b и c: (со знаками)" << endl << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;

		//calculate D
		double d = (b * b) - (4 * a * c);
		if (calc == 'y') {
			cout << endl << "Вычисляем дискриминант: \n" << "D = b^2 - 4ac = " << b << "^2 - 4 * " << a << " * " << c;
			cout << " = " << b * b << " - " << 4 * a * c << " = " << d << endl;
		}

		if (d == 0) {
			double x1 = (-b) / (2 * a);
			if (calc == 'y')
				cout << "Вычисляем корень: \n" << "x1 = (-b + корень(d)) / 2a = (- " << b << " + " << sqrt(d) << ") / " << 2 * a << " = " << x1 << endl;
			cout << endl << "* Дискриминант равен " << d << endl;
			cout << "* Корень равен " << x1 << endl;
		}
		else if (d > 0) {
			double x1 = (-b + sqrt(d)) / (2 * a);
			double x2 = (-b - sqrt(d)) / (2 * a);
			if (calc == 'y') {
				cout << "Вычисляем корни: \n" << "x1 = (-b + корень(d)) / 2a = (- " << b << " + " << sqrt(d) << ") / " << 2 * a << " = " << x1 << endl;
				cout << "x2 = (-b - корень(d)) / 2a = (- " << b << " - " << sqrt(d) << ") / " << 2 * a << " = " << x2 << endl << endl;
			}

			cout << endl << "* Дискриминант равен " << d << endl;
			cout << "* Первый корень равен " << x1 << endl;
			cout << "* Второй корень равен " << x2 << endl;
		}
		else {
			cout << endl << "* Нет решений" << endl;
		};

		cout << endl << "Ввести другие числа?(y/n)" << endl;

	} while (cin >> quit && quit == 'y');
}