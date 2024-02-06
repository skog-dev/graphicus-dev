#include <iostream>
#define COUCHE_H

#include "vector.h"

#define INITIALISE -1
#define INACTIVE 0
#define ACTIVE 1

template <class O>
class Couche
{
public:
	Couche();
	virtual ~Couche();

	double totalArea();
	bool translate(int x2, int y2);
	
	bool reset();
	void printLayer();

	O *getElement(int index);
	O *removeElement(int index);
	bool addElement(O *element);

	bool changeState(int state);
	int getState();

private:
	Vector<O> vector;
	int *state;
};

template <class O>
Couche<O>::Couche()
{
	state = new int;
	*state = INITIALISE;
}

template <class O>
Couche<O>::~Couche() { delete state; }

template <class O>
double Couche<O>::totalArea()
{
	float totalArea = 0;

	for (int i = 0; i < vector.getTaille(); i++)
	{
		if (vector[i] != nullptr)
		{
			totalArea += vector[i]->aire();
		}
	}

	return totalArea;
}

template <class O>
bool Couche<O>::translate(int x2, int y2)
{
	for (int i = 0; i < vector.getTaille(); i++)
	{
		if (vector[i] != nullptr)
		{
			vector[i]->translater(x2, y2);
		}
	}

	return true;
}

template <class O>
bool Couche<O>::reset()
{
	vector.purge();

	*state = INITIALISE;

	return true;
}


template <class O>
void Couche<O>::printLayer()
{
	if (vector.isEmpty()) std::cout << "Couche: vide" << std::endl;

	for (int i = 0; i < vector.getCapacity(); i++)
	{
		if (vector[i] != nullptr) std::cout << "Element [" << i << "] : " << *vector[i] << std::endl;
		else std::cout << "Element [" << i << "] : vide" << std::endl;
	}
}

template <class O>
int Couche<O>::getState() { return *state; }

template <class O>
O *Couche<O>::getElement(int index) { return vector[index]; }

template <class O>
bool Couche<O>::addElement(O *element)
{
	vector += element;
	return true;
}

template <class O>
O *Couche<O>::removeElement(int index)
{
	return vector.removeElement(index);
}

template <class O>
bool Couche<O>::changeState(int new_state)
{
	state = new_state;
	return true;
}