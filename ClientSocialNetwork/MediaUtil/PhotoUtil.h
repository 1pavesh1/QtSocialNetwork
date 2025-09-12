#ifndef PHOTOUTIL_H
#define PHOTOUTIL_H

#include <QPainter>

class PhotoUtil
{
public:
    QPixmap GetHandlerPhoto(const QByteArray &photo, const QSize &sizePhoto)
    {
        QPixmap pixmap;
        pixmap.loadFromData(photo);

        QSize buttonSize = sizePhoto;
        QPixmap scaledPixmap(buttonSize);
        scaledPixmap.fill(Qt::transparent);

        QPainter painter(&scaledPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(pixmap.scaled(buttonSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        painter.drawEllipse(0, 0, buttonSize.width(), buttonSize.height());
        painter.end();

        return scaledPixmap;
    }
};

#endif // PHOTOUTIL_H
