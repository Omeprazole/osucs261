#include "sheet16.h"
#include<stdio.h>
#include <stdlib.h>

/* Dynamic Array implementation of the Stack Interface */
void pushDynArray (struct DynArr * da, TYPE e) {
        /* Check to see if a resize is necessary */
        if(da->size >= da->capacity)
                _setCapacityDynArr(da, 2 * da->capacity);
        da->data[da->size] = e;
        da->size++;
}

TYPE topDynArray (struct DynArr * da) {
        assert(da->size != 0);
        return da->data[da->size - 1];
}

void popDynArray (struct DynArr * da) {
	assert(da->size != 0);
	da->size--;
}
int isEmptyDynArray (struct DynArr * da) {
	return da->size == 0;
}
