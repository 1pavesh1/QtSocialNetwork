#ifndef CHANGEPHOTOWINDOW_H
#define CHANGEPHOTOWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include "AbstractClasses/BaseWindow.h"

namespace Ui {
class ChangePhotoWindow;
}

class ChangePhotoWindow : public QDialog
{
    Q_OBJECT
private:
    Ui::ChangePhotoWindow       *ui;

    QGraphicsScene              *scene;
    QGraphicsPixmapItem         *pixmapItem;
    QGraphicsPixmapItem         *maskItem;
    QGraphicsEllipseItem        *circleItem;
    QGraphicsEllipseItem        *resizeHandle;
    QPointF                     dragOffset;
    QPixmap                     originalPixmap;
    QPixmap                     croppedPixmap;
    QPixmap                     displayPixmap;

    bool                        isResizing;
    bool                        isDragging = false;

    void CreateResizableCircle();
    QVariant ItemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

public:
    explicit ChangePhotoWindow(const QPixmap &originalPixmap, QWidget *parent = nullptr);
    ~ChangePhotoWindow();
    QPixmap GetCroppedPixmap() const;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_applyButton_clicked();
    void UpdateMask();
};

#endif // CHANGEPHOTOWINDOW_H
