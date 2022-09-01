#include "shell.h"

/* realloc user defined */

void *_realloc(void *ptr, int oldsize, int newsize)
{
	void *tmp; /* declaring a temporary memory space */
	int i, min;

	if(ptr == NULL) /* declaring a new space if pointer is empty */
	{
		tmp = malloc(newsize);
		return (tmp);
	}

	else if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	 else if (newsize == oldsize)
                return (ptr);

	else
	{
		min = (new < old) ? newsize : oldsize;
		tmp = malloc(newsize);
		if (tmp)
		{
			for (i = 0; i < min; i++)
				*((char *)tmp + 1) = *((char *)ptr + 1)
			free(ptr);
			return(tmp);
		}

		else
			return (NULL);
	}
}
