#ifndef PHOTOWIDGET_H
#define PHOTOWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomWidget.h"
#include "FileModel.h"

class PhotoWidget : public QWidget, public CustomWidget
{
    Q_OBJECT
private:
    FileModel   fileModel;
    QVBoxLayout *mainLayout;
    QLabel      *imageLabel;
    QWidget     *mediaContainer;

public:
    PhotoWidget(const FileModel &fileModel, QWidget *parent = nullptr)
        : QWidget(parent), fileModel(fileModel)
    {
        SetupQCC();
        InitializationInterface();
        LoadContent();
    }

    void InitializationInterface() override
    {
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(8);

        mediaContainer = new QWidget(this);
        QVBoxLayout *containerLayout = new QVBoxLayout(mediaContainer);
        containerLayout->setContentsMargins(0, 0, 0, 0);

        imageLabel = new QLabel(mediaContainer);
        imageLabel->setAlignment(Qt::AlignCenter);
        containerLayout->addWidget(imageLabel);

        mainLayout->addWidget(mediaContainer);

        setLayout(mainLayout);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            QLabel
            {
                background: transparent;
            }
            QWidget
            {
                background: transparent;
            }
        )");
    }

    void LoadContent() override
    {
        QPixmap pixmap;
        if (pixmap.loadFromData(fileModel.GetFileData()))
        {
            QPixmap scaledPixmap = pixmap.scaled(360, 360,
                                                 Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation);
            imageLabel->setPixmap(scaledPixmap);
            mediaContainer->setVisible(true);
        }
    }
};

#endif // PHOTOWIDGET_H
