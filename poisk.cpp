#include "main.h"
#include <iostream>
#include <fstream>
using namespace std;

bool book::poid(const int& idd)
  {
  if(idd==id) return true;
  else return false;
  }

bool book::pottl(string ttll)
  {
  if(ttl==ttll) return true;
  else return false;
  }
  
bool book::poavtf(string ttll)
  {
  if(ttll==avtf) return true;
  else return false;
  }

bool book::pojnr(int jnrr)
  {
  if(jnr==jnrr) return true;
  else return false;
  }

bool poisk(char* data, book *beg)
  {
  if (beg==NULL)
    {
    cout << "Библиотека пуста\n";
    return false;
    }
  bool kont;
  string ttll;
  string tmp;
  int i;
  int idd;
  int pol, kol;
  book *pBk;
  ifstream f;
  f.open(data);
  f >> pol >> pol >> pol >> kol;
  cout << "\nВведите цифру от 1 до 5 для выбора соответствующего пункта меню\n\n1. Поиск по id\n2. Поиск по названию\n3. Поиск по фамилии автора\n4. Поиск по жанру\n5. Выйти в меню\n";
  while(1)
    {  
    cin >> i;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "\nВведите одну из цифр от 1 до 5!\n";
      }
    else break;
    }
  switch(i)
      {
      case 1:
        cout << "Введите id книги\n";
        while(1)
          {
          cin >> idd;
          if(cin.fail())
            {
            cin.clear();
            getline(cin, tmp);
            cout << "\n\nId задается числом!\nВведите число!\n\n";
            }
          else break;
          }
        pBk=beg;
        while(pBk!=NULL)
          {
          if(pBk->poid(idd))
            {
            pBk->show(pol, kol);
            kont=true;
            }
          pBk=pBk->next;
          }
        if(!kont) cout << "\nКнига не найдена\n";
      kont=false;
      return true;
      case 2:
        cout << "Введите название книги\n";
        getline(cin, ttll);
        getline(cin, ttll);
        pBk=beg;
        cout << ttll;
        while(pBk!=NULL)
          {
          if(pBk->pottl(ttll)) 
            {
            pBk->show(pol, kol);
            kont=true;
            }
          pBk=pBk->next;
          }
        if(!kont)  cout << "\nКниг не найдено\n";
        kont=false;
        return true;
      case 3:
        cout << "Введите фамилию автора\n";
        getline(cin, ttll);
        getline(cin, ttll);
        pBk=beg;
        cout << ttll;
        while(pBk!=NULL)
          {
          if(pBk->poavtf(ttll))
            {
            pBk->show(pol, kol);
            kont=true;
            }
          pBk=pBk->next;
          }
        if(!kont)  cout << "\nКниг не найдено\n";
        kont=false;
        return true;
      case 4:
        cout << "\nВведите тип жанра книги:\n1. Детектив\n2. Классика\n3. Любовный роман\n4. Повесть\n5. Приключения\n6. Роман\n7. Справочник\n8. Фантакстика\n9. Неизвестный жанр\n  ";
        while(1)
          {
          cin >> idd;
          if(cin.fail())
            {
            cin.clear();
            getline(cin, ttll);
            cout << "Введите одну из цифр от 1 до 9!" << endl;
            }
          else break;
          }
          pBk=beg;
          while(pBk!=NULL)
            {
            if(pBk->pojnr(idd))
              {
              pBk->show(pol, kol);
              kont=true;
              }
            pBk=pBk->next;
            }
          if(!kont) cout << "\nКниг не найдено\n";
          kont=false;
          return true;
      case 5: return false; 
      }
    
  }