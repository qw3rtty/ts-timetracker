#include "TS_FactoryView.h"
#include "TS_IView.h"

int main(int argc, char **argv)
{
    TS_IView *view = TS_FactoryView::build();
    view->render();

    return 0;
}
