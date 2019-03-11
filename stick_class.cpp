#include "stick_class.h"
#include <cstdlib>
#include <ctime>
#include "square.h"
using namespace std;


 void Stick::hod_compaslot()
 {

     Stick *stdop[36];
     int k = 0;
     int i;
     srand(time(NULL));

     for( i=0;i<40;i++)
     {
         if(!(stm[i]->pst)->signalsBlocked())
         {
             if( ((*stm[i]).stickpower==2)
                     ||((*stm[i]).stickpower==3)
                     ||( (((*stm[i]).stickpower ==4) || ((*stm[i]).stickpower ==5))&& (((*stm[i]).sq1==1) || ((*stm[i]).sq2 ==1))))

             stdop[k++] = stm[i];
         }
     }

     if(k)
     {

         i = rand() % k;
         (*stdop[i]).pst->setStyleSheet("*{background-color: black;}");
         emit stdop[i]->score_minus(--palochek_ostalos);
         (*stdop[i]).pst->blockSignals(true);
         emit stdop[i]->sig_sqminus(true);
         return;
     }
     for( i=0;i<40;i++)
     {
         if(!(stm[i]->pst)->signalsBlocked())
         {
             if( ((stm[i]->stickpower == 7) ||(stm[i]->stickpower == 8) ||((stm[i]->stickpower == 6) && (stm[i]->sq1==3))))
                 stdop[k++] = stm[i];
         }
     }
     if(k)
     {
         i = rand() % k;

         (*stdop[i]).pst->setStyleSheet("*{background-color: black;}");
         emit score_minus(--palochek_ostalos);
         (*stdop[i]).pst->blockSignals(true);
         emit stdop[i]->sig_sqminus(true);

         return;
     }
     for( i=0;i<40;i++)
     {
         if(!(*stm[i]).pst->signalsBlocked())
         {
             if( ((*stm[i]).stickpower == 6)&&((*stm[i]).sq1 ==2))
                 stdop[k++] = stm[i];
         }
     }
     if(k)
     {

         i = rand() % k;

         (*stdop[i]).pst->setStyleSheet("*{background-color: black;}");
         emit score_minus(--palochek_ostalos);
         (*stdop[i]).pst->blockSignals(true);
         emit stdop[i]->sig_sqminus(true);

         return;
     }
     for( i=0;i<40;i++)
     {
         if(!(*stm[i]).pst->signalsBlocked())
         {
             if( ((*stm[i]).stickpower == 4) || ((*stm[i]).stickpower == 5))
                 stdop[k++] = stm[i];
         }
     }
     if(k)
     {

         i = rand() % k;

         (*stdop[i]).pst->setStyleSheet("*{background-color: black;}");
         emit score_minus(--palochek_ostalos);
         (*stdop[i]).pst->blockSignals(true);
         emit stdop[i]->sig_sqminus(true);

         return;
     }

 }


Stick *Stick::returndopstick()
{
    return dopstick;
}

 void Stick::powerslot(int sq_num)
 {

     if(sq_num/10==1)
         sq1 = sq_num % 10;
     if(sq_num/10==2)
         sq2 = sq_num % 10;
     stickpower = sq1 + sq2;
 }

void Stick::nulldopstickslot()
{
    dopstick = NULL;
}


void Stick::memorybutton()
{

    if(dopstick==NULL)
        dopstick = this;
}


void Stick::graypall()
{
      pst->setStyleSheet("*{background-color: rgb(193,193,193);}");
}


QWidget *Stick::setbutton()
{
    return pst;
}

QWidget *Stick::operator->()
{
    return pst;
}


// Конструктор класса Горизонтальная_палочка
Stick_h::Stick_h(QWidget *p): Stick(p)
{
    pst = new QPushButton(p);
    pst->setStyleSheet("*{background-color: black;}");
    pst->resize(30, 6);
    //pst->setAutoFillBackground(true);
    pst->blockSignals(true);


}

Stick::Stick(QWidget *p): QWidget(p)
{
    if(palochek_ostalos<40)
        ++palochek_ostalos;
    sq1=0;
    sq2=0;
}


// Конструктор класс Вертикальная_палочка
Stick_v::Stick_v(QWidget *p): Stick(p)
{
    pst = new QPushButton(p);
    pst->setStyleSheet("*{background-color: black;}");
    pst->resize(6, 30);
    //pst->setAutoFillBackground(true);
    pst->blockSignals(true);


}

void Stick::blackpall()
{
    Stick &st = *dopstick;
    st.pst->setStyleSheet("*{background-color: black;}");
    st.pst->blockSignals(true);
    emit dopstick->sig_sqminus(false);
    emit st.score_minus(--palochek_ostalos);
    dopstick = NULL;
}

void Stick::noblock()
{
    pst->blockSignals(false);
}
