#include "matlab.hpp"

// Wersje bibliotek standardowych znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c" (np. stdlib.h -> cstdlib).
#include <cstdlib>

int main() {
    int tab[] = {1, 2, 3, 4, 5};
    print_vector(tab, 5);
    return EXIT_SUCCESS;
}
