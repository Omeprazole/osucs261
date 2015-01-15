struct DynArr {
	TYPE * data;
	int size;
	int capacity;
};

void removeDynArr (struct DynArr * dy, TYPE test) {
	int i;
	for (i = 0; i < dy->size; i++) {
		if (EQ(test, dy->data[i])) { /* found it */
			_dynArrayRemoveAt(dy, i);
			return;
		}
	}
}

/* the following were written in earlier lessons */
void initDynArr (struct DynArr * da, int initCap);
void addDynArr(struct DynArr * da, TYPE e);

/* you must write the following */
int containsDynArr (struct DynArr * da, TYPE e) {
        int i;
        for(i = 0; i < da->size; i++){
                if(EQ(data[da->size], e))
                        return i;
        }
        return -1;
}
