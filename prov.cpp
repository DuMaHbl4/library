#include "main.h"
#include <iostream>
#include <fstream>
using namespace std;

int prov(char* data)
  {
  int sh, pol, kol;
  int p=0;
  int i;
  book *beg, *pBk, *end;
  string tmp;
  ifstream f;
  f.open(data);
  f >> p;
  if(f==NULL && p==0)
    {
    f.close();
    cout << "Файла нет или он пуст" << endl << endl << "Что делать дальше?" << endl << "1. Добавить информацию о библиотеке" << endl << "2. Закрыть программу" << endl;
    while(1)
      {
      while(1)
        {
        cin >> i;
        if(cin.fail())
          {
          cin.clear();
          getline(cin, tmp);
          cout << "Введите 1 или 2" << endl;
          }
        else break;
        }
      switch(i)
        {
        case 1:
          {
          while(1)
            {
            cout << "Введите число шкафов: ";
            cin >> sh;
            if(cin.fail())
              {
              cin.clear();
              getline(cin, tmp);
              }
            else break;
            }
          while(1)
            {
            cout << "Введите число полок в шкафу: ";
            cin >> pol;
            if(cin.fail())
              {
              cin.clear();
              getline(cin, tmp);
              }
            else break;
            }
          while(1)
            {
            cout << "Введите число книг, помещающихся на одной полке: ";
            cin >> kol;
            if(cin.fail())
              {
              cin.clear();
              getline(cin, tmp);
              }
            else break;
            }
          ofstream f;
          f.open(data);
          f << 0 << ' '  << sh << ' ' << pol << ' ' << kol;
          f.close();
          return (0);
          }    
        case 2:
          return(1);      
        default:
          cout << "Некоректный ввод " << endl;  
        }
      }
    }
  }
