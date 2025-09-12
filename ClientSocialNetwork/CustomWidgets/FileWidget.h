#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomWidget.h"
#include "FileModel.h"

class FileWidget : public QWidget, public CustomWidget
{
    Q_OBJECT

private:
    FileModel       fileModel;
    QVBoxLayout     *mainLayout;
    QHBoxLayout     *headerLayout;
    QLabel          *fileIconLabel;
    QLabel          *fileNameLabel;

public:
    FileWidget(const FileModel &fileModel, QWidget *parent = nullptr)
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

        QWidget *headerWidget = new QWidget(this);
        headerWidget->setObjectName("headerWidget");
        headerLayout = new QHBoxLayout(headerWidget);
        headerLayout->setContentsMargins(8, 8, 8, 8);
        headerLayout->setSpacing(12);

        fileIconLabel = new QLabel(headerWidget);
        fileIconLabel->setPixmap(QIcon(":/IMG/IMG/FilePin50x50.png").pixmap(40, 40));
        fileIconLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

        fileNameLabel = new QLabel(headerWidget);
        fileNameLabel->setObjectName("fileName");
        fileNameLabel->setWordWrap(false);
        fileNameLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        fileNameLabel->setMaximumWidth(400);

        headerLayout->addWidget(fileIconLabel);
        headerLayout->addWidget(fileNameLabel);
        headerLayout->addStretch(1);

        QHBoxLayout *mainControlLayout = new QHBoxLayout();
        mainControlLayout->setSpacing(8);

        mainLayout->addWidget(headerWidget);

        setLayout(mainLayout);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            QLabel
            {
                color: #2a5885;
                font-size: 13px;
                background: transparent;
            }
            QLabel#fileName
            {
                font-size: 16px;
                color: black;
                background: transparent;
                padding: 5px;
            }
        )");
    }

    void LoadContent() override
    {
        fileNameLabel->setText(fileModel.GetName());
    }
};

#endif // FILEWIDGET_H
