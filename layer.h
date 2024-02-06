#include <iostream>
#define LAYER_H

#include "shape.h"
#include "vector.h"

#define INITIALISE -1
#define INACTIVE 0
#define ACTIVE 1

class Layer
{
public:
	Layer();
	virtual ~Layer();

	double totalArea();
	bool translate(int x2, int y2);

	bool reset();
	// void printLayer();

	Shape* getElement(int index);
	Shape* removeElement(int index);
	bool addElement(Shape* element);

	bool changeState(int state);
	int getState();

	int getSize();

private:
	Vector<Shape> vector;
	int state;
};

Layer::Layer()
{
	state = INITIALISE;
}

Layer::~Layer() {}

double Layer::totalArea()
{
	float totalArea = 0;

	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr)
		{
			totalArea += vector[i]->area();
		}
	}

	return totalArea;
}

bool Layer::translate(int x2, int y2)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr)
		{
			// TODO: Fix this
			// vector[i]->translate(x2, y2);
		}
	}

	return true;
}

bool Layer::reset()
{
	vector.purge();

	state = INITIALISE;

	return true;
}

/*
void Layer::printLayer()
{
	if (vector.isEmpty()) std::cout << "Couche: vide" << std::endl;

	for (int i = 0; i < vector.getCapacity(); i++)
	{
		if (vector[i] != nullptr) std::cout << "Element [" << i << "] : " << vector[i]->printTo() << std::endl;
		else std::cout << "Element [" << i << "] : vide" << std::endl;
	}
}
*/

int Layer::getState() { return state; }

Shape* Layer::getElement(int index) { return vector[index]; }

bool Layer::addElement(Shape* element)
{
	vector += element;
	return true;
}

Shape* Layer::removeElement(int index)
{
	return vector.removeElement(index);
}

bool Layer::changeState(int new_state)
{
	state = new_state;
	return true;
}

int Layer::getSize() { return vector.getSize(); }