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
* [Map](/doc/clibp/stdlib_docs/map.md)
* [File](/doc/clibp/stdlib_docs/file.md)
* ► [Thread](/doc/clibp/stdlib_docs/thread.md)
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

# Thread Library

# Type(s) / Struct
```c
typedef struct
{
	handler_t	fnc;
	ptr			arguments;
	i8 			wait;
	i8 			finished;
	i32			pid;
	i32			ttid;
} _thread;

typedef _thread 	thread;
typedef thread 		*thread_t;
typedef thread 		**threads_t;

typedef struct
{
	threads_t	threads;
	int			idx;
} gthread;
```

### Functions
```c
gthread 	init_group_thread();
bool 		append_thread(gthread *g, thread_t t);

thread 		start_thread(handler_t fnc, ptr p, int wait);
fn 			thread_kill(thread_t t);
```