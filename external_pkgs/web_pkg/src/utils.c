#include "../headers/libweb.h"

string status_code_to_string(status_code code)
{
    if(!code) return NULL;

    for(int i = 0; i < STATUS_CODE_COUNT; i++)
        if(code == (StatusCode)StatusCodeDef[i][0])
            return StatusCodeDef[i][1];

    return NULL;
}