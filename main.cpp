#include "TS_Application.h"
#include "TS_View.h"

int main(int argc, char **argv)
{
    TS_View *view = application->buildView();
    view->render();

    return 0;
}
