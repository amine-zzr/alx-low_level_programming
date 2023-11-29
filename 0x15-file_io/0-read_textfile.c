#include "main.h"

/**
 * read_textfile - reads a text file and prints to the POSIX stdout.
 * @filename: the pathneme to the file.
 * @letters: number of letters it should read and print.
 * Return: number of bytes written or 0 if it failed.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t readed, written;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	readed = read(fd, buffer, letters);
	if (readed == -1)
		return (0);
	written = write(STDOUT_FILENO, buffer, readed);
	if (written == -1)
		return (0);
	if (close(fd) == -1)
		return (0);

	free(buffer);
	return (written);
}
