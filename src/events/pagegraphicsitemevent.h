#ifndef PAGEGRAPHICSITEMEVENT_H
#define PAGEGRAPHICSITEMEVENT_H

#include <QEvent>
#include "types.h"
#include "pagegraphicsitem.h"

class PageGraphicsItemEvent : public QEvent
{

public:
    explicit PageGraphicsItemEvent(PageGraphicsItem::PageItemType type, int_t thumbonailNumber = 0);
    int_t getThumbonailNumber() const;
    PageGraphicsItem::PageItemType getSenderType() const;
    void setScaleFactor(double_t);
    double_t getScaleFactor() const;

private:
    int_t                           m_thumbonailNumber;
    PageGraphicsItem::PageItemType  m_sender;
    double_t                        m_scaleFactor;

};

#endif // PAGEGRAPHICSITEMEVENT_H
