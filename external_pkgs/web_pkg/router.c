
#include "headers/libweb.h"

route_t create_route(string name, string path, handler_t fnc, int parse_req)
{
    route_t r = allocate(0, sizeof(_route));
    r->name = str_dup(name);
    r->path = str_dup(path);
    r->handle = fnc;
    r->parse_req = parse_req;

    return r;
}