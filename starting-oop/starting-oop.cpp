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

int main() {

	Person a("Masha", 15);
	Person b;

	a.output();
	b.output();

	

}