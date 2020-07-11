#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

using namespace std;

//������� ��� ����� ����
char table[3][3];
//���������� - ��� ���
bool turn;
//����� �������
char player1[30],
	 player2[30];

void instructions();
bool input();
bool win();

int main() {
	setlocale(LC_ALL, "Russian");

	//����� ����������
	instructions();
	system("cls");

	int i = 0;

	cout << "������� ��� 1 ������: ";
	cin.getline(player1, 30);
	cout << "������� ��� 2 ������: ";
	cin.getline(player2, 30);

	//�������� ���������� ��� ���
	srand(time(NULL));
	if (rand() & 1)
		turn = true; //��� 2 ������
	else turn = false; //��� 1 ������

	//���� ����� �� �������, ��������� �����
	//� ���� ���� ������ �������, ������� ������
	while (!win()) {
		system("cls");
		//���� ����� ����� ����� 9, �� ����������� �����
		if (i == 9) {
			cout << "�����!";
			_getch();
			return -1;
		}
		if (!input()) {
			cout << "��� ���� ����������! ������� ����� �������, ����� ����������";
			_getch();
		}
		i++;
	}

	system("cls");
	
	if (turn)
		cout << "������� " << player2 << endl;
	else cout << "������� " << player1 << endl;

	_getch();
	return 0;
}

void instructions() {
	cout << "--- ��������-������ ---" << endl;
	cout << "��� ����:" << endl;

	//����� �������
	int l = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << l + 1 << ' ';
			table[i][j] = char(49 + l);
			l++;
		}
		cout << '|' << endl;
	}

	cout << "��� ���� ������� ����� ������ ����." << endl;
	cout << "��� ������ ���� ������� ����� �������" << endl;
	_getch();
}

bool input() {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << table[i][j] << ' ';
		}
		cout << '|' << endl;
	}

	cout << endl;

	if (turn)
		cout << "����� " << player1 << " : ";
	else cout << "����� " << player2 << " : ";

	//���������� ��� ��������� ������� �����
	int n;
	cin >> n;

	if (n < 1 || n > 9)
		return false;
	int i, j;

	if (n % 3 == 0) { //�� ���� ���� ��� 3, 6 ��� 9
		i = n / 3 - 1; //6 / 3 - 1 = 1 ��� (�� ���� 2)
		j = 2; //� ��� ����� ��������� �������
	}
	else {
		i = n / 3; //��������, 7 => 7 / 3 = 2 ��� (�� ���� ������)
		j = n % 3 - 1; //7 % 3 - 1 = 0 �������
	}

	if (table[i][j] == '0' || table[i][j] == 'X')
		return false;

	if (turn) {
		table[i][j] = 'X';
		turn = false;
	}
	else {
		table[i][j] = '0';
		turn = true;
	}
	return true;

}
bool win() {
	for (int i = 0; i < 3; i++) {
		if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2])) {
			return true;
		}
		else if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i])) {
			return true;
		}
		else if (((table[0][0] == table[1][1]) && (table[0][0] == table[2][2])) || ((table[0][2] == table[1][1]) && (table[0][2] == table[2][0]))) {
			return true;
		}
	}
	return false;
}
