#include "square.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void Square::block()
{
    this->blockSignals(true);
}

void Square::no_block()
{
    this->blockSignals(false);
}


void Square::initpow()
{

    emit sq1(sqnum+10);
    emit sq2(sqnum+20);
}



void Square::st_green(int g)
{
    if(stgreen<g)
    {
        emit izmenit_score1(g);
        stgreen=g;
    }

}


void Square::st_red(int r)
{
    if(stred<r)
    {
        emit izmenit_score2(r);
        stred=r;
    }

}



void Square::izmenit_sqnum(bool b)
{

    --sqnum;
    x+=1;
    emit sq1(sqnum+10);
    emit sq2(sqnum+20);
   if(sqnum==0 && !b)
    {
        y = -10;
        sqpall.setColor(psq->backgroundRole(), Qt::green);
        psq->setPalette(sqpall);
        psq->setAutoFillBackground(true);
        QObject::connect(this, SIGNAL(greenplus(int)), this, SLOT(st_green(int)));
        emit greenplus(++green);
        if(red+green == 25)
        {
            if(red>green)
                emit win_c();
            else emit win_p();
        }
    }
    if(x==2 && y<0)
    {
        x = 0;
        y = 0;
        return;
    }
    if(sqnum==0 && b )
    {
        y = 10;

        sqpall.setColor(psq->backgroundRole(), Qt::red);
        psq->setPalette(sqpall);
        psq->setAutoFillBackground(true);
        QObject::connect(this, SIGNAL(redplus(int)), this, SLOT(st_red(int)));
        emit redplus(++red);
        if(red+green == 25)
        {
            if(red>green)
                emit win_c();
            else emit win_p();
        }
    }
    if(x==2 && y>0)
    {
       // emit proverka();
        y = 0;
        x = 0;
        emit hod_compa2();
        return;
    }
    if(!b && x==2 && y==0)
    {
        x=0;
        emit hod_compa2();
        return;
    }
    if(b && x==2 && y==0)
    {
        x=0;
        return;
    }


}

void Square::pokazat_score()
{
    emit izmenit_score1(green);
    emit izmenit_score2(red);
}

void Square::nullsq()
{
    red = 0;
    green = 0;
    emit izmenit_score1(green);
    emit izmenit_score2(red);

}

Square::Square(QWidget *p):QWidget(p)
{
    psq = new QWidget(p);
    srand(time(NULL));
    if((rand()+sq_i)%2)
    {
        sqpall.setColor(psq->backgroundRole(), Qt::green);
        green++;
    }
    else
    {
        sqpall.setColor(psq->backgroundRole(), Qt::red);
        red++;
    }
    psq->setPalette(sqpall);
    psq->resize(30, 30);
    psq->setAutoFillBackground(true);
    sq_i++;
}

QWidget *Square::operator ->()
{
    return psq;
}

int Square::setgreen(){ return green;}
int Square::setred(){ return red;}

QPalette *Square::setpall()
{
    return &sqpall;
}

void Square::whitepall()
{
   red=0;
   green=0;
   sqpall.setColor(psq->backgroundRole(), Qt::white);
   psq->setPalette(sqpall);
   psq->setAutoFillBackground(true);

}
