#ifndef PAGEGRAPHICSITEM_H
#define PAGEGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include "types.h"

class QImage;
class QGraphicsView;

class PageGraphicsItem : public QGraphicsItem
{
public:

    enum PageItemType {
        PAGE_VIEW, THUMBONAILS_VIEW
    };

    PageGraphicsItem(QImage*, PageItemType type = PageGraphicsItem::PAGE_VIEW, QObject* receiver = 0, int_t pageNumber = 1);

    int_t getHeight() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);

private:

    QImage*                 mp_image;
    QObject*                mp_receiver;
    int_t                   m_initialHeight;
    double_t                m_zoom;
    int_t                   m_pageNumber;
    QGraphicsView*          mp_ParentView;
    PageItemType            m_itemType;
};

#endif // PAGEGRAPHICSITEM_H
