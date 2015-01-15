#include "sheet14.h"
#include<stdio.h>
#include <stdlib.h>

struct DynArr
{
	TYPE *data; /* pointer to the data array */
	int size; /* Number of elements in the array */
	int capacity; /* capacity ofthe array */
};

void initDynArr(struct DynArr *v, int capacity)
{
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

void freeDynArr(struct DynArr *v)
{
	if(v->data != 0){
		free(v->data); /* free the space on the heap */
		v->data = 0; /* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

int sizeDynArr( struct DynArr *v)
{
	return v->size;
}

void addDynArr(struct DynArr *v, TYPE val)
{
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_setCapacityDynArr(v, 2 * v->capacity);
	v->data[v->size] = val;
	v->size++;
}

void _setCapacityDynArr(struct DynArr *v, int newCap)
{
	TYPE *new_data = malloc(sizeof(TYPE) * newCap);
	assert(new_data != 0);

	int i;
	for(i = 0; i < v->size; i++)
		new_data[i] = v->data[i]; 
        
	if(v->data != 0){
                free(v->data); /* free the space on the heap */
                v->data = 0; /* make it point to null */
        }

	v->capacity = newCap;
	v->data = new_data;
}

TYPE getDynArr (struct DynArr * da, int position) {
	assert(position >= 0 && position < da->size);
	return da->data[position];
}

void putDynArr(struct DynArr * da, int position, TYPE value) {
	assert(position >= 0 && position < da->size);
	da->data[position] = value;

}

void swapDynArr (struct DynArr * da, int i, int j) {
	assert(i >= 0 && i < da->size);
	assert(j >= 0 && j < da->size);
	TYPE temp = da->data[i];
	da->data[i] = da->data[j];
	da->data[j] = temp;
}

void removeAtDynArr (struct DynArr * da, int index) {
	assert(index >= 0 && index < da->size);
        int i;
        for(i = index; i < da->size - 1; i++)
		da->data[i] = da->data[i + 1];
        da->size--;
}

