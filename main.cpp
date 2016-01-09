#include <QApplication>
#include "result.h"
#include "npo.h"

int main(int argc,char*argv[])
{
    QApplication app(argc,argv);
    NPO npo;
    npo.show();
    return app.exec();
}
