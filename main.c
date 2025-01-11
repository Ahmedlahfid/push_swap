#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main ()
{
    char **st;
    	char *str = "salam";
        int j = ft_strlen(str) + 1;
	char *new = malloc(j);

	int i = 0;

	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
    st = &new;
    free(st);
	printf("%s\n", *st);
	
    return (0);
}