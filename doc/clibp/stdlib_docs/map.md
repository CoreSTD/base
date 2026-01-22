<div align="center">
    <h1>clib+ Libraries</h1>

[Start-up](/README.md)
| [Introduction](/doc/clibp/intro.md)
| [Quick Doc](/quick_doc.md)
| ● [Libraries](/doc/clibp/libraries.md)
| [Todo](/doc/clibp/todo.md)
</div>

## List Of Libraries Provided for clib+
<table align="center">
<tr><td valign=top>

<p>Stdlib<p>

* [Internal](/doc/clibp/stdlib_docs/internal.md)
* [Allocator](/doc/clibp/stdlib_docs/allocator.md)
* [Memory](/doc/clibp/stdlib_docs/memory.md)
* [Int](/doc/clibp/stdlib_docs/int.md)
* [String](/doc/clibp/stdlib_docs/string.md)
* [Array](/doc/clibp/stdlib_docs/array.md)
* ► [Map](/doc/clibp/stdlib_docs/map.md)
* [File](/doc/clibp/stdlib_docs/file.md)
* [Thread](/doc/clibp/stdlib_docs/thread.md)
* [Socket](/doc/clibp/stdlib_docs/socket.md)
</td>
<td valign=top>

<p>External Libs</p>

* [cWS (C Webserver)](#)
</td>
<td valign=top>

<p>Public Libs</p>

* [GLFW2](#)
</td></tr>
</table>

# Map Library

## Type(s) / Struct
```c
typedef struct {
	string key;
	string value;
} _field;

typedef _field field;
typedef _field *field_t;
typedef _field **fields_t;

typedef struct {
	fields_t 	fields;
	int 		len;
} _map;

typedef _map map;
typedef _map *map_t;
```

## Functions
```c
map_t 	init_map(void);
bool 	map_append(map_t map, string key, string value);
string 	find_key(map_t map, string key);
```