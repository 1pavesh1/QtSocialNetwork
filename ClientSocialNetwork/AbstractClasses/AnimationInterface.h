#ifndef ANIMATIONINTERFACE_H
#define ANIMATIONINTERFACE_H

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

class AnimationInterface
{
public:
    virtual void OpenAnimation() = 0;
    virtual void CloseAnimation() = 0;

    QGraphicsOpacityEffect  *opacityEffect;
    QPropertyAnimation      *animation;
};

#endif // ANIMATIONINTERFACE_H
