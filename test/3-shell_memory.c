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
	void *tmp;
	int i, cond;

	if (!ptr) /* declaring a new space if pointer is empty */
	{
		return (malloc(newsize));
	}

	else if (newsize == oldsize)
		return (ptr);

	else if (newsize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	else
	{
		cond = (newsize < oldsize) ? newsize : oldsize;
		/* tenary operator replacing if */
		tmp = malloc(newsize);
		if (tmp)
		{
			for (i = 0; i < cond; i++)
				*((char *)tmp + 1) = *((char *)ptr + 1);
			free(ptr);
			return (tmp);
		}

		else
			return (NULL);
	}
}
