#include "dynamicArray.h"
#include <stdexcept>
#include <algorithm>
using namespace std;


DynamicArray::DynamicArray()
{
	if (capacite == 0) throw std::invalid_argument("la capaciter doit être supérieur à 0");
	tabElement = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(unsigned int _capacite) // constructeur avec parametre
{
	if (_capacite == 0) throw std::invalid_argument("la capaciter doit être supérieur à 0");
	capacite = _capacite;
	tabElement = new int[capacite];
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray& _source) // constructeur de copie
	:capacite(_source.capacite),
	tabElement(new int[capacite])
{
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElement[i] = _source.tabElement[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] tabElement;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &_source) // operateur =
{
	if (&_source != this)
	{
		delete[] tabElement;
		capacite = _source.capacite;
		tabElement = new int[capacite];
		for (unsigned int i = 0; i < capacite; i++)
		{
			tabElement[i] = _source.tabElement[i];
		}
	}
	return *this;
}

int DynamicArray::getCapacite() const
{
	return capacite;
}

void DynamicArray::setCapacite(unsigned int nouvelle_capacite)
{
	if (nouvelle_capacite < 1) throw std::invalid_argument("la capaciter de ne peut être inférieure à 1");
	int * tabTemporaire = new int[nouvelle_capacite];
	for (unsigned int i = 0; i < min(capacite,nouvelle_capacite); i++)
	{
		tabTemporaire[i] = tabElement[i];
	} 
	for (unsigned int i = capacite; i < nouvelle_capacite; i++)
	{
		tabTemporaire[i] = 0;
	}
	capacite = nouvelle_capacite;
	delete[] tabElement;
	tabElement = tabTemporaire;
}

int DynamicArray::getElement(unsigned int i) const
{
	if (i > capacite) throw std::out_of_range("out of range");
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

bool DynamicArray::operator==(const DynamicArray &_source)
{
	if (_source.tabElement[capacite] == this->tabElement[capacite])
	{
		return true;
	}
	else
	{
		return false;
	}
}