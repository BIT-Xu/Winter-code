#ifndef ALCIRCLECANVAS_H
#define ALCIRCLECANVAS_H

#include "alcanvas.h"

class ALCircleCanvas : public ALCanvas
{
    Q_OBJECT
public:
    explicit ALCircleCanvas(QWidget *parent=0);

    bool StartDraw(int width, int height, int gap, int mode);
};

#endif // ALCIRCLECANVAS_H
