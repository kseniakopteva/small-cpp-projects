#include <iostream>
#include <cmath>
#include <conio.h>

#include <Windows.h>
using namespace std;

using std::cout;//��������� ������������ ���� ��������� cout � ���������� �������
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");

	double a, b, c;
	char calc, quit;

	do {
		system("cls");
		cout << "\t***��������� �� ������� ���������� ���������***" << endl << endl;

		cout << endl << "���������� ����������?(y/n)" << endl;
		cin >> calc;

		cout << "������� a, b � c: (�� �������)" << endl << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "c: ";
		cin >> c;

		//calculate D
		double d = (b * b) - (4 * a * c);
		if (calc == 'y') {
			cout << endl << "��������� ������������: \n" << "D = b^2 - 4ac = " << b << "^2 - 4 * " << a << " * " << c;
			cout << " = " << b * b << " - " << 4 * a * c << " = " << d << endl;
		}

		if (d == 0) {
			double x1 = (-b) / (2 * a);
			if (calc == 'y')
				cout << "��������� ������: \n" << "x1 = (-b + ������(d)) / 2a = (- " << b << " + " << sqrt(d) << ") / " << 2 * a << " = " << x1 << endl;
			cout << endl << "* ������������ ����� " << d << endl;
			cout << "* ������ ����� " << x1 << endl;
		}
		else if (d > 0) {
			double x1 = (-b + sqrt(d)) / (2 * a);
			double x2 = (-b - sqrt(d)) / (2 * a);
			if (calc == 'y') {
				cout << "��������� �����: \n" << "x1 = (-b + ������(d)) / 2a = (- " << b << " + " << sqrt(d) << ") / " << 2 * a << " = " << x1 << endl;
				cout << "x2 = (-b - ������(d)) / 2a = (- " << b << " - " << sqrt(d) << ") / " << 2 * a << " = " << x2 << endl << endl;
			}

			cout << endl << "* ������������ ����� " << d << endl;
			cout << "* ������ ������ ����� " << x1 << endl;
			cout << "* ������ ������ ����� " << x2 << endl;
		}
		else {
			cout << endl << "* ��� �������" << endl;
		};

		cout << endl << "������ ������ �����?(y/n)" << endl;

	} while (cin >> quit && quit == 'y');
}