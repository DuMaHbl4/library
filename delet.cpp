#include "main.h"
#include <iostream>
#include <fstream>
using namespace std;

book* delet(char* data, book *beg)
  {              
  bool kont=false;
  string tmp;
  book *pBk, *prBk;;
  int i, k;
  int idd;
  int pol, kol;
  ifstream f;
  f.open(data);
  f >> pol >> pol >> pol >> kol;
  f.close();
  cout << "\nВведите цифру от 1 до 3 для выбора соответствующего пункта\n\n1. Ввести id, удаляемой книги\n2. Найти книгу которую необходимо удалить\n3. Выйти в меню\n";
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
          cout << endl;
          pBk->show(pol, kol);
          cout << "Это та книга которую нужно удалить?\n\n1. Да\n2. Нет\n";
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
            if(pBk==beg)
              {
              if(pBk->next==NULL)
                {
                delete beg;
                beg=NULL;
                pBk=NULL;
                }
              else
                {
                beg=beg->next;
                delete pBk;
                pBk=beg;
                }
              }
            else
              {
              if(pBk==beg&&pBk->next==NULL)
                delete pBk;
              else
                {
                prBk=beg;
                while(prBk->next!=pBk)
                  prBk=prBk->next;
                prBk->next=pBk->next;
                delete pBk;
                pBk=prBk;
                }
              }
            cout << "\nКнига удалена";
            }
          else break;
          break;
          }
        pBk=pBk->next;
        }
      if(!kont) cout << "Нет книги с таким id\n";
      return beg;
      //break;
    case 2: poisk(data, beg);
    break;
    case 3: return beg;
    }
  } 
