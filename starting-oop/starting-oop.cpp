#include <iostream>
#include <string>

using namespace std;

class Person {

private:
	int age;
	string name;

public:	

	Person() { //�����������
		name = "Default name"; 
		age = 0;
	}
	Person(string name, int age) { //���������� ������������
		this->age = age;
		this->name = name;
	}

	//����������� �����������
	//(����� ����� ��������� ������� ������������ ������)
	Person(const Person &other) {
		//...
	}
	
	// ���������� ��������� ���������
	bool operator == (const Person & other) {
		return this->age == other.age && this->name == other.name;
	}

	// ���������� ��������� �����������
	bool operator != (const Person& other) {
		return !(this->age == other.age && this->name == other.name);
	}

	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	void output() {
		cout << "name: " << name << endl
			<< "age: " << age << endl;
	}
};

class Point
{
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		setX(x);
		setY(y);
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void print() {
		cout << this << endl;
		cout << "---" << endl;
		cout << "x: " << x << endl;
		cout << "y: " << y << endl << endl;
	}

	Point operator +(const Point &other) {
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	//���������� �����
	Point & operator ++() {
		this->x++;
		this->y++;

		return *this;
	}

	//����������� �����
	Point& operator ++(int value) {
		Point temp(*this);

		this->x++;
		this->y++;

		return temp;
	}

	friend void changeX(Point& value);

private:
	int x;
	int y;
};

class ArrClass
{
public:
	int& operator[](int index) {
		return arr[index];
	}
private:
	int arr[5]{ 5, 6, 7, 8, 9 };
};

//������������� ������� ��� ������ �����
void changeX(Point &value) {
	value.x = -1;
}

int main() {

	/*
	Person a("Masha", 15);
	Person b;

	a.output();
	b.output();
	*/

	/*
	Point a(3, 5);
	Point b(1, 2);

	a.print();
	b.print();

	Point c = a + b;
	c.print();

	
	++a;
	a.print();
	a++;
	a.print();
	*/
}