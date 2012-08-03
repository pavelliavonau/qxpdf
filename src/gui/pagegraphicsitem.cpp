#include "pagegraphicsitem.h"
#include <QPainter>
#include <QCoreApplication>
#include "pagegraphicsitemevent.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>


PageGraphicsItem::PageGraphicsItem(QImage* _image, PageItemType type, QObject* receiver, int_t pageNumber)
{
    m_initialHeight = _image->height();    
    m_pageNumber = pageNumber;
    mp_image = _image;
    mp_receiver = receiver;
    m_itemType = type;
}

int_t PageGraphicsItem::getHeight() const
{
    return mp_image->height();
}

void PageGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // TODO: MAYDO if selecred - draw border
    painter->drawImage(QPointF(0, 0), *mp_image);
}

QRectF PageGraphicsItem::boundingRect() const
{
    return mp_image->rect();
}

void PageGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsItem::mousePressEvent(event);

    if (m_itemType == PageGraphicsItem::THUMBONAILS_VIEW)
    {
        QCoreApplication::sendEvent(mp_receiver, new PageGraphicsItemEvent(PageGraphicsItem::THUMBONAILS_VIEW, m_pageNumber));
    }
}

void PageGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (m_itemType == PageGraphicsItem::PAGE_VIEW)
    {
        PageGraphicsItemEvent* pageEventPtr = new PageGraphicsItemEvent(PageGraphicsItem::PAGE_VIEW);

        double_t scaleFactor = 1 + (event->delta() / MOUSE_WHEEL_STEP) * ZOOM_STEP;
        pageEventPtr->setScaleFactor(scaleFactor);
        QCoreApplication::sendEvent(mp_receiver, pageEventPtr);
    }
    else
    {
        QGraphicsItem::wheelEvent(event);
    }
}
