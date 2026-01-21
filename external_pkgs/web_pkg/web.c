#include "headers/libweb.h"

handler_t index_page(cwr_t wr)
{
	println("\x1b[31mNew Request\x1b[39m");
	parse_request(wr);

	int header_len = __get_size__(wr->headers->fields);
	_printi(header_len), print("\n");
	for(int i = 0; i < header_len; i++) {
		println(wr->headers->fields[i]->key);
	}
	println("\x1b[31mEnding req\x1b[39m");
}

int entry()
{
	toggle_debug_mode();
	cws_t ws = init_web_server(NULL, 50);
	if(!ws)
	{
		println("error, unable to put up the webserver!");
		return 1;
	}
	println("Webserver up @ localhost:"), _printi(50), print("\n");

	web_append_route(ws, create_route("index", "/", (handler_t)index_page, 0));
	for(int i = 0; i < ws->route_count; i++)
		print("Path: "), println(ws->routes[i]->path);

	start_web_server(ws, 0);
	return 0;
}
