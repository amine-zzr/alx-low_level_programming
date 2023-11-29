#include "main.h"
/**
 * append_text_to_file - a function that creates a file.
 * @filename: the name of the file.
 * @text_content: a NULL terminated string to add to the file.
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t appended;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (text_content != NULL)
	{
		appended = write(fd, text_content, strlen(text_content));

		if (appended == -1)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);
	return (1);
}
