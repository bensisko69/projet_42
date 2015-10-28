/*******
 * Read input from STDIN
 * Use printf(...) or fprintf( stdout, ...) to output your result.
 * Use:
 *  localPrint( char* mystring)
 * to display variable in a dedicated area.
 * ***/
#include <stdlib.h>
#include <stdio.h>

int main() 
{
	char s[1024];
	int	money;
	int	tour;
	int	x;
	int	y;


	money = 0;
	tour = 0;
	x = 0;
	y = 0;
    while (scanf("%s", &s) != EOF) 
    {
    	printf("%s\n", s);
    }
    
    return 0;
}