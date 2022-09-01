#include "main.h"

char **tokenization(char *line_read, const char *delim)
{
	int i =0, j, count = 1, k = len[1024];
	char ** res;

	if (line_read == NULL)
		return (NULL);
	while (line_read[i] != NULL) /* checks for the end of input */
	{
		for (j = 0; delim[j]; j++) /* goes through an array of delims */
		{
			if (line_read[i] == delim[j]) /* for each character in i it checks for a delim specified in j */
			{
				count++
				len[k++] = i + 1;
				break;
			}
		}
	}

	res = malloc((count + 1) * sizeof(char *))
		if (!res)
		{
			perror("failed");
			exit(EXIT_FAILURE);
		}
	while (line_read[i])
}

