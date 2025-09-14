#include "ChangePhotoWindow.h"
#include "ui_ChangePhotoWindow.h"

ChangePhotoWindow::ChangePhotoWindow(const QPixmap &originalPixmap, QWidget *parent)
    : BaseWindow(parent), ui(new Ui::ChangePhotoWindow),
    originalPixmap(originalPixmap),
    scene(new QGraphicsScene(this)),
    pixmapItem(nullptr),
    maskItem(nullptr),
    circleItem(nullptr),
    resizeHandle(nullptr),
    isResizing(false)
{
    ui->setupUi(this);
    ui->editPhotoGraphicsView->setScene(scene);
    ui->editPhotoGraphicsView->setRenderHint(QPainter::Antialiasing);
    ui->editPhotoGraphicsView->setMouseTracking(true);

    displayPixmap = originalPixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    pixmapItem = scene->addPixmap(displayPixmap);

    ConnectSlots();
    CreateResizableCircle();
    UpdateMask();
}

ChangePhotoWindow::~ChangePhotoWindow()
{
    delete scene;
    delete ui;
}

void ChangePhotoWindow::ConnectSlots()
{
    connect(scene, &QGraphicsScene::changed, this, &ChangePhotoWindow::UpdateMask);
}

void ChangePhotoWindow::DisconnectSlots()
{

}

void ChangePhotoWindow::CreateResizableCircle()
{
    circleItem = scene->addEllipse(0, 0, 150, 150, QPen(Qt::white, 2));
    circleItem->setBrush(Qt::NoBrush);
    circleItem->setPos(displayPixmap.rect().center().x() - 75,
                       displayPixmap.rect().center().y() - 75);
    circleItem->setFlag(QGraphicsItem::ItemIsMovable);
    circleItem->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    circleItem->setZValue(2);

    resizeHandle = scene->addEllipse(0, 0, 10, 10, QPen(Qt::white), Qt::white);
    resizeHandle->setParentItem(circleItem);
    resizeHandle->setPos(140, 140);
    resizeHandle->setFlag(QGraphicsItem::ItemIsSelectable);
    resizeHandle->setZValue(3);

    ui->editPhotoGraphicsView->viewport()->installEventFilter(this);
}

QVariant ChangePhotoWindow::ItemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange && circleItem)
    {
        QPointF newPos = value.toPointF();

        qreal x = qBound(0.0, newPos.x(), displayPixmap.width() - circleItem->rect().width());
        qreal y = qBound(0.0, newPos.y(), displayPixmap.height() - circleItem->rect().height());

        return QPointF(x, y);
    }
    return value;
}

QPixmap ChangePhotoWindow::GetCroppedPixmap() const
{
    return croppedPixmap;
}

bool ChangePhotoWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->editPhotoGraphicsView->viewport())
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent     *mouseEvent = static_cast<QMouseEvent*>(event);
            QPointF         scenePos = ui->editPhotoGraphicsView->mapToScene(mouseEvent->pos());
            QGraphicsItem   *item = scene->itemAt(scenePos, ui->editPhotoGraphicsView->transform());

            if (item == resizeHandle)
            {
                isResizing = true;
                return true;
            }
            if (item == circleItem)
            {
                isDragging = true;
                dragOffset = scenePos - circleItem->pos();
                return true;
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            isResizing = false;
            isDragging = false;
            return true;
        }
        else if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent     *mouseEvent = static_cast<QMouseEvent*>(event);
            QPointF         scenePos = ui->editPhotoGraphicsView->mapToScene(mouseEvent->pos());

            if (isResizing)
            {
                QPointF     circlePos = circleItem->pos();
                qreal       maxSize = qMin(displayPixmap.width() - circlePos.x(), displayPixmap.height() - circlePos.y());
                qreal       newSize = qMax(scenePos.x() - circlePos.x(), scenePos.y() - circlePos.y());
                newSize = qBound(50.0, newSize, maxSize);

                circleItem->setRect(0, 0, newSize, newSize);
                resizeHandle->setPos(newSize - 10, newSize - 10);

                UpdateMask();
                return true;
            }
            else if (isDragging)
            {
                qreal       newX = scenePos.x() - dragOffset.x();
                qreal       newY = scenePos.y() - dragOffset.y();
                qreal       w = circleItem->rect().width();
                qreal       h = circleItem->rect().height();

                newX = qBound(0.0, newX, displayPixmap.width() - w);
                newY = qBound(0.0, newY, displayPixmap.height() - h);

                circleItem->setPos(newX, newY);
                UpdateMask();
                return true;
            }
        }
    }
    return BaseWindow::eventFilter(watched, event);
}

void ChangePhotoWindow::on_applyButton_clicked()
{
    if (!circleItem) return;

    qreal       circleWidth = circleItem->rect().width();
    qreal       circleHeight = circleItem->rect().height();

    QRectF      circlePos(circleItem->pos().x(), circleItem->pos().y(), circleWidth, circleHeight);

    qreal       xRatio = (qreal)originalPixmap.width() / displayPixmap.width();
    qreal       yRatio = (qreal)originalPixmap.height() / displayPixmap.height();

    QRectF      sourceRect(
        circlePos.x() * xRatio,
        circlePos.y() * yRatio,
        circlePos.width() * xRatio,
        circlePos.height() * yRatio
        );

    QPixmap     cropped = originalPixmap.copy(sourceRect.toRect());

    cropped = cropped.scaled(150, 150, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QPixmap     circularPixmap(150, 150);
    circularPixmap.fill(Qt::transparent);

    QPainter    painter(&circularPixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    QRect       targetRect(0, 0, 150, 150);
    if (cropped.width() > 150 || cropped.height() > 150)
    {
        targetRect.moveLeft((150 - cropped.width()) / 2);
        targetRect.moveTop((150 - cropped.height()) / 2);
    }
    painter.drawPixmap(targetRect, cropped, cropped.rect());

    QPainterPath path;
    path.addEllipse(0, 0, 150, 150);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.fillPath(path, Qt::white);

    painter.end();

    croppedPixmap = circularPixmap;
    accept();
}

void ChangePhotoWindow::UpdateMask()
{
    scene->blockSignals(true);

    if (maskItem)
    {
        scene->removeItem(maskItem);
        delete maskItem;
    }

    QPixmap mask(displayPixmap.size());
    mask.fill(Qt::transparent);

    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(mask.rect(), QColor(0, 0, 0, 150));

    if (circleItem)
    {
        QPainterPath path;
        path.addEllipse(circleItem->pos().x(), circleItem->pos().y(),
                        circleItem->rect().width(), circleItem->rect().height());
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillPath(path, Qt::transparent);
    }
    painter.end();

    maskItem = scene->addPixmap(mask);
    maskItem->setZValue(1);

    scene->blockSignals(false);
}
