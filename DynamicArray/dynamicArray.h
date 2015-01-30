#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(const int &_capacite);
	~DynamicArray(void);
	int getCapacite();
	void setCapacite(const int nouvelle_capacite);
	int getElement(int i);
	void setElement(const int index_element, const int nouvelle_valeur_element);


private:

	int capacite;
	int* tabElement;
};


#endif //DYNAMICARRAY_H_