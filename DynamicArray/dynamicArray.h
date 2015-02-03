#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	~DynamicArray();
	int getCapacite() const ;
	void setCapacite(unsigned int nouvelle_capacite);
	int getElement(unsigned int i) const;
	void setElement(unsigned int index_element, int nouvelle_valeur_element);


private:

	unsigned int capacite = 100;
	int* tabElement;
};


#endif //DYNAMICARRAY_H_