#include "template.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	const int result = template();
	assert(EOF != result);
	return EXIT_SUCCESS;
}
