# Definitions
```c
#define PROT_READ   	0x1
#define PROT_WRITE		0x2
#define PROT_EXEC   	0x4
#define PROT_NONE   	0x0

#define MAP_SHARED  	0x01
#define MAP_PRIVATE 	0x02
#define MAP_FIXED   	0x10
#define MAP_ANONYMOUS 	0x20
#define MAP_STACK 		0x20000

#define _STANDARD_MEM_SZ_   4096
#define _LARGE_MEM_SZ_      4096 * 3
```

# Type(s) / Struct(s)
```c
typedef void* heap_t;

typedef struct {
	int     size;
	size_t  length;
	int     id;
} __meta__;
```

# Functions

```c
fn 			set_heap_sz(int n);
fn 			set_heap_debug();
fn 			req_memory();

fn        	init_mem();
fn        	uninit_mem();
int         __get_total_mem_used__(void);
ptr         allocate(int sz, int len);
int         __get_size__(any ptr);
int         __is_heap_init__();
fn        	pfree(any ptr, int clean);
__meta__* __get_meta__(any ptr);
```