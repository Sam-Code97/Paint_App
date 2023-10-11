
#include "studentfill1.h"
#include <QDebug>

#include <algorithm>

const char* nameOfStudent1(){
    return "Sam Aliwa";
}

void recursiveFull(int r, int k, IDrawingParent *pImage, QColor colorOld, QColor colorNew){
    // behöver ej implementeras

}


void recursiveFill(int r, int k, IDrawingParent *pImage, QColor colorOld, QColor colorNew){


    // TODO
    // (Detta är ett uppdrag i chapter 2, rekursion)
    // Nedanstående kod är helt felaktig
    // Men den avser att visa hur man använder pImage
    //    while (pImage->isInside(r,k) &&  pImage->pixel(r,k) == colorOld) {
    //        pImage->setPixel(r,k, colorNew);
    //        k+=1;
    //    }


    if(pImage->isInside(r, k) && pImage->pixel(r, k) == colorOld){
        pImage->setPixel(r, k, colorNew);
        recursiveFill(r, k+1, pImage, colorOld, colorNew);
        recursiveFill(r, k-1, pImage, colorOld, colorNew);
        recursiveFill(r+1, k, pImage, colorOld, colorNew);
        recursiveFill(r-1, k, pImage, colorOld, colorNew);
    }
    else return;

    //    if(!pImage->isInside(r, k)
    //            || pImage->pixel(r, k) != colorOld
    //            || colorOld == colorNew)
    //        return;
    //    pImage->setPixel(r, k, colorNew);
    //    recursiveFill(r, k+1, pImage, colorOld, colorNew);
    //    recursiveFill(r, k-1, pImage, colorOld, colorNew);
    //    recursiveFill(r+1, k, pImage, colorOld, colorNew);
    //    recursiveFill(r-1, k, pImage, colorOld, colorNew);
}
