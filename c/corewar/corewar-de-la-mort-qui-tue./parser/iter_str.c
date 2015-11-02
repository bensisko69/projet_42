#include "../includes/parser.h"

void iter_str(char *s, void (*f)(char))
{
    if (!s)
        return ;
    while (s && *s != 0)
    {
        f(*s);
        s++;
    }
}