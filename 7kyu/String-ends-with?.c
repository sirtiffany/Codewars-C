#include <stdbool.h>
bool solution(const char *string, const char *ending)
{
	int i;
	int x;
    
    i = 0;
    x = 0;
    while (string[i] != 0)  //count how many characters my string has
    {
		i++;
    }
    while (ending[x] != 0)
    {
        x++;
    }
    if (i < x)              //string can't be smaller than ending for ending to actually be the "ending" of string
    {
        return false;
    }
    i -= x;                 //get to index where ending is supposed to start in string
    x = 0;
    while (ending[x] != 0)  //check if each character of ending is the same as string supposed end
    {
        if (string[i] != ending[x])
        {
            return false;
            break ;
        }
		x++;
      	i++;
    }
    return (true);
}
