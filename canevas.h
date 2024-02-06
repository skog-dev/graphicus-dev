

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
	Canevas();
	~Canevas();

	bool reset();
	bool resetLayer(int index);

	bool enableLayer(int index);
	bool disableLayer(int index);

	bool addElement(int *element);
	bool removeElement(int index);

	double area();
	bool translate(int deltaX, int deltaY);
	void printTo(ostream &s);

	Vector<Couche<int>> couches;
private:
	
};

Canevas::Canevas()
{
	couches += new Couche<int>();
	couches += new Couche<int>();
	couches += new Couche<int>();

	couches[0]->changeState(ACTIVE);
}

Canevas::~Canevas()
{
}

bool Canevas::reset()
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		couches[i]->reset();
	}

	couches[0]->changeState(ACTIVE);

	return true;
}

bool Canevas::resetLayer(int index)
{

	if (index < 0 || index > couches.getSize() - 1) { return false; }

	if (couches[index]->getState() != ACTIVE) { couches[index]->reset(); }

	else
	{
		couches[index]->reset();
		couches[index]->changeState(ACTIVE);
	}

	return true;
}

bool Canevas::enableLayer(int index)
{
	if (index < 0 || index > couches.getSize() - 1) { return false; }

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			if (index == i) { return true; }

			couches[i]->changeState(INACTIVE);
			break;
		}
	}

	couches[index]->changeState(ACTIVE);

	return true;
}

bool Canevas::disableLayer(int index)
{
	if (index < 0 || index > couches.getSize() - 1) { return false; }

	if (couches[index]->getState() == ACTIVE) { couches[index]->changeState(INACTIVE); }

	return true;
}

bool Canevas::addElement(int *element)
{
	if (element == NULL) { return false; }

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			couches[i]->addElement(element);
			break;
		}

		if (i == MAX_COUCHES - 1) { return false; }
	}

	return true;
}

bool Canevas::removeElement(int index)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			if (couches[index] == nullptr)
			{
				return false;
			}
			couches[i]->removeElement(index);
			break;
		}

		if (i == MAX_COUCHES - 1)
		{
			return false;
		}
	}
	return true;
}

double Canevas::area()
{
	float totalArea = 0;

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() != INITIALISE) { totalArea += couches[i]->totalArea(); }
	}

	return totalArea;
}

bool Canevas::translate(int deltaX, int deltaY)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE) { couches[i]->translate(deltaX, deltaY); }

		if (i == couches.getSize() - 1) { return false; }
	}

	return true;
}

void Canevas::printTo(ostream &s)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		cout << "----- Couche " << i << " -----" << endl;
		cout << "État: " << couches[i]->getState() << endl;

		if (couches[i]->getState() == INITIALISE) { cout << "Initialisée" << endl; }

		if (couches[i]->getState() == ACTIVE) { cout << "Active" << endl; }

		if (couches[i]->getState() == INACTIVE) { cout << "Inactive" << endl; }

		couches[i]->printLayer();
	}

	cout << endl;
}


#endif
