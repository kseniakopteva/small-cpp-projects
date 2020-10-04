#include <iostream>
using namespace std;

// �� ��������

class String {
public:

	//����������� ��� ����������
	String() {
		str = nullptr;
		length = 0;
	}
	
	//�������� ������
	String(const char *str) {
		length = strlen(str);

		this->str = new char[length+1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}

	//����������
	~String() {
		delete[] this->str;
	}

	//����������� �����������
	String(const String& other) {

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

	}

	//���������� ��������� ������������
	String& operator =(const String &other) {
		if (this->str != nullptr) {
			delete[] str;
		}

		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	//���������� ��������� �������� (������������)
	String & operator +(const String& other) {
		String newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		//newStr.str[i] = '\0';
		newStr.str[thisLength + otherLength] = '\0';

		return newStr;

	}

	void Print() {
		cout << str << endl;
	}

	int Length() {
		return length;
	}

private:
	char* str;
	int length;
};


int main() {

	String str("test");
	String str2("-test-");
	
	String result;
	result = str + str2;

	return 0;
}