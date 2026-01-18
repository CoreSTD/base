#include "headers/libweb.h"

handler_t request_handler(cwr_t wr)
{
	wr->content = sock_read(wr->socket);
	int len = __get_meta__(wr->content)->length;

	println(wr->content);
	if(len < 3)
	{
		println("Malform request...!\n");
		return NULL;
	}

	wr->lines = split_lines(wr->content, &wr->line_count);
	if(wr->line_count == 0)
	{
		println("Malform request\n");
		return NULL;
	}

	if(find_string(wr->lines[0], "GET")) {
		wr->type = _rGET;
	} else if(find_string(wr->lines[0], "POST"))
	{
		wr->type = _rPOST;
	} else if(find_string(wr->lines[0], "HEAD"))
	{
		wr->type = _rHEAD;
	}

    /*
        TODO;
            work on the route handler
            Parse wr->lines[0] for req info
            find path handler or reject request with status code 
    */
	char *fake = "HTTP/1.1 200 OK\r\n"
				 "Content-Type: text/html;charset=UTF-8\r\n"
				 "Content-length: 16\r\n"
				 "Connection: close\r\n\r\n"
				 "Hello World\r\n\r\n";

	sock_write(wr->socket, fake);
	return NULL;
}

void parse_request(cwr_t wr)
{
	bool capture_body = false;

	int len = __get_meta__(wr->content)->length;
	wr->body = allocate(0, len);

	/* Parse Headers and Get body, Skip first line */
	wr->headers = init_map();
	for(int i = 1; i < wr->line_count; i++)
	{
		if(!wr->lines[i])
			break;

		/* After headers which is an empty line, Capture Body */
		if(is_empty(wr->lines[i])) {
			capture_body = true;
			continue;
		} else if(is_empty(wr->lines[i]) && capture_body) { // Break after body
			break;
		}
		
		/* Capture body after header */
		if(capture_body)
		{
			str_append(wr->body, wr->lines[i]);
			continue;
		}

		/* Parse Header Line */
		if(find_string(wr->lines[i], ":") > -1)
		{

			int arg_c = 0;
			sArr args = split_string(wr->lines[i], ':', &arg_c);

			if(arg_c < 2)
			{
				continue;
			}

			int pos = find_char(wr->lines[i], ':');
			map_append(wr->headers, args[0], wr->lines[i] + pos);
			pfree_array((array)args);
		}
	}
}