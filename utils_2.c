/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *_strdup(char *str, int start, int stop)
{
	static char dup[1024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (str[i] != ':')
			dup[j++] = str[i];
	dup[k] = 0;
	return (dup);
}

