#include "dynamicArray.h"
#include <stdexcept>
#include <algorithm>
using namespace std;


DynamicArray::DynamicArray()
{
	if (capacite == 0) throw std::invalid_argument("la capaciter est de zero");
	tabElement = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(unsigned int _capacite)
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

int DynamicArray::getCapacite() const
{
	return capacite;
}

void DynamicArray::setCapacite(unsigned int nouvelle_capacite)
{
	int * tabTemporaire = new int[nouvelle_capacite];
	for (int i = 0; i < min(capacite,nouvelle_capacite); i++)
	{
		tabTemporaire[i] = tabElement[i];
	} 
	for (int i = capacite; i < nouvelle_capacite; i++)
	{
		tabTemporaire[i] = 0;
	}
	capacite = nouvelle_capacite;
	delete[] tabElement;
	tabElement = tabTemporaire;
}

int DynamicArray::getElement(unsigned int i) const
{
	if (i >= capacite) throw std::out_of_range("out of range");
	return tabElement[i];
}

void DynamicArray::setElement(unsigned int index_element,  int nouvelle_valeur_element)
{
	if (index_element > capacite)
	{
		setCapacite(index_element + 1);
	}
	tabElement[index_element] = nouvelle_valeur_element;
}