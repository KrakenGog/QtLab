#ifndef DATALOADER_H
#define DATALOADER_H

#include <Model/Headers/appdata.h>
#include <Model/Headers/ellipse.h>


class DataLoader
{
public:
    DataLoader();

    AppData Load(QString file);
};

#endif // DATALOADER_H
