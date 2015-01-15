/******************wroksheet0*************************************************/
#include "sheet0.h"
#include<stdio.h>

void initArray (struct arrayBagStack *b){
	b->count = 0;
}

/* Bag Interface Functions */
void addArray (struct arrayBagStack * b, TYPE v) {
	b->data[b->count] = v;
	b->count++;
}

/*return the index of v, if v doesn't exist, return -1*/
int containsArray (struct arrayBagStack * b, TYPE v){
	int i;
	for(i = 0; i < b->count; i++){
		if(b->data[i] == v)
			return i;
	}
	return -1;
}

void removeArray (struct arrayBagStack * b, TYPE v) {
	int index = containsArray(b, v);
	if(index >= 0){
		int i;
		for(i = index; i < b->count - 1; i++)
			b->data[i] = b->data[i + 1];
		b->count--;
	} else {
		printf("Failed to remove %d", v);
	}	
	
}

int sizeArray (struct arrayBagStack * b) {
	return b->count;
}

/* Stack Interface Functions */
void pushArray (struct arrayBagStack * b, TYPE v) {
        b->data[b->count] = v;
        b->count++;
}

TYPE topArray (struct arrayBagStack * b) {
	return b->data[b->count - 1];
}

void popArray (struct arrayBagStack * b) {
	if(b->count == 0)
		printf("Failed to pop");

	b->count--;
}

int isEmptyArray (struct arrayBagStack * b) {
	return b->count == 0;

}
