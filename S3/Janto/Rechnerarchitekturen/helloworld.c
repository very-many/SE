#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	int i = 2;
	int j = 9;
	j++;
	int k = i * j + 1;

	printf("Hello World INF%d.\n", k);
}
