#include "square.h"
#include "stick_class.h"

int k;
int Square::sq_i;
int Square::red;
int Square::green;
Stick *Stick::dopstick;
int Square::stgreen;
int Stick::palochek_ostalos;
 Stick *Stick::stm[40];
int Square::stred;
 int Square::x = 0;

 int Square::y = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QWidget start_wgt(&w);
    QWidget score_wgt(&w);
    QWidget play1(&w);
    QWidget play2(&w);
    QWidget score1_wgt(&w);
    QWidget score2_wgt(&w);

    QWidget proverka;
    proverka.hide();

    QLabel *win_player = new QLabel("<h4><center>Игрок</center></h4>",&w);
    QLabel *win_comp = new QLabel("<h4>Компьютер</h4>", &w);
    win_player->setStyleSheet("color: rgb(0,128,0)");
    win_comp->setStyleSheet("color: rgb(255,0,0)");
    win_comp->hide();
    win_player->hide();
    QLabel *win_banner = new QLabel("<h4>Выиграл!</h4>",&w);
    win_banner->hide();
    win_banner->move(230,50);
    win_comp->move(150,50);
    win_player->move(150,50);

    QLabel *ostalos_hodov = new QLabel("40", &w);
    ostalos_hodov->move(255, 50);
    ostalos_hodov->hide();
    ostalos_hodov->setStyleSheet("color: rgb(0, 0 ,255)");

    QWidget what_first;
    QLabel *what_lbl = new QLabel("<h4><center>Кто ходит первым?</center></h4>");
    QPushButton *player = new QPushButton("ИГРОК");
    QPushButton *comp = new QPushButton("КОМПЬЮТЕР");
    QHBoxLayout *h_layout = new QHBoxLayout;
    h_layout->addWidget(player);
    h_layout->addWidget(comp);
    h_layout->setSpacing(10);
    h_layout->setMargin(5);
    QVBoxLayout *v_layout = new QVBoxLayout;
    v_layout->addWidget(what_lbl);
    v_layout->addLayout(h_layout);
    v_layout->setSpacing(5);
    what_first.setLayout(v_layout);
    what_first.move(425,420);

    QWidget score_ok;
    QLabel *score_ok_lbl = new QLabel("<h4><center>Подтвердите ход</center></h4>");
    QPushButton *score_yes = new QPushButton("Ok");
    QPushButton *score_no = new QPushButton("Нет");

    QHBoxLayout *h_layout2 = new QHBoxLayout;
    h_layout2->addWidget(score_yes);
    h_layout2->addWidget(score_no);
    h_layout2->setSpacing(10);
    h_layout2->setMargin(5);
    QVBoxLayout *v_layout2 = new QVBoxLayout;
    v_layout2->addWidget(score_ok_lbl);
    v_layout2->addLayout(h_layout2);
    v_layout2->setSpacing(5);
    score_ok.setLayout(v_layout2);
    score_ok.move(660,300);

    score_ok.hide();


    QLabel *score_to_end = new QLabel("<h4>Осталось ходов:</h4>", &w);
    score_to_end->move(150,50);
    score_to_end->hide();

    QLabel *gamer_11 = new QLabel("<h4>Игрок</h4>", &w);
    QLabel *gamer_12 = new QLabel("<h4>Компьютер</h4>", &w);

    gamer_11->hide();
    gamer_12->hide();

    gamer_11->move(36,150);
    gamer_12->move(330,150);

    gamer_11->setStyleSheet("color: rgb(0,128,0)");
    gamer_12->setStyleSheet("color: rgb(255,0,0)");

    QString player_str = "ИГРОК";
    QString comp_str = "КОМПЬЮТЕР";
    QPushButton *start = new QPushButton("НАЧАТЬ", &start_wgt);
    QLabel *player1_lbl = new QLabel( "<h4><center>PLAYER_1</center></h4>", &play1);
    QLabel *player2_lbl = new QLabel( "<h4><center>PLAYER_2</center></h4>", &play2);
    QLabel *score_lbl = new QLabel("<CENTER><H4>SCORE<H4></CENTER>", &score_wgt);
    QLabel *score1 = new QLabel(&score1_wgt);
    QLabel *score2 = new QLabel(&score2_wgt);

    QString str1;
    QString str2;


    start_wgt.move(170,50);
    play1.move(20,150);
    play2.move(330,150);
    score_wgt.move(195,336);
    score1_wgt.move(190,366);
    score2_wgt.move(228,366);

    QPalette pall = start->palette();
    pall.setColor(QPalette::ButtonText, Qt::blue);
    start->setPalette(pall);

    player1_lbl->setStyleSheet("color: rgb(0,128,0)");
    player2_lbl->setStyleSheet("color: rgb(255,0,0)");
    score_lbl->setStyleSheet("color: rgb(0,0,255)");
    score1->setStyleSheet("color: rgb(0,128,0)");
    score2->setStyleSheet("color: rgb(255,0,0)");

    pall = score_lbl->palette();
    pall.setColor(QPalette::Text , Qt::blue);
    score_lbl->setPalette(pall);
    score_lbl->setStyleSheet("color: rgb(0,0,255)");

    QWidget game_field(&w);
    game_field.resize(216,216);
    game_field.move(100,100);

    Square sq[25]={&game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field,
                   &game_field
                  };
    str1.setNum(sq[1].setgreen());
    str2.setNum(sq[1].setred());
    score1->setText(str1);
    score2->setText(str2);

  Stick_v stv[30]={&game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field
                 };

  Stick_h sth[30]={&game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field,
                  &game_field
                 };
  int i,j, n, y;
  i=n=0;
  for(;i<6;++i)
  {
      y = 5 + 40*i;
      for(j=0;j<5;++j)
      {
          double x = 13 + 40*j;
          sth[n++]->move(x,y);
      }
  }
  n=0;
  for(i=0;i<5;++i)
  {
      y = 13 + 40*i;
      for(j=0;j<6;++j)
      {
          double x = 5 + 40*j;
          stv[n++]->move(x,y);
      }
  }

  n=0;
  for(i=0;i<5;++i)
  {
      y = 13 + 40*i;
      for(j=0;j<5;++j)
      {
          double x = 13 + 40*j;
          sq[n++]->move(x,y);
      }
  }


  for(i=5, j=0;i<25;++i, ++j)
       Stick::stm[j] = &sth[i];
   k=20;


   Stick::stm[k++] = &stv[1];
   Stick::stm[k++] = &stv[2];
   Stick::stm[k++] = &stv[3];
   Stick::stm[k++] = &stv[4];
   Stick::stm[k++] = &stv[7];
   Stick::stm[k++] = &stv[8];
   Stick::stm[k++] = &stv[9];
   Stick::stm[k++] = &stv[10];
   Stick::stm[k++] = &stv[13];
   Stick::stm[k++] = &stv[14];
   Stick::stm[k++] = &stv[15];
   Stick::stm[k++] = &stv[16];
   Stick::stm[k++] = &stv[19];
   Stick::stm[k++] = &stv[20];
   Stick::stm[k++] = &stv[21];
   Stick::stm[k++] = &stv[22];
   Stick::stm[k++] = &stv[25];
   Stick::stm[k++] = &stv[26];
   Stick::stm[k++] = &stv[27];
   Stick::stm[k++] = &stv[28];

  sq[0].sqnum=2;
  sq[4].sqnum=2;
  sq[20].sqnum=2;
  sq[24].sqnum=2;
  for(i=1;i<4;i++)
      sq[i].sqnum=3;
  for(i=21;i<24;i++)
      sq[i].sqnum=3;
  for(i=5;i<16;i+=5)
      sq[i].sqnum=3;
  for(i=9;i<20;i+=5)
      sq[i].sqnum=3;
  for(i=0;i<3;i++)
      for(j=0;j<3;j++)
          sq[6+j+5*i].sqnum=4;


  // Определить, кто ходит первый
  QObject::connect( start, SIGNAL(clicked(bool)), &what_first, SLOT(show())  );
  QObject::connect( player, SIGNAL(clicked(bool)), &what_first, SLOT(close()) );
  QObject::connect( comp, SIGNAL(clicked(bool)), &what_first, SLOT(close()) );

  // Счет 0 0
  QObject::connect( player, SIGNAL(clicked(bool)), sq, SLOT(nullsq()) );
  QObject::connect( comp, SIGNAL(clicked(bool)), sq, SLOT(nullsq()) );


  // После выбора того, кто первый ходит, можно нажимать на палочки
  for(i=0;i<30;++i)
  {

      QObject::connect(player, SIGNAL(clicked(bool)),&stv[i], SLOT(noblock()));
       QObject::connect(player, SIGNAL(clicked(bool)),&sth[i], SLOT(noblock()));
       QObject::connect(comp, SIGNAL(clicked(bool)),&stv[i], SLOT(noblock()));
        QObject::connect(comp, SIGNAL(clicked(bool)),&sth[i], SLOT(noblock()));
  }

  for(i=0;i<25;++i)
      QObject::connect(start, SIGNAL(clicked(bool)), &sq[i], SLOT(initpow()));



  // Убирается кнопка начать
  QObject::connect( player, SIGNAL(clicked(bool)), start, SLOT(close()) );
  QObject::connect( comp, SIGNAL(clicked(bool)), start, SLOT(close()) );

  // Стираются надписи player1 и player2
  QObject::connect( player, SIGNAL(clicked(bool)), player1_lbl, SLOT(close()) );
  QObject::connect( player, SIGNAL(clicked(bool)), player2_lbl , SLOT(close()) );
  QObject::connect( comp, SIGNAL(clicked(bool)), player1_lbl, SLOT(close()) );
  QObject::connect( comp, SIGNAL(clicked(bool)), player2_lbl , SLOT(close()) );

  // Высвечивается: осталось ходов
  QObject::connect(player, SIGNAL(clicked(bool)), score_to_end, SLOT(show()));
  QObject::connect(comp, SIGNAL(clicked(bool)), score_to_end, SLOT(show()));


  // Появляются надписи компьютер игрок
  QObject::connect(player, SIGNAL(clicked(bool)),gamer_11, SLOT(show()));
  QObject::connect(player, SIGNAL(clicked(bool)), gamer_12, SLOT(show()));
  QObject::connect(comp, SIGNAL(clicked(bool)), gamer_11, SLOT(show()));
  QObject::connect(comp, SIGNAL(clicked(bool)), gamer_12, SLOT(show()));


  //  Осталось ходов: 40
  QObject::connect(player, SIGNAL(clicked(bool)),ostalos_hodov, SLOT(show()));
  QObject::connect(comp, SIGNAL(clicked(bool)), ostalos_hodov, SLOT(show()));







  // После выбора, кто ходит первым, квадраты становятся белыми
  for(i=0;i<25;++i)
  {
     QObject::connect(player, SIGNAL(clicked(bool)),&sq[i], SLOT(whitepall()));
     QObject::connect(comp, SIGNAL(clicked(bool)),&sq[i], SLOT(whitepall()));
  }


  // Квадраты внутри становятся серыми
  for(i=0;i<5;++i)
      for(j=1;j<5;++j)
      {
          QObject::connect(player, SIGNAL(clicked(bool)),&stv[j+6*i], SLOT(graypall()));
          QObject::connect(comp, SIGNAL(clicked(bool)),&stv[j+6*i], SLOT(graypall()));

          QObject::connect(stv[j+6*i].pst , SIGNAL(clicked()), &stv[j+6*i] , SLOT(memorybutton()));




          QObject::connect(stv[j+6*i].pst , SIGNAL(clicked()), &score_ok , SLOT(show()));
       }
  for(i=5;i<25;++i)
  {
      QObject::connect(player, SIGNAL(clicked(bool)),&sth[i], SLOT(graypall()));
      QObject::connect(comp, SIGNAL(clicked(bool)),&sth[i], SLOT(graypall()));


      QObject::connect(sth[i].pst , SIGNAL(clicked(bool)), &sth[i] , SLOT(memorybutton()));




      QObject::connect(sth[i].pst , SIGNAL(clicked(bool)), &score_ok , SLOT(show()));

  }

  // Убрать окно подтверждения хода
  QObject::connect(score_yes, SIGNAL(clicked(bool)), &score_ok, SLOT(close()) );
  QObject::connect(score_no, SIGNAL(clicked(bool)), &score_ok, SLOT(close()) );


  // Палочка становится черной
  QObject::connect(score_yes, SIGNAL(clicked(bool)), &stv[1] , SLOT(blackpall()) );  // ?
  QObject::connect(score_no, SIGNAL(clicked(bool)), &stv[1] , SLOT(nulldopstickslot()) );


  /*for(i=0;i<30;++i)  // ?
  {
      QObject::connect(&stv[i], SIGNAL(score_minus(int)),ostalos_hodov, SLOT(setNum(int)));
      QObject::connect(&sth[i], SIGNAL(score_minus(int)),ostalos_hodov, SLOT(setNum(int)));


  } */

  for(i=0;i<5;++i)
      for(j=1;j<5;++j)
          QObject::connect(&stv[j+6*i], SIGNAL(score_minus(int)),ostalos_hodov, SLOT(setNum(int)));
  for(i=5;i<25;++i)
  {
      QObject::connect(&sth[i], SIGNAL(score_minus(int)),ostalos_hodov, SLOT(setNum(int)));
  }


  // Устанаввливается связь палочек и квадратов
  for(i=5;i<25;++i)
  {
      QObject::connect(&sth[i], SIGNAL(sig_sqminus(bool)),&sq[i], SLOT(izmenit_sqnum(bool)));
      QObject::connect(&sth[i], SIGNAL(sig_sqminus(bool)), &sq[i-5], SLOT(izmenit_sqnum(bool)));

  }
  for(i=1;i<5;++i)
  {
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i], SLOT(izmenit_sqnum(bool)));
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-1], SLOT(izmenit_sqnum(bool)));
  }
  for(i=7;i<11;i++)
  {
     QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-2], SLOT(izmenit_sqnum(bool)));
     QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-1], SLOT(izmenit_sqnum(bool)));
  }
  for(i=13;i<17;i++)
  {
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-3], SLOT(izmenit_sqnum(bool)));
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-2], SLOT(izmenit_sqnum(bool)));
  }
  for(i=19;i<23;i++)
  {
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-3], SLOT(izmenit_sqnum(bool)));
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-4], SLOT(izmenit_sqnum(bool)));
  }
  for(i=25;i<29;i++)
  {
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-5], SLOT(izmenit_sqnum(bool)));
      QObject::connect(&stv[i], SIGNAL(sig_sqminus(bool)), &sq[i-4], SLOT(izmenit_sqnum(bool)));
  }

  for(i=0;i<25;++i)
  {
      QObject::connect(&sq[i], SIGNAL(izmenit_score1(int)), score1, SLOT(setNum(int)));
      QObject::connect(&sq[i], SIGNAL(izmenit_score2(int)), score2, SLOT(setNum(int)));
  }

    // Силы палочек
  for(i=0;i<20;++i)
      QObject::connect(&sq[i], SIGNAL(sq1(int)), &sth[i+5], SLOT(powerslot(int)) );
  for(i=5;i<25;++i)
      QObject::connect(&sq[i], SIGNAL(sq2(int)), &sth[i], SLOT(powerslot(int)) );

  // Первая строка
  for(i=0;i<4;++i)
      QObject::connect(&sq[i], SIGNAL(sq1(int)), &stv[i+1], SLOT(powerslot(int)) );
  for(i=1;i<5;++i)
      QObject::connect(&sq[i], SIGNAL(sq2(int)), &stv[i], SLOT(powerslot(int)) );
   // Вторая строка
   for(i=5;i<9;++i)
         QObject::connect(&sq[i], SIGNAL(sq1(int)), &stv[i+2], SLOT(powerslot(int)) );
   for(i=6;i<10;++i)
        QObject::connect(&sq[i], SIGNAL(sq2(int)), &stv[i+1], SLOT(powerslot(int)) );
   // Третья строка
   for(i=10;i<14;++i)
         QObject::connect(&sq[i], SIGNAL(sq1(int)), &stv[i+3], SLOT(powerslot(int)) );
   for(i=11;i<15;++i)
        QObject::connect(&sq[i], SIGNAL(sq2(int)), &stv[i+2], SLOT(powerslot(int)) );
   // Четвертая строка
   for(i=15;i<19;++i)
         QObject::connect(&sq[i], SIGNAL(sq1(int)), &stv[i+4], SLOT(powerslot(int)) );
   for(i=16;i<20;++i)
        QObject::connect(&sq[i], SIGNAL(sq2(int)), &stv[i+3], SLOT(powerslot(int)) );
   // Пятая строка
   for(i=20;i<24;++i)
         QObject::connect(&sq[i], SIGNAL(sq1(int)), &stv[i+5], SLOT(powerslot(int)) );
   for(i=21;i<25;++i)
        QObject::connect(&sq[i], SIGNAL(sq2(int)), &stv[i+4], SLOT(powerslot(int)) );


   for(i=0;i<25;++i)
   {

       QObject::connect(&sq[i], SIGNAL(hod_compa2()), &stv[3], SLOT(hod_compaslot()));
   }

   for(i=0;i<25;++i)
   QObject::connect(&sq[i], SIGNAL(proverka()), &proverka, SLOT(show()));

   QObject::connect(comp, SIGNAL(clicked(bool)), &sq[3], SIGNAL(hod_compa2()));


   for(i=0;i<25;++i)
   {
       QObject::connect(&sq[i], SIGNAL(win_c()), win_comp, SLOT(show()));
       QObject::connect(&sq[i], SIGNAL(win_p()), win_player, SLOT(show()));
       QObject::connect(&sq[i], SIGNAL(win_c()), win_banner, SLOT(show()));
       QObject::connect(&sq[i], SIGNAL(win_p()), win_banner, SLOT(show()));
       QObject::connect(&sq[i], SIGNAL(win_c()), score_to_end, SLOT(close()));
       QObject::connect(&sq[i], SIGNAL(win_p()), score_to_end, SLOT(close()));
       QObject::connect(&sq[i], SIGNAL(win_c()), ostalos_hodov, SLOT(close()));
       QObject::connect(&sq[i], SIGNAL(win_p()), ostalos_hodov, SLOT(close()));

   }

    w.show();
    w.setFixedSize(416,416);

    return a.exec();
}
