#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

//This program shows usage of variadic functions. It counts cost of the order.
typedef enum drink
{
	MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
	
} drink_type;

double price(drink_type d)
{
	switch(d) {
		case MUDSLIDE:
			return 6.54;
		case FUZZY_NAVEL:
			return 5.34;
		case MONKEY_GLAND:
			return 3.31;
		case ZOMBIE:
			return 9.93;

	}

	return 0;
}

double total(int args, ...)
{
	double total = 0;
	va_list num;
	va_start(num, args);
	int i;
	for (i = 0; i < args; ++i)
	{
		drink_type d = va_arg(num, drink_type);
		total = total + price(d);
	}
	va_end(num);

	return total;
}

int main(int argc, char const *argv[])
{
	price(MONKEY_GLAND);
	printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));

	return 0;
}

