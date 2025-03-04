#include <unistd.h>

int main()
{
    write(1, "Hello, I'm true!\n", 17);
    return 0;
}
