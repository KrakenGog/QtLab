#ifndef APPDATA_H
#define APPDATA_H

#include <vector>
#include <Model/Headers/figure.h>

class AppData
{
public:
    AppData();

    std::vector<Figure*> Figures;
    qint32 c1,c2,c3;

};

#endif // APPDATA_H
