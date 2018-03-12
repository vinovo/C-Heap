#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

/* Your Heap implementation here */

void swap(Heap* h, int index1, int index2) {
	Pair temp = h->elements[index1];
	h->elements[index1] = h->elements[index2];
	h->elements[index2] = temp;
}

void expandCapacity(Heap* h) {
	h->capacity *= 2;
	Pair* elements = malloc(sizeof(Pair) * h->capacity);
	int i;
	for (i = 0; i < h->size; i++){
		elements[i] = h->elements[i];
	}
	h->elements = elements;
/*	Heap* newHeap = malloc(sizeof(Heap));
	newHeap->capacity = h->capacity * 2;
	newHeap->size = h->size;
	newHeap->elements = malloc(sizeof(Pair) * newHeap->capacity);
	int i;
	for (i = 0; i < h->size; i += 1){
		newHeap->elements[i] = h->elements[i];
	}
	h = newHeap;*/
}

void bubbleUp(Heap* h, int index) {
	if (index == 0){
		return;
	}
	bool left = index % 2 != 0;
	int parentIndex;
	if (left){
		parentIndex = (index - 1) / 2;
	}
	else{
		parentIndex = (index - 2) / 2;
	}
	if (h->elements[index].key <= h->elements[parentIndex].key){
		swap(h, index, parentIndex);
		bubbleUp(h, parentIndex);
	}
}

void add(Heap* h, int k, char* val) {
	Pair pair;
	pair.key = k;
	pair.value = val;
	h->elements[h->size] = pair;
	bubbleUp(h, h->size);
	h->size += 1;
	if (h->size >= h->capacity){
		expandCapacity(h);
	}
}

void bubbleDown(Heap* h, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= h->size || right >= h->size){
		return;
	}
	if (h->elements[right].key < h->elements[left].key){
		swap(h, index, right);
		bubbleDown(h, right);
	}
	else{
		swap(h, index, left);
		bubbleDown(h, left);
	}
}

char* removeMin(Heap* h) {
	if (h->size <= 0){
		return NULL;
	}
	char* toReturn = h->elements[0].value;
	swap(h, 0, h->size - 1);
	h->size = h->size - 1;
	bubbleDown(h, 0);
	return toReturn;
}

bool isHeapAt(Heap* h, int index) {
	return false;
}

void cleanupHeap(Heap* h) {
	free(h->elements);
	free(h);
}

void printHeap(Heap* h) {
	int i;
	for (i = 0; i < h->size; i++){
		printf("%s", h->elements[i].value);
	}
}

char* peek(Heap* h) {
	return h->elements[0].value;
	}

int size(Heap* h) {
	return h->size;
}

Heap* makeHeap(int capacity) {
	Heap* h = malloc(sizeof(Heap));
	h->size = 0;
	h->capacity = capacity;
	h->elements = malloc(sizeof(Pair) * capacity);
	return h;
}


