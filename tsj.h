#ifndef TSJ_H
#define TSJ_H
#include "strain.h"
#include <qstring.h>
#include <qmutex.h>

class tsj
{
public:
    tsj();
    static train temp;
    static QString name,id;
    static int s,t;
    static QMutex m;
};

#endif // TSJ_H
