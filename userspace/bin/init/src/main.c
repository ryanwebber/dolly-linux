#include <unistd.h>

int main()
{
    char buffer[256];

    while (1)
    {
        write(1, "Hello world\n", 12);
        read(0, buffer, sizeof(buffer));
    }

    return 0;
}
