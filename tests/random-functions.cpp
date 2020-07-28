#include <iostream>
#include <conio.h>
using namespace std;

//factorial function
int factorial(int n) {
	//n! = n * (n-1)!

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return n * factorial(n - 1);
}

//template function that swaps two values
template <typename T> 
void myswap(T &first, T &second) {
	T temp = first;
	first = second;
	second = temp;
}


int main() {





	_getch();
}