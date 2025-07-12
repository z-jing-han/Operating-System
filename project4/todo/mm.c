#include "mm.h"

static Header base;
static Header *free_list = NULL;

void* Mymalloc(size_t bytes){
	Header *prev, *now;
	size_t units = (bytes + sizeof(Header) - 1)/sizeof(Header) + 1;
	
	prev = free_list;
	if(prev == NULL){
		base.meta.next = &base;
		free_list = &base;
		prev = &base;
		base.meta.size = 0;
	}
	
	for(now = prev->meta.next; ; prev = now, now=now->meta.next){
		if(now->meta.size >= units){
			if(now->meta.size == units)
				prev->meta.next = now->meta.next;
			else{
				now->meta.size -= units;
				now += now->meta.size;
				now->meta.size = units;
			}
			
			free_list = prev;
			return (void*)(now + 1);
		}
		
		if(now == free_list){
			now = morecore(units);
			if(now == NULL)
				return NULL;
		}
	}
}

void* Mycalloc(size_t num, size_t size){
	void *ptr = Mymalloc(num*size);
	if(ptr)
		memset(ptr, 0, num*size);
	return ptr;
}

void* Myrealloc(void *ptr, size_t bytes){
	if(!ptr)
		return Mymalloc(bytes);
	if(bytes == 0){
		Myfree(ptr);
		return NULL;
	}
	size_t units = (bytes + sizeof(Header) - 1)/sizeof(Header) + 1;
	size_t old_units = ((Header*)ptr - 1)->meta.size;
	size_t max = (units >= old_units ? units*sizeof(Header) : old_units*sizeof(Header));
	void *new_ptr = Mymalloc(units * sizeof(Header));
	if(new_ptr){
		printf("Test1\n");
		printf("ptr:%p\n",ptr);
		printf("new_ptr:%p\n", new_ptr);
		printf("max:%ld\n", max);
		memcpy(new_ptr, ptr, max);
		printf("Test2\n");
	}
	printf("test3\n");
	Myfree(ptr);
	return new_ptr;
}

void Myfree(void *p){
	Header *ptr;
	Header *header = (Header*)p - 1;
	
	for(ptr = free_list; !(header > ptr && header < ptr->meta.next); ptr = ptr->meta.next)
		if(ptr >= ptr->meta.next && (header > ptr || header < ptr->meta.next))
			break;
	
	if(header + header->meta.size == ptr->meta.next){
		header->meta.size += ptr->meta.size;
		header->meta.next = ptr->meta.next->meta.next;
	}else
		header->meta.next = ptr->meta.next;
	
	if(ptr + ptr->meta.size == header){
		ptr->meta.size += header->meta.size;
		ptr->meta.next = header->meta.next;
	}else
		ptr->meta.next = header;
	
	free_list = ptr;
}

static Header* morecore(size_t num){
	Header *header;
	void *ptr;
	if(num < MIN_ALLOC_SIZE)
		num = MIN_ALLOC_SIZE;
	ptr = Osalloc(num * sizeof(Header));
	if(!ptr)
		return NULL;
	header = (Header*)ptr;
	header->meta.size = num;
	Myfree((void*)(header+1));
	return free_list;
}

static void* Osalloc(size_t num){
	void* ptr = sbrk(num);
	return (ptr == (void*)-1) ? NULL : ptr;
}
