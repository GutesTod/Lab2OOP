#include <iostream>
#include <Windows.h>

using namespace std;

class Backpack
{
public:
	Backpack()
	{
		max_weight = 100;
		weight = 20;
		loss_weight = max_weight - weight;
		cout << "Backpack()" << endl;
	};
	Backpack(int max_weighttmp, int weighttmp)
	{
		max_weight = max_weighttmp;
		weight = weighttmp;
		loss_weight = max_weight - weight;
		cout << "Backpack(int max_weighttmp, int weighttmp)" << endl;
	};
	Backpack(const Backpack& copybackpack)
	{
		max_weight = copybackpack.max_weight;
		weight = copybackpack.weight;
		cout << "Backpack(const Backpack& copybackpack)" << endl;
	};
	~Backpack()
	{
		cout << "~Backpack()" << endl;
	};
	void add_to_backpack(int weighttmp);
	void magic_in_backpack();

protected:
	int max_weight;
	int weight;
	int loss_weight;
};

void Backpack::add_to_backpack(int weighttmp)
{
	weight += weighttmp;
}

void Backpack::magic_in_backpack() 
{
	int tmp = loss_weight;
	loss_weight = weight;
	weight = tmp;
}

class MultiBackpack : public Backpack
{
public:
	MultiBackpack() : Backpack()
	{
		pockets = 4;
		cout << "MultiBackpack()" << endl;
	};
	MultiBackpack(int max_weighttmp, int weighttmp, int pocketstmp) : Backpack(max_weighttmp, weighttmp)
	{
		this->weight = weighttmp;
		this->pockets = pocketstmp;
		this->max_weight = max_weighttmp;
		loss_weight = (this->max_weight * pockets / 2) - weight;
		cout << "MultiBackpack(int max_weighttmp, int weighttmp, int pocketstmp)" << endl;
	};
	MultiBackpack(const MultiBackpack& copybackpack)
	{
		weight = copybackpack.weight;
		pockets = copybackpack.pockets;
		max_weight = copybackpack.max_weight;
		loss_weight = (this->max_weight * pockets / 2) - weight;
		cout << "MultiBackpack(const MultiBackpack& copybackpack)" << endl;
	};
	~MultiBackpack()
	{
		cout << "~MultiBackpack()" << endl;
	};
	void set_pockets(int pocketstmp);
protected:
	int pockets;
};

void MultiBackpack::set_pockets(int pocketstmp)
{
	pockets = pocketstmp;
}

class Many_backpacks
{
public:
	Many_backpacks() 
	{
		cout << "Many_backpacks()" << endl;
		b1 = new Backpack;
		b2 = new Backpack;
		b3 = new Backpack;
	};
	Many_backpacks(int max_weighttmp, int weighttmp)
	{
		cout << "Many_backpacks(int max_weighttmp, int weighttmp)" << endl;
		b1 = new Backpack(max_weighttmp, weighttmp);
		b2 = new Backpack(max_weighttmp, weighttmp);
		b3 = new Backpack(max_weighttmp, weighttmp);
	};
	Many_backpacks(const Many_backpacks& copybackpack)
	{
		cout << "Many_backpacks(const Many_backpacks& copybackpack)" << endl;
		b1 = new Backpack(*(copybackpack.b1));
		b2 = new Backpack(*(copybackpack.b2));
		b3 = new Backpack(*(copybackpack.b3));
	};
	~Many_backpacks() 
	{
		cout << "~Many_backpacks()" << endl;
		delete b1;
		delete b2;
		delete b3;
	};

protected:
	Backpack* b1;
	Backpack* b2;
	Backpack* b3;
};

int main()
{
	setlocale(LC_ALL, "");
	cout << "Создание обычного классов разными конструкторами" << endl;
	Backpack* b = new Backpack;
	Backpack* b1 = new Backpack(1000, 5);
	Backpack* b2 = new Backpack(*b1);
	system("pause");
	system("cls");
	cout << "Создание дочернего классов разными конструкторами" << endl;
	MultiBackpack* mb = new MultiBackpack;
	MultiBackpack* mb1 = new MultiBackpack(1000, 500, 20);
	MultiBackpack* mb2 = new MultiBackpack(*mb1);
	system("pause");
	system("cls");
	cout << "Создание классов разными конструкторами методом композиции" << endl;
	Many_backpacks* a = new Many_backpacks;
	Many_backpacks* a1 = new Many_backpacks(*a);
	system("pause");
	system("cls");
	delete b;
	delete b1;
	delete b2;
	delete mb;
	delete mb1;
	delete mb2;
	delete a;
	delete a1;
	return 0;
}