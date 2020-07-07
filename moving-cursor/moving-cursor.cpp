//custom cursor moves on WASD

#include <iostream>
#include <cstring>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
	char str[100];
	char c = '~', c1;
	int index = 0;
	int index2 = 0;

	do {
		c1 = _getch();
		system("cls");

		if (toupper(c1) == 'W') {
			index2--;
		}
		if (toupper(c1) == 'S') {
			index2++;
		}

		if (toupper(c1) == 'D') {
			for (int i = 0; i <= index; i++) {
				if (i != index)
					str[i] = ' ';
				else str[i] = c;
			}
			str[index + 1] = '\0';
			index++;
		}

		if (toupper(c1) == 'A') {
			for (int i = 0; i < index; i++) {
				if (i != index - 1)
					str[i] = ' ';
				else str[i] = c;
			}
			str[index] = '\0';
			index--;
		}

		for (int i(0); i < index2; i++)
		{
			cout << endl;
		}

		cout << str;
	} while (c1 != 'q');

}