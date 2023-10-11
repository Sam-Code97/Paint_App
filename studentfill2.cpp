// OBS OBS OBS OBS OBS OBS
// Denna fil tillhör INTE rekursionslabbarna, utan en senare laboration!!!!


#include "studentfill2.h"
#include <QDebug>
#include <deque>   // double-ended-que, har du tillåtelse att använda här!
#include <vector>

using namespace std;


const char* nameOfStudent2(){
    return "Sam Aliwa";
}

// Nedanstående struct kan användas för att lagra koordinater
struct RK {
    RK(int r, int k): _r(r),_k(k) {}
    int _r;
    int _k;
};

float *m_pArr;
int    m_size;
int    m_capacity;


// Denna metod visar bara hur man använder en sk deque
void exempelkodDemonstrerarDeque(){

    deque<RK> minQueue;


    qDebug() <<"Demo: vi använder minQueue som en STACK";
    qDebug() <<"      med push_back back och pop_back";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
       RK rk = minQueue.back();
       minQueue.pop_back();
       qDebug() << "vi poppar: (" << rk._r << ", " << rk._k << ")";
    }

    qDebug() <<"Demo: vi använder nu minQueue som en FIFO";
    qDebug() <<"      med push_back front och pop_front";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
       RK rk = minQueue.front();
       minQueue.pop_front();
       qDebug() << "vi pop_frontar: (" << rk._r << ", " << rk._k << ")";
    }

}



void nonRecursiveFillStack(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){

    vector<RK> toDoList;
    QColor clickedColor = im->pixel(r, k);
    toDoList.push_back(RK(r, k));
    while(!toDoList.empty()){

        if(im->isInside(toDoList.back()._r, toDoList.back()._k)
            && im->pixel(toDoList.back()._r, toDoList.back()._k) == clickedColor)
        {
            im->setPixel(toDoList.back()._r, toDoList.back()._k, colorNew);
            RK rk = RK(toDoList.back()._r, toDoList.back()._k);
            toDoList.pop_back();
            toDoList.push_back(RK(rk._r+1, rk._k));
            toDoList.push_back(RK(rk._r-1, rk._k));
            toDoList.push_back(RK(rk._r, rk._k+1));
            toDoList.push_back(RK(rk._r, rk._k-1));
        }
        else toDoList.pop_back();
    }
}


void nonRecursiveFillFifo(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){


    deque<RK> toDoList;
    QColor clickedColor = im->pixel(r, k);
    toDoList.push_front(RK(r, k));

    while(!toDoList.empty()){
        if(im->isInside(toDoList.front()._r, toDoList.front()._k)
            && im->pixel(toDoList.front()._r, toDoList.front()._k) == clickedColor)
        {
            im->setPixel(toDoList.front()._r, toDoList.front()._k, colorNew);
            toDoList.push_back(RK(toDoList.front()._r+1, toDoList.front()._k));
            toDoList.push_back(RK(toDoList.front()._r-1, toDoList.front()._k));
            toDoList.push_back(RK(toDoList.front()._r, toDoList.front()._k+1));
            toDoList.push_back(RK(toDoList.front()._r, toDoList.front()._k-1));
        }
        toDoList.pop_front();
    }
}
