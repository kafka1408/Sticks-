#ifndef SQUARE_H
#define SQUARE_H

#include <QtWidgets>



class Square: public QWidget{
    Q_OBJECT
private:
    //int sqnum;
    QPalette sqpall;
    QWidget *psq;
    static int sq_i;
    static int red;
    static int green;
    static int stgreen;
    static int stred;
public:
    Square(QWidget *p=0);
    QWidget *operator->();
    int setgreen();
    int setred();
    QPalette *setpall();
    int sqnum;
    static bool hod;
    static int x;
    static int y;
public slots:
    void whitepall();
    void nullsq();
    void pokazat_score();
    void izmenit_sqnum(bool b);
    void st_green(int g);
    void st_red(int r);
    void initpow();

    void block();
    void no_block();
signals:
    void izmenit_score1(int);
    void izmenit_score2(int);
    void greenplus(int);
    void redplus(int);

    void sq1(int);
    void sq2(int);
    void hod_compa2();
    void proverka();
    void win_c();
    void win_p();


};



#endif // SQUARE_H
