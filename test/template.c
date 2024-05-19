#ifdef NDEBUG
    #undef NDEBUG // assert in Release
#endif
#include "template.h"
#include <assert.h>
#include <stdlib.h>
int main()
{
    assert(template_true());
    return EXIT_SUCCESS;
}
