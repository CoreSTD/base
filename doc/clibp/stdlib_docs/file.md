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
* ► [File](/doc/clibp/stdlib_docs/file.md)
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

# File Library

## Definitions/Enums
```c
typedef enum FILE_MODE {
	O_RDONLY 	= 0,		// Read
	O_WRONLY 	= 01,		// Write
	O_RDWR 		= 02,		// Read-Write
	O_CREAT 	= 0100,		// Create
	O_EXCL 		= 0200,
	O_NOCTTY 	= 0400,
	O_TRUNC 	= 01000		// Truncate
} FILE_MODE;
```

## Type
```c
typedef u32 fd_t;
```

## Functions
```c
fd_t    open_file(const char* filename, FILE_MODE mode, int flags);
int		file_content_size(fd_t fd);
int		file_read(fd_t fd, char* buffer, int sz);
int		file_write(fd_t fd, const char* buffer, len_t len);
fn		file_close(fd_t fd);
```