#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heapp.h"


static void _swap_(int32_t *timestamp, int32_t *aircrft_num) {
	int32_t temp = *timestamp;
	*timestamp = *aircrft_num;
	*aircrft_num = temp;
}

static void _heapify_ (int32_t timestamp[], uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (timestamp[child+1] > timestamp[child]){
				++child;
			}
		}
		if (timestamp[parent] >= timestamp[child]) {
			break;
		}
		_swap_(&timestamp[parent], &timestamp[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(int32_t timestamp[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(timestamp[child] <= data[child/2]);
	}

}

Heap*	heap_test(Heap *heap)
{
	_test_heap_(heap->timestamp, heap->size);
}

Heap 	heap_new(int32_t timestamp[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(timestamp, len, idx);
	}
	heap.size = len;
	memcpy(heap.timestamp, timestamp, (len+1) * sizeof(int32_t));
	_test_heap_(heap.timestamp, heap.size);

	return heap;
}

Heap*	heap_sort(Heap *heap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) {
		_swap_(&heap->timestamp[idx], &heap->timestamp[1]);
		_heapify_(heap->timestamp, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->timestamp[parent] < key) {
		heap->timestamp[loc] = heap->timestamp[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->timestamp[loc] = key;
	return heap;

}



/***int32_t		heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->timestamp[1];	
	_swap_(&heap->data[1], &heap->data[heap->size]);
	--heap->size;
	_heapify_(heap->data, heap->size, 1);

	return max;
}***/

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}
int32_t		heap_extract_min(Heap *heap timestamp[][]){
	assert(heap->size>0&&heap->size<HEAP_MAX_SIZE);
	for(uint32_t idx=heap->size;idx>0;--idx){
		-swap-(&heap->timestamp[][],&heap->timestamp[idx]);
		-heapify-(heap->data,idx-1,1);
	}
	return heap;
}
