#include "stdlib.h"
#include "unistd.h"
#include "string.h"

#define __MALLOC_HEAP_SIZE (4 * 1024 * 1024)

static char heap[__MALLOC_HEAP_SIZE];
static size_t heap_offset = 0;

// Trivial malloc implementation that just leaks memory
// just to get the system stood up
void *malloc(size_t size)
{
    if (heap_offset + size >= __MALLOC_HEAP_SIZE)
    {
        return NULL;
    }

    void *ptr = &heap[heap_offset];
    heap_offset += size;
    return ptr;
}

void free(void *ptr)
{
    // Noop for now, we just leak memory
    (void)ptr;
}

char *getenv(const char *name)
{
    for (char **env = &environ[0]; *env; env++)
    {
        char *current = *env;
        while (*current != '=')
        {
            current++;
        }

        if (strncmp(*env, name, current - *env) == 0)
        {
            return current + 1;
        }
    }

    return NULL;
}
