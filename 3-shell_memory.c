#include "shell.h"

/**
 * _realloc - reallocation of memory if the size is exceeded
 * @ptr: pointer to the previous size.
 * @oldsize: previously allocated size.
 * @newsize: newsize to allocate.
 *
 * Return: returns the newly allocated size
 */

void *_realloc(void *ptr, int oldsize, int newsize)
{
	void *tmp; /* declaring a temporary memory space */
	int i, min;

	if (ptr == NULL) /* declaring a new space if pointer is empty */
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
		min = (new < old) ? newsize : oldsize; /* tenary operator replacing if */
		tmp = malloc(newsize);
		if (tmp)
		{
			for (i = 0; i < min; i++)
				*((char *)tmp + 1) = *((char *)ptr + 1)
			free(ptr);
			return (tmp);
		}

		else
			return (NULL);
	}
}
