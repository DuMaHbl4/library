#include "main.h"
#include <fstream>
#include <iostream>
using namespace std;

int book::getNal()
  {
  return nal;
  }

void book::change()
  {
  if(nal==1) nal=0;
  else nal=1;
  }

bool change(char* data, book *beg)
  {
  if (beg==NULL)
    {
    cout << "Библиотека пуста\n";
    return false;
    }
  bool kont=false;
  string tmp;
  book *pBk;
  int i, k;
  int idd;
  int pol, kol;
  ifstream f;
  f.open(data);
  f >> pol >> pol >> pol >> kol;
  f.close();
  cout << "\nВведите цифру от 1 до 3 для выбора соответствующего пункта\n\n1. Ввести id, забираемой/отдаваемой книги\n2. Найти нужную книгу\n3. Выйти в меню\n";
  while(1)
    {
    cin >> i;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите одну из цифр от 1 до 3!\n";
      }
    else break;
    }
  switch(i)
    {
    case 1:
      cout << "Введите id книги: ";
      while(1)
        {
        cin >> idd;
        if(cin.fail())
          {
          cin.clear();
          getline(cin, tmp);
          cout << "\nId задается числом! Введите число!\n";
          }
        else break;
        }
      pBk=beg;
      while(pBk!=NULL)
        {
        if(pBk->poid(idd))
          {
          kont=true;		
          if(pBk->getNal()==1)
            {
            cout << endl;
            pBk->show(pol, kol);
            cout << "Это та книга которую нужно отдать?\n\n1. Да\n2. Нет\n";
            while(1)
              {
              cin >> k;
              if(cin.fail()||k>2||k<1)
                {
                cin.clear();
                getline(cin, tmp);
                cout << "\nВведите 1 или 2!\n";
                }
              else break;
              }
            if(k==1)
              {
              cout << "\nКнигу взяли\n";
              pBk->change();
              }
            else break;
            }
          else
            {
            cout << endl;
            pBk->show(pol, kol);
            cout << "Это та книга которую нужно принять?\n\n1. Да\n2. Нет\n";
            while(1)
              {
              cin >> k;
              if(cin.fail()||k>2||k<1)
                {
                cin.clear();
                getline(cin, tmp);
                cout << "\nВведите 1 или 2!\n";
                }
              else break;
              }
            if(k==1)
              {
              cout << "Книгу вернули\n";
              pBk->change();
              }
            else break;
            }
          }
        pBk=pBk->next;
        }
      if(!kont) cout << "Нет книги с таким id\n";
      return true;
    case 2: poisk(data, beg);
    return true;
    case 3: return false;
    }
  } 
