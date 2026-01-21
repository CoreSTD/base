#include "headers/libweb.h"

map_t ending_default_headers;
fn create_default_web_headers()
{
	ending_default_headers = init_map();
	map_append(ending_default_headers, "Content-Type", "text/html;charset=UTF-8");
	map_append(ending_default_headers, "Connection", "close");
}

handler_t index_page(cwr_t wr)
{
	println("\x1b[31mNew Request\x1b[39m");
	char *fake = "HTTP/1.1 200 OK\r\n"
				 "Content-Type: text/html;charset=UTF-8\r\n"
				 "Content-length: 15\r\n"
				 "Connection: close\r\n\r\n"
				 "Hello World\r\n\r\n";

	__sprintf(_OUTPUT_, "Header Count: %d", (void *)&wr->headers->len);
	println(_OUTPUT_);
	for(int i = 0; i < wr->headers->len; i++) {
		print("[ "), i <= 9 ? printi(i) : _printi(i), print(" ]: ");
		print_args((string []){
			"Key: ",
			wr->headers->fields[i]->key,
			" -> ",
			wr->headers->fields[i]->value,
			"\n", 0
		});
	}
	println("\x1b[31mEnding req\x1b[39m");
	sock_write(wr->socket, fake);
}

int entry()
{
	cws_t ws = init_web_server(NULL, 50);
	if(!ws)
	{
		println("error, unable to put up the webserver!");
		return 1;
	}
	print("Webserver up @ http://localhost:"), _printi(50), print("\n");

	web_append_route(ws, create_route(
		"index",
		"/",
		(handler_t)index_page,
		1
	));

	start_web_server(ws, 0);
	return 0;
}
