#include <clibp.h>

int entry()
{
    map_t map = init_map();
    map_append(map, "name", "chris");
    map_append(map, "age", "3");

    for(int i = 0; map->fields[i] != NULL; i++)
        print_args((string []){map->fields[i]->key, " -> ", map->fields[i]->value, "\n", 0});

    return 0;
}