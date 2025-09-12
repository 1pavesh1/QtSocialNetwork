#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QDateTime>

class CustomWidget
{
public:
    virtual void InitializationInterface() = 0;
    virtual void SetupQCC() = 0;
    virtual void LoadContent() = 0;
};

#endif // CUSTOMWIDGET_H
