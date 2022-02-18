#include <iostream>
#include <string>
using namespace std;

class Point
{
	int x, y;
public:
	Point() {
		x = 0; y = 0;
	}
	Point(int x, int y) { 
		this->x = 0; this->y = y; // To distinguish data members 
	}
	void Display() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	Point setX(int x) { // We can delete &. Point setX(int x) and Point& setX(int x) no difference.
		this->x = x;
		//cout << this << endl; // Memory address will be printed.
		//cout << *this << endl;// Gives an error.
		return *this; //Gives Error if we remove it. returning an object p!
	}
	Point setY(int y) {
		this->y = y;
		return *this;
	}
};

class Human
{
private:
	int* age;
	string* name;
public:
	Human() { age = 0; name = NULL; } // ~ giving memory address ~ // error if *age=0, *name="asdf"
	//Human() { age = new int(0); name = new string("johnny"); } // works!
	Human(int a, string n) { age = new int(a); name = new string(n); }

	void SetHuman(int a, string n) {
		age = new int(a); 
		name = new string(n);
	}

	void Display() {
		cout << *age << endl;
		cout << *name << endl;
	}
};

class Humann
{
	int age;
	string name;
public:
	Humann(int age=0, string name=" ")
	{
		this->age = age;
		this->name = name;
	}
	void sethuman(int a, string n)//const error
	{
		age = a;
		name = n;
	}
	void Display()const
	{
		cout << age << endl << name << endl;
	}
};

class Birthday
{
private:
	int month, day, year;
public:
	/*Birthday()
	{

	}*/
	Birthday(int m, int d, int y) // or we can assign values int m=0, int d=0, int y=0
	{
		month = m;
		day = d;
		year = y;
	}
	void display() {
		cout << year << " " << month << " " << day << endl;
	}
};

class Employee
{
private:
	string name;
	Birthday dob; // this what composition means
public:
	Employee(string n, Birthday b):name(n), dob(b)
	{
		/*name = n;
		dob = b;*/
	}
	void printemp() {
		cout << "I am " << name << endl;
		dob.display();
	}
};

int main()
{
	// ----------this pointer---------
	//Point p(2, 3);
	//p.setX(5);
	//p.setY(15);
	//p.Display();

	//p.setX(5).setY(15);//method chaining.
	//p.Display();

	// Dynamic memory allocation using new and delete
	/*int* p;
	int pp;
	p = &pp;
	cout<<*p << endl;*/

	//int* ptr;
	//ptr = new int;//memory address from heap.
	//ptr = new int(15);//Assigning value. Shows the result if cout << *ptr; >>>15
	////cout << ptr << endl;//Shows the memory address
	////*ptr = 5;//Assigning value to ptr;
	////cin >> *ptr; or we can assign in that way too.

	//cout << *ptr << endl;//Shows the value
	//delete ptr;// putting asterisk(*) before ptr is error.
	////cout << ptr << endl;// Not Error, but shows some weird things.
	////cout << *ptr << endl; // Runtime Error

	/*int* p;
	int size;
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> *(p + i);
	}
	for (int i = 0; i < size; ++i)
	{
		cout << *(p + i) << "\t";
	}*/

	/*Human* h;
	h = new Human;*/
	//Human* h = new Human;//Human* h = new Human() also works.
	//Human* h = new Human(17, "pop")//also works
	//h->SetHuman(12, "abc");
	//h->Display();

	//Human* h = new Human[3];
	//int age;
	//string name;
	//for (int i = 0; i < 3; ++i)
	//{
	//	cout << "input smth:" << endl;
	//	cin >> age >> name;
	//	(h[i]).SetHuman(age, name);// is h list of lists?
	//}
	//for (int i = 0; i < 3; ++i)
	//{
	//	(h[i]).Display();
	//}

	/*Humann h;
	h.sethuman(12, "asd");
	h.Display();*/
	// h.SetHuman(2, "as"); //works fine

	//const Humann h1;
	//h1.sethuman(112, "aassd"); // error

	//const Humann h2(15, "xyz"); // works!
	//h2.Display();
	//const h2.humann;

	Birthday b(1, 1, 2003);
	Employee e("johnny", b);
	e.printemp();




	return 0;
}