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

* ► [Internal](/doc/clibp/stdlib_docs/internal.md)
* [Allocator](/doc/clibp/stdlib_docs/allocator.md)
* [Memory](/doc/clibp/stdlib_docs/memory.md)
* [Int](/doc/clibp/stdlib_docs/int.md)
* [String](/doc/clibp/stdlib_docs/string.md)
* [Array](/doc/clibp/stdlib_docs/array.md)
* [Map](/doc/clibp/stdlib_docs/map.md)
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

# Internal Library

## Definitions
```c
#define clibp_panic(msg) 	\
			__clibp_panic(msg, __FILE__, __LINE__);
```

## Functions
```c
/* internal.c */
fn		toggle_debug_mode();
fn 		__exit(int code);
fn 		execute(string app, sArr args);
fn 		print_sz(const string buffer, int sz);
fn		printc(const char ch);
fn 		printi(int num);
fn 		_printi(int value);
fn 		print(const string buff);
fn		println(const string buff);
fn 		printsz(const string buff, int sz);
fn 		print_args(sArr arr);
ptr		to_heap(ptr p, i32 sz);
fn		__clibp_panic(string msg, string file, int line);
```