/*********************************************************
 This app exhausts memory at a rate of approximately 10MB per second
 Suitable to test within a container to see when container
 is killed due to Out Of Memory (OOM) error.
*********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define CHUNK_SIZE (1024 * 1024) // 1MB chunks
#define CHUNKS_PER_SECOND 10     // 10 chunks per second = 10MB/s

int main(void)
{
    int i = 0;
    char *chunk;

    printf("Starting memory exhaustion at ~10MB/second until OOM\n");

    while (1)
    {
        chunk = malloc(CHUNK_SIZE);

        if (chunk == NULL)
        {
            printf("Malloc failed after allocating %d MB\n", i);
            break;
        }

        // Fill memory to ensure it's actually allocated
        memset(chunk, 1, CHUNK_SIZE);

        printf("Allocated: %d MB\n", ++i);

        // Sleep for 1/10 of a second after each MB allocation
        usleep(1000000 / CHUNKS_PER_SECOND);
    }

    printf("Allocation complete. Sleeping...\n");
    sleep(9999999);

    return 0;
}
