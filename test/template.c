#ifdef NDEBUG
    #undef NDEBUG // assert in Release
#endif
#include "template/template.h"
#include <assert.h>
int main()
{
    using namespace thezhe::templatepp; // NOLINT
    assert(Templatepp::returnTrue());
    return EXIT_SUCCESS;
}
