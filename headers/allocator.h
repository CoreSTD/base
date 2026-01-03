#pragma once

typedef unsigned long size_t;

#define _STANDARD_MEM_SZ_ 4096
#define _LARGE_MEM_SZ_ 4096 * 3
extern int _HEAP_PAGE_SZ_;

typedef struct {
	int 	size;
	size_t 	length;
	int 	id;
} __meta__;

extern int HEAP_META_SZ;

typedef void *heap_t;
typedef void *any;

extern heap_t _HEAP_;
extern int HEAP_DEBUG;
extern int used_mem;

void set_heap_sz(int n);

void init_mem();
void uninit_mem();
int __get_total_mem_used__(void);
any allocate(int sz, int len);
int __get_size__(any ptr);
int __is_heap_init__();
void pfree(any ptr);
__meta__ *__get_meta__(any ptr);

