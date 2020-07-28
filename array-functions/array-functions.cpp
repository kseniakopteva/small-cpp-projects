#include <iostream>
#include <conio.h>

using namespace std;

//bubblesort function
void bubbleSort(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				swap(arr[j], arr[i]);
			}
		}
	}
}

//attempt at strcat function
void addString(char string[], char stringTwo[], int firstStringSize, int secondStringSize) {
	//there is a string with a \0 at the end of it, and that's where we should put the next string...
	
	for (int i = 0; i < firstStringSize; i++) {
		if (string[i] == '\0') {
			for (int j = 0; j < secondStringSize; j++) {
				if (stringTwo[j] != '\0') {
					string[i] = 0;
					string[i] = stringTwo[j];
					i++;
				}
				else {
					string[i] = '\0';
					string[i] = stringTwo[j];
					break;
				}
			}
		}	
	}

	cout << string << endl;
}

int main() {

	char name[20];
	cin.getline(name, 20);

	char surname[10];
	cin.getline(surname, 10);

	addString(name, surname, 20, 10);

	_getch();
	return 0;
}