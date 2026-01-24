#include <clibp.h>


bool str_endswith(string buffer, string needle)
{
    if(!buffer || !needle)
        return false;

    int len = str_len(buffer);
    int slen = str_len(needle);
    
    int start = len - slen;
    for(int i = start, c = 0; buffer[i] != '\0'; i++, c++)
    {
        if(buffer[i] != needle[c])
            return false;
    }

    return true;
}

i8 entry()
{
    printi(str_endswith(TEST_STRING, "SKID")), println(NULL);
    printi(str_endswith(TEST_STRING, "SKID\n"));
    return 0;
}