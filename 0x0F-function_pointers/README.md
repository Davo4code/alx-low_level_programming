0x0F. C - Function pointers
Learning Objectives

General

    What are function pointers and how to use them
    What does a function pointer exactly hold
    Where does a function pointer point to in the virtual memory

Requirements

    All files are created and compiled on Ubuntu 14.04.4 LTS on gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
    All files are linted for syntax and style with Betty

Tasks
0. What's my name

    Write a function that prints a name.
        Prototype: void print_name(char *name, void (*f)(char *));

julien@ubuntu:~/0x0e. Function pointers$ cat 0-main.c

#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name_as_is - prints a name as is
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_as_is(char *name)
{
    printf("Hello, my name is %s\n", name);
}

/**
 * print_name_uppercase - print a name in uppercase
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_uppercase(char *name)
{
    unsigned int i;

    printf("Hello, my uppercase name is ");
    i = 0;
    while (name[i])
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            putchar(name[i] + 'A' - 'a');
        }
        else
        {
            putchar(name[i]);
        }
        i++;
    }
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_name("Danton", print_name_as_is);
    print_name("Rick Harris", print_name_uppercase);
    printf("\n");
    return (0);
}

julien@ubuntu:~/0x0e. Function pointers$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-print_name.c -o a
julien@ubuntu:~/0x0e. Function pointers$ ./a
Hello, my name is Danton
Hello, my uppercase name is RICK HARRIS

1. If you spend too much time thinking about a thing, you'll never get it done

    Write a function that executes a function given as a parameter on each element of an array.
        Prototype: void array_iterator(int *array, size_t size, void (*action)(int));
        where size is the size of the array
        and action is a pointer to the function you need to use

julien@ubuntu:~/0x0e. Function pointers$ cat 1-main.c

#include <stdio.h>
#include "function_pointers.h"

/**
 * print_elem - prints an integer
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem(int elem)
{
    printf("%d\n", elem);
}

/**
 * print_elem_hex - prints an integer, in hexadecimal
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem_hex(int elem)
{
    printf("0x%x\n", elem);
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[5] = {0, 98, 402, 1024, 4096};

    array_iterator(array, 5, &print_elem);
    array_iterator(array, 5, &print_elem_hex);
    return (0);
}
