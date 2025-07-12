#ifndef _MM_H_
#define _MM_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ALLOC_SIZE 256
#define ALIGN long

typedef union _Header{
    struct{
        union _Header *next;
        size_t size;
    } meta;
    
    ALIGN a;
} Header;

void* Mymalloc(size_t bytes);
void* Mycalloc(size_t num, size_t size);
void* Myrealloc(void *ptr, size_t bytes);
void Myfree(void *ptr);

static void* Osalloc(size_t num);
static Header* morecore(size_t num);

#endif
