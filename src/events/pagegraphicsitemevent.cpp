#include "pagegraphicsitemevent.h"

PageGraphicsItemEvent::PageGraphicsItemEvent(PageGraphicsItem::PageItemType _senderType, int_t thumbonailNumber) :
    QEvent((Type)(QEvent::User + 1))
{
    m_thumbonailNumber = thumbonailNumber;
    m_sender = _senderType;
    m_scaleFactor = 1;
}

int_t PageGraphicsItemEvent::getThumbonailNumber() const
{
    return m_thumbonailNumber;
}

PageGraphicsItem::PageItemType PageGraphicsItemEvent::getSenderType() const
{
    return m_sender;
}

void PageGraphicsItemEvent::setScaleFactor(double_t _scaleFactor)
{
    m_scaleFactor = _scaleFactor;
}

double_t PageGraphicsItemEvent::getScaleFactor() const
{
    return m_scaleFactor;
}
