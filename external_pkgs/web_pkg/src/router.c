#include "../headers/libweb.h"

route_t create_route(string name, string path, handler_t handle, int parse)
{
    if(!name || !path || !handle)
        return NULL;

    route_t r = allocate(0, sizeof(_route));
    r->name = str_dup(name);
    r->path = str_dup(path);
    r->handle = handle;
    r->parse_req = parse;

    return r;
}

bool get_html_template(route_t r, string template_file)
{
    if(!r || !template_file)
        return false;

    if(!str_endswith(template_file, ".html"))
        return false;

    fd_t file = open_file(template_file, 0, 0);
    size_t sz = file_content_size(file);

    r->template = allocate(0, sz + 1);
    file_read(file, r->template, sz);

    file_close(file);
    return true;
}

bool toggle_read_only(route_t r)
{ return (r->parse_req = r->parse_req ? false : true); }