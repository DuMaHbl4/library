#include "main.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string book::getTtl()
  {
  string str=string(ttl);
  return str;
  }

string book::getAvtf()
  {
  string str=string(avtf);
  return str;
  }

void book::show(const int &pol, const int &kol)
  {
  int i;
  cout.width(5);
    cout << "В " << (id-1)/pol/kol+1 << " шкафу, " << "на " << (id-1)%(kol*pol)/kol+1 << " полке. ";
    cout.width(24);
    if(nal==1) cout << " В наличии  ";
    else cout << " Нет в наличии  ";
    cout << "  id: " << id << "  ";
    if (id<10) cout << ' ';
    switch (jnr)
    {
    case 1: cout << "Детектив    "; break;
    case 2: cout << "Классика    "; break;
    case 3: cout << "Лбвный роман"; break;
    case 4: cout << "Повесть     "; break;
    case 5: cout << "Приключения "; break;
    case 6: cout << "Роман       "; break;
    case 7: cout << "Справочник  "; break;
    case 8: cout << "Фантастика  "; break;
    case 9: cout << "Неизвестный "; break;
    default: cout << "Неправильный тип жанра"; break;
    }
    cout<<"\t"; 
    cout << ttl <<' ';
    cout << "\t";
    if(strlen(ttl)<=28)
    cout << "\t";
    if(strlen(ttl)<=14)
    cout << "\t";
    cout << avtf << " " << avti << " " << avto  << endl;
  }
  
book* show(char* data, book *beg)
  {
  if (beg==NULL)
    {
    cout << "Библиотека пуста\n";
    return beg;
    }              
  char ttls1[150], ttls2[150];
  book *prBk, *ppBk, *pBk;
  int kont=0;
  string tmp;
  int i;
  int pol, kol;
  ifstream f;
  f.open(data);
  f >> pol >> pol >> pol >> kol;
  cout << "\nВведите цифру от 1 до 4 для выбора соответствующего пункта меню\n1. Вывести весь список книг, отсортированый по полкам\n2. Вывести весь список книг, отсортированый по алфату(по названию)\n3. Выйти в меню\n";
  while(1)
    {
    cin >> i;
    if(cin.fail()||i<1||i>4)
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите одну из цифр от 1 до 4!\n";
      }
    else break;
    }
  cout << "  Расположение                Наличие      Id      Жанр         Название                ФИО автора\n\n";   
  if(beg->next==NULL) beg->show(pol, kol);
  else
    {
    switch(i)
      {
      case 1:
        while(kont!=1)
          {
          kont=1;
          if(beg->getId()>beg->next->getId())
            {
            ppBk=beg;
            prBk=beg->next->next;;
            beg=beg->next;
            beg->next=ppBk;
            beg->next->next=prBk;
            }
          pBk=beg;
          while(pBk->next->next!=NULL)
            {
            if(pBk->next->getId()>pBk->next->next->getId())
              {
              prBk=pBk->next->next->next;
              ppBk=pBk->next;
              pBk->next=pBk->next->next;
              pBk->next->next=ppBk;
              pBk->next->next->next=prBk;
              kont=0;
              }  
            pBk=pBk->next;
            }
          }
        kont=0;
        break;
      case 2:
        while(kont!=1)
          {
          kont=1;
          if(beg->getTtl()>beg->next->getTtl())
            {
            ppBk=beg;
            prBk=beg->next->next;;
            beg=beg->next;
            beg->next=ppBk;
            beg->next->next=prBk;
            }
          pBk=beg;
          while(pBk->next->next!=NULL)
            {
            if(pBk->next->getTtl()>pBk->next->next->getTtl())
              {
              prBk=pBk->next->next->next;
              ppBk=pBk->next;
              pBk->next=pBk->next->next;
              pBk->next->next=ppBk;
              pBk->next->next->next=prBk;
              kont=0;
              }  
            pBk=pBk->next;
            }
          }
          kont=0;
          break;
      case 3:
        return beg;    
      }
  pBk=beg;
  while(pBk!=NULL)
    {
    pBk->show(pol, kol);
    pBk=pBk->next;
    }
    }
  return beg;
  }
