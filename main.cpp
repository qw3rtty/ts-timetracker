#include "TS_ViewTerminal.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char **argv)
{
    TS_ViewTerminal view;
    view.render();

    return 0;
}
