#ifndef DATASAVER_H
#define DATASAVER_H

#include <Model/Headers/appdata.h>
#include <vector>
#include <Model/Headers/figure.h>
#include <QDataStream>
#include <QFile>
#include <QDebug>
#include <Model/Headers/ellipse.h>

class DataSaver
{
public:
    DataSaver();
    void Save(AppData data, QString path);
};

#endif // DATASAVER_H
