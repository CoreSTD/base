<div align="center">
    <h1>clib+ Libraries</h1>
    <p>File Library</p>
</div>

Definitions/Enums
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

Type
```c
typedef u32 fd_t;
```

Functions
```c
fd_t    open_file(const char* filename, FILE_MODE mode, int flags);
int		file_content_size(fd_t fd);
int		file_read(fd_t fd, char* buffer, int sz);
int		file_write(fd_t fd, const char* buffer, len_t len);
fn		file_close(fd_t fd);
```