#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

using namespace std;

//таблица для самой игры
char table[3][3];
//переменная - чей ход
bool turn;
//имена игроков
char player1[30],
	 player2[30];

void instructions();
bool input();
bool win();

int main() {
	setlocale(LC_ALL, "Russian");

	//вывод инструкций
	instructions();
	system("cls");

	int i = 0;

	cout << "Введите имя 1 игрока: ";
	cin.getline(player1, 30);
	cout << "Введите имя 2 игрока: ";
	cin.getline(player2, 30);

	//рандомно определяет чей ход
	srand(time(NULL));
	if (rand() & 1)
		turn = true; //ход 2 игрока
	else turn = false; //ход 1 игрока

	//пока никто не выиграл, очищается экран
	//и если ввод вернул неудачу, выводит ошибку
	while (!win()) {
		system("cls");
		//если число ходов равно 9, то объявляется ничья
		if (i == 9) {
			cout << "Ничья!";
			_getch();
			return -1;
		}
		if (!input()) {
			cout << "Ваш ввод недопустим! Нажмите любую клавишу, чтобы продолжить";
			_getch();
		}
		i++;
	}

	system("cls");
	
	if (turn)
		cout << "Победил " << player2 << endl;
	else cout << "Победил " << player1 << endl;

	_getch();
	return 0;
}

void instructions() {
	cout << "--- Крестики-нолики ---" << endl;
	cout << "Вид поля:" << endl;

	//вывод таблицы
	int l = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << l + 1 << ' ';
			table[i][j] = char(49 + l);
			l++;
		}
		cout << '|' << endl;
	}

	cout << "Для хода нажмите цифру ячейки поля." << endl;
	cout << "Для начала игры нажмите любую клавишу" << endl;
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
		cout << "Ходит " << player1 << " : ";
	else cout << "Ходит " << player2 << " : ";

	//переменная для введенной игроком цифры
	int n;
	cin >> n;

	if (n < 1 || n > 9)
		return false;
	int i, j;

	if (n % 3 == 0) { //то есть если это 3, 6 или 9
		i = n / 3 - 1; //6 / 3 - 1 = 1 ряд (то есть 2)
		j = 2; //и все время последний столбец
	}
	else {
		i = n / 3; //например, 7 => 7 / 3 = 2 ряд (то есть третий)
		j = n % 3 - 1; //7 % 3 - 1 = 0 столбец
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
