#ifndef ALRECCANVAS_H
#define ALRECCANVAS_H

#include "alcanvas.h"

class ALRecCanvas : public ALCanvas
{
    Q_OBJECT
public:
    explicit ALRecCanvas(QWidget *parent=0);

    bool StartDraw(int width, int height, int gap, int mode);
};

#endif // ALRECCANVAS_H
