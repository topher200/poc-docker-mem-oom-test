/*********************************************************
 This app just keeps on requesting 65536 bytes of memory
 Suitable to test within a container to see when container
 is killed due to Out Of Memory (OOM) error.
*********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
    int i;
    for (i=0; i<65536; i++) 
    {
        char *q = malloc(65536);
        printf ("Malloced: %d\n", 65536*i);
        sleep(1);

    }
    sleep(9999999);
}
