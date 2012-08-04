#ifndef TYPES_H
#define TYPES_H

#include <QList>

class   QImage;
class   DocumentPDF;

typedef     bool    bool_t;
typedef     char*   c_str_t;
typedef     const char*   const_c_str_t;
typedef     int    int_t;
typedef     long    long_t;
typedef     double    double_t;
typedef     QList<QImage *>*    ThumbonailsListPtr_t;
typedef     QList<QImage *>::iterator    ThumbonailsIterator;
typedef     QList<DocumentPDF*>*    DocumentsPtr_t;
typedef     QList<DocumentPDF*>::iterator    DocumentsIterator;


/* constants */
const int SPACES_BETWEEN_THUMBONAILS = 10;
const int THUMBONAIL_RESOLUTION = 20;
const int PAGE_RESOLUTION = 120;
const int THUMBONAIL_VIEW_LOADING_SCALE = 1;
const int THUMBONAIL_VIEW_CLOSING_SCALE = 1/THUMBONAIL_VIEW_LOADING_SCALE;
const int PAGE_ITEM_INIT_ZOOM = 1;
const int ZOOM_EDIT_INIT = 100;
const double MINIMUM_PAGE_ZOOM = .01;
const int MAXIMUM_PAGE_ZOOM = 2;
const double ZOOM_STEP = .1;
const int MOUSE_WHEEL_STEP = 120;


/* defines */

#ifdef WIN32
    #define     SYSTEM_ENCODING     "Windows-1251"
#elif defined __unix__
    #define     SYSTEM_ENCODING     "UTF-8"
#endif

#endif // TYPES_H
