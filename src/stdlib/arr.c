#include "../../headers/clibp.h"

int arr_contains(sArr args, string needle)
{
	if(!args || !needle)
        return -1;

    for(int i = 0; args[i] != 0; i++)
        if(mem_cmp(args[i], needle, str_len(args[i])))
            return i;

    return -1;
}
