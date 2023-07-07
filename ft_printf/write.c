#include <unistd.h>
#include <stdio.h>

int main()
{
    char *t = "guhıgjrtgr";

    // while(*t)
    //     write(1, t++, 1);       //doğru hepsi

    // int i = 0;
    // while(i <11)
    //     write(1, &t[i++], 1);       // t + i  =  &t[i]
    int i = 0;

    while(i < 11)
        write(1, t + i++, 1);       // t + i  =  &t[i]

    while(*t)
        write(1, ++t, 1);
}
