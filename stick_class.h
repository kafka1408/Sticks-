#ifndef STICK_CLASS_H
#define STICK_CLASS_H

#include <QtWidgets>


// Класс Палочка
class Stick: public QWidget{
    Q_OBJECT
protected:
    QPalette stpall;

public:
    Stick(QWidget *p=0);
    QPushButton *pst;
    static int palochek_ostalos;
    QWidget *operator->();
    QWidget *setbutton();
    static Stick *dopstick;
    static Stick *returndopstick();
    int stickpower;
    int sq1;
    int sq2;
    static Stick *stm[40];
public slots:
    void graypall();
    void blackpall();
    void memorybutton();
    void noblock();
    void nulldopstickslot();
    void powerslot(int sq_num);
    void hod_compaslot();
signals:
    void make_black(bool);
    void nulldopsticksignal();
    void sig_sqminus(bool);
    void score_minus(int);
    void proverka();





};

// Класс Горизонтальная_палочка
class Stick_h: public Stick{
    Q_OBJECT
public:
    Stick_h(QWidget *p=0);

};


// Класс Вертикальная_палочка
class Stick_v: public Stick{
    Q_OBJECT
public:
    Stick_v(QWidget *p=0);

};

#endif // STICK_CLASS_H
