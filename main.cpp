#include "TS_Application.h"
#include "TS_IView.h"

int main(int argc, char **argv)
{
    TS_IView *view = application->buildView();
    view->render();

    return 0;
}
