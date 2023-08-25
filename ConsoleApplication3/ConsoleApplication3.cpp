#include <iostream>
#include <string>


using namespace std;

class Human {
public:
	int age;
	int weight;
	string name;

	void Print() {
		cout << "Name: " << name << endl;;
		cout << "Weight: " << weight << endl;
		cout << "Age: " << age << endl;
	}
};

class Test;

class Point {
private:
	int x;
	int y;

public:
	Point() {
		x = 0;
		y = 0;
		cout << this << endl;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
		cout << this << endl;
	}

	bool operator == (const Point& other) {
		return this->x == other.x && this->y == other.y;

	}

	bool operator != (const Point& other) {
		return !(this->x == other.x && this->y == other.y);

	}

	//void setX(int x) {
	//	this->x = x;
	//}
	int getX() {
		return x;
	}
	//void setY(int y) {
	//	this->y = y;
	//}
	int getY() {
		return y;
	}
	void Print() {
		cout << "X = " << x << "\t Y = " << y << endl << endl;
	}

	Point & operator ++() {
		this->x++;
		this->y+=1;
		return *this;
	}
	Point& operator ++(int value) {
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}

	Point operator +(const Point& other) {
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	friend void ChangeX(Point& value, Test& testvalue);
};


class CoffeeGrinder {
private:

	bool CheckVoltage() {
		return false;
	}

public:

	void Start() {
		bool voltageIsNormal = CheckVoltage();
		voltageIsNormal ? cout << "VjuHHHHH!" << endl : cout << "BEEP BEEP" << endl;

	}
};

class TestClass
{
public:
	int& operator[](int index){
		return arr[index];
	}

private:
	int arr[5]{ 5,33,3,45,2 };
};



class MyClass {
	int* data;
public:
	MyClass(int size) {
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Constructor " << this << endl;
	}

	MyClass(const MyClass& other) {
		this->size = other.size;
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++) {
			this->data[i] = other.data[i];
		}
		cout << "Copy Constructor " << this << endl;
	}

	MyClass& operator = (const MyClass& other) {
		cout << "Call equal operator" << this << endl;
		this->size = other.size;
		if (this->data != nullptr) {
			delete[] this->data;
		}
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++) {
			this->data[i] = other.data[i];
		}

		return *this;

	}

	~MyClass() {
		cout << "Destructor " << this << endl;
		delete[] data;
	}


private:
	int size;
};

void Foo(MyClass value) {
	cout << "Call function FOO" << endl;
}

MyClass Foo2() {
	cout << "call function Foo2" << endl;
	MyClass temp(2);

	return temp;
}

class Test {
private: int data = 0;
	   friend void ChangeX(Point& value, Test& testvalue);
};

void ChangeX(Point& value, Test &testvalue) {
	value.x = -1;
	testvalue.data = -1;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	Test test;
	Point a(5, 12);
	a.Print();
	ChangeX(a, test);
	a.Print();
}




