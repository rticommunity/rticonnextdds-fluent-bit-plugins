/* 
 * Build with: gcc -o catdelay catdelay.c
 *
 * Usage: catdelay <delayMsec> <fileName>
 * If <delayMsec> is zero, app will wait for the user to press ENTER to
 * process the next line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    char buf[2048];
    int delay;
    FILE *f;
    if (argc != 3) {
        fprintf(stderr, "Usage: catdelay <delayMsec (0=prompt)> <fileName>\n");
        return 1;
    }
    delay = atoi(argv[1]);
    if (delay < 0) {
        fprintf(stderr, "Invalid delay\n");
        return 1;
    }
    f=fopen(argv[2], "r");
    if (!f) {
        fprintf(stderr, "File not found: %s\n", argv[2]);
        return 1;
    }
    if (!delay) {
        fprintf(stderr, "Ready, press ENTER to write one line at the time\n");
    }
    while(!feof(f)) {
        if (!fgets(buf, sizeof(buf), f)) {
            fprintf(stderr, "Error reading: %s (errno=%d)\n", strerror(errno), errno);
            return 1;
        }
        buf[strlen(buf)-1]='\0';

        if (delay) {
            usleep(delay*1000);
        } else {
            getchar();
        }
        puts(buf);
        fflush(stdout);
    }
    return 0;
}


