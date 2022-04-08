#include <stdlib.h>
#include <time.h>
#include <studio.h>
/**
 * main - Prints a random number and states whether
 *        it is positive, negative, or zero.
 *
 * Return: Always 0.
 */
int ma

int n;

srand(time(0));
n = rand() - RAND_MAX / 2;

if (n > 1)
printf("%d is positive\n", n);
else if (n < 0)
printf("%d is negative\n", n);
else
return (0);
