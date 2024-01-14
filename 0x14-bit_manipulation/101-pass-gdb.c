#include <stdio.h>

int main(void)
{
	FILE *file = fopen("101-password", "w");

	fprintf(file, "%s", "Hol");
	fclose(file);

	return (0);
}
