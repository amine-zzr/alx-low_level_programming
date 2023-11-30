#include "main.h"
#define SIZE 1024

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: the files to hundle.
 * Return: always 0.
 */

int main(int argc, char **argv)
{
	int fd1, fd2;
	char buffer[SIZE];
	ssize_t readed, written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	readed = read(fd1, buffer, SIZE);

	if (fd1 == -1 || readed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	while ((readed = read(fd1, buffer, SIZE)) > 0)
	{
		written = write(fd2, buffer, readed);
		if (fd2 == -1 || written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}

	return (0);
}
