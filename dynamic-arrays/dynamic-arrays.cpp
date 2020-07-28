#include <iostream>
#include <conio.h>
using namespace std;

void fillArr(int* const arr, int const size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void showArr(const int* const arr, int const size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void push_back(int *&arr, int &size, const int value) {

	//making new array with one more slot
	int* newArray = new int[size + 1];

	//transfering all existing values
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	//adding the element
	newArray[size] = value;
	//size is now larger
	size++;

	//deleting the old array
	delete[] arr;

	//now a pointer should point to a new array
	arr = newArray;
}

int main() {



	//	--- Dynamic memory allocation and its removal ---
	int* var = new int;
	*var = 10;

	//	Deleting the data
	delete var;
	var = nullptr;

	//-------------------------------------

	//	--- Dynamic arrays ---
	int size = 10;
	int* arr1 = new int[size];

	//	Deleting the data

	delete[] arr1;

	//-------------------------------------

	//	--- Dynamic 2d array ---

	int rows = 5;
	int cols = 5;

	int** arr2 = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr2[i] = new int[cols];
	}

	//	Deleting the data

	for (int i = 0; i < rows; i++) {
		delete[] arr2[i];
	}

	delete[] arr2;

	//-------------------------------------
	//-------------------------------------

	//	--- Copying a dynamic array ---

	int firstSize = 10;
	int secondSize = 5;

	//copying firstArr to secondArr
	int* firstArr = new int[firstSize];
	int* secondArr = new int[secondSize];

	fillArr(firstArr, firstSize);
	fillArr(secondArr, secondSize);

	//showArr(firstArr, firstSize);
	//cout << endl;
	//showArr(secondArr, secondSize);

	//1. delete data from arr1
	delete[] secondArr;

	//2. make enough space in arr2
	secondArr = new int[firstSize];

	//3. copy with a loop
	for (int i = 0; i < firstSize; i++)
	{
		secondArr[i] = firstArr[i];
	}

	//cout << endl << endl << "Whoosh!" << endl << endl;

	//showArr(firstArr, firstSize);
	//cout << endl;
	//showArr(secondArr, firstSize);

	delete[] firstArr;
	delete[] secondArr;

	//-------------------------------------

	//	--- Adding an element to the end of the array ---

	int Size = 5;
	int* Arr = new int[Size];
	fillArr(Arr, Size);

	showArr(Arr, Size);
	cout << endl << endl << "Whoosh!" << endl << endl;
	push_back(Arr, Size, 25);
	showArr(Arr, Size+1);


	delete[] Arr;

	_getch();
}


