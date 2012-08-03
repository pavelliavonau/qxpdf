#ifndef LOADER_H
#define LOADER_H

#include "types.h"

class QImage;
class SplashBitmap;
class PDFDoc;

class Loader
{
public:
    Loader(const_c_str_t);
    virtual ~Loader();    

    ThumbonailsListPtr_t getThumbonails();
    QImage*             getPage(int_t number);
private:

    ThumbonailsListPtr_t        mp_thumbonails;
    QImage*                     mp_page;
    PDFDoc*                     mp_doc;

};

#endif // LOADER_H
