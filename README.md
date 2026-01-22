<div align="center">
	<h1>clib+ v3.0</h1>
	<p>The official minimal C backend alternative to GLIBC</p>

● [Start-up](/README.md)
| [Introduction](doc/intro.md)
| [Quick Doc](/quick_doc.md)
| [Libraries](doc/libraries.md)
| [Todo](/doc/clibp/todo.md)
</div>

# Some Info

- The project is still in development!
- The library is a minimal C backend with a custom loader to link!

### Supported Architectures

- x86
- x86_64
- AMD
- RISC-V

### Install

Run the following commands to install the library!
```bash
sudo apt install git make;
git clone https://github.com/clibplus/clibp_v3_0.git
cd cdlib_v3_0
make # make tcc (for tcc (not complete, testing stage))
```

### Standard Use

```c
#include <clibp.h>

int entry() {
	println("Hello World");
	return 0;
}
```

# Compile w/ CLIBP

### Linux Linker
```c
Usage: gclibp <c_file> <opt> <output>
Use --help for help or more arguments
```
