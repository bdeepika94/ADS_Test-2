ifndef _HEAPSORT_
#define _HEAPSORT_

#include<stdint.h>
#define HEAP_SIZE 32

typedef struct _heap_ Heap;

struct _heap_event_
{
	int32_t size;
	int32_t timestamp[HEAP_SIZE];
	

};

Heap heap_new(int32_t data[],int32_t length);
Heap *heap_sort(Heap *heap);
Heap heap_insert(&heap, 47);
Heap heap_test(&heap);
Heap heap_extract_min(Heap *heap timestamp[][]);
Heap _heapify_(int32_t timestamp[], uint32_t len, uint32_t parent);

#endif
