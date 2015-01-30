#include "dynamicArray.h"
using namespace std;


DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElement = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(const int& _capacite)
{
	capacite = _capacite;
	tabElement = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElement[i] = 0;
	}
}

DynamicArray::~DynamicArray()
{
	delete[] tabElement;
}

int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setCapacite(const int nouvelle_capacite)
{
	int * tabTemporaire = new int[nouvelle_capacite];
	for (int i = 0; i < nouvelle_capacite; i++)
	{
		tabTemporaire[i] = tabElement[i];
	}
}

int DynamicArray::getElement(int i)
{
	return tabElement[i];
}

void DynamicArray::setElement(const int index_element, const int nouvelle_valeur_element)
{
	tabElement[index_element] = nouvelle_valeur_element;
}