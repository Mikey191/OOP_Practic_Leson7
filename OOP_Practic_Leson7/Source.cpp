//Самолеты

#include <iostream>
using namespace std;

class Airplane
{
private:
	char name[20];
	char type[20];
	int countPeople;
public:
	Airplane(const char* name,const char* type, int countPeople)
	{
		strcpy_s(this->name, 20, name);
		strcpy_s(this->type, 20, name);
		this->countPeople = countPeople;
	}
	Airplane() : Airplane (" ", " " , 0) {}
	bool operator==(Airplane& a) 
	{ 
		if (strcmp(this->type, a.type) == 0)
			return 1;
		else
			return 0;
	}
	Airplane(const Airplane& a)//конструктор копирования
	{
		strcpy_s(this->name, 20, a.name);
		strcpy_s(this->type, 20, a.type);
		this->countPeople = a.countPeople;
	}
	Airplane operator++() { return Airplane(name, type, ++countPeople); }
	Airplane operator--() { return Airplane(name, type, --countPeople); }
	friend void operator>(Airplane& c1, Airplane& c2);
	//friend bool operator>(Airplane& c1, Airplane& c2);
	bool operator>(Airplane& a) { return this->countPeople > a.countPeople; }
	void print() { cout << "Name: " << name << "\nType: " << type << "\nCapacity: " << countPeople << endl; }
};

void operator>(Airplane& c1, Airplane& c2)
{
	if (c1.countPeople > c2.countPeople)
		cout << "Capacity Air " << c1.name << " bigger capacity Air " << c2.name << endl;
	else if (c2.countPeople > c1.countPeople)
		cout << "Capacity Air " << c2.name << " bigger capacity Air " << c1.name << endl;
	else
		cout << "Capacity is equal" << endl;
}

int main()
{
	Airplane a1("Air1", "type1", 100);
	a1.print();
	Airplane a2("Air2", "type2", 200);
	a2.print();
	Airplane a3(a1);
	a3.print();
	++a3;
	a3.print();
	--a3;
	a3.print();
	bool t;
	t = a2 > a3;

	return 0;
}