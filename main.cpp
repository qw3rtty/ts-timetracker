#include <stdio.h>
#include "./controllers/headers/TS_Base.h"
#include "./controllers/headers/TS_Info.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char **argv)
{
    TS_Info info;
    info.welcome();
    info.showInfo();

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        fputs("ts-timetracker> ", stdout);

        /* Read a line of user input of maximum size 2048 */
        fgets(input, 2048, stdin);

        /* Echo input back to user */
        printf("You entered: %s", input);
    }

    return 0;
}
