#include "main.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
    
void book::add (int d)
  {
  string tmp, str;
  id=d;
  nal=1;
  cout << "\nВведите тип жанра книги:\n1. Детектив\n2. Классика\n3. Любовный роман\n4. Повесть\n5. Приключения\n6. Роман\n7. Справочник\n8. Фантакстика\n9. Неизвестный жанр\n  ";
  while(1)
    {
    cin >> jnr;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      cout << "Введите одну из цифр от 1 до 9!" << endl;
      }
    else break;
    }
  if(jnr<1 && jnr>9) cout << "Введите одну из цифр от 1 до 9!";
  cout << "Введите фамилию автора книги: ";
  cin >> avtf;
  cout << "Введите имя автора книги: ";
  cin >> avti;
  cout << "Введите отчество автора книги: ";
  cin >> avto;
  cout << "Введите название книги: ";
  getline(cin, str);
  getline(cin, str);
  strcpy(ttl, str.c_str());
  }
  
book* add(char* data, book *beg)
  {
  string tmp;
  int kont;
  book *pBk, *end;
  int it=1;
  int i;
  int shc, polc, kolc;
  int sh, pol, kol;
  int idd;		//айди, который считывается с клавиатуры 
  int x=0;		//число книг в списке
  int idm=0;		//максимальный айди
  int j;
  int d;		//айди который считывается из файла
  ifstream f;
  f.open(data);
  f >> d >> sh >> pol  >> kol;
  f.close();
  pBk=beg;
  end=beg;
  if(end!=NULL)
    {
    while(end->next!=NULL)		
      {
      end=end->next;
      }
    }
  d++;    
  while(1)
    {
    x=0;
    idm=0;
    pBk=beg;
    while(pBk!=NULL)	//подсчет числа книг в списке
      {
      x++;
      pBk=pBk->next;
      }
    pBk=beg;
    while(pBk!=NULL)	//поиск максимального айди в списке
      {
      if(pBk->getId()>idm) idm=pBk->getId();
      pBk=pBk->next;
      }
    cout << "\nВведите цифру от 1 до 3 для выбора соответствующего пункта меню\n\n1. Добавить книгу (по порядку)\n2. Добавить книгу на место, оставшееся после удаления\n3. Выйти в меню\n";
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
      case 1:		//добавление в конец списка
        if(idm==sh*kol*pol)
          {
          if(idm>x)
            {
            cout << "В библиотеке нет мест по порядку, но есть места оставшиеся после удаления книг\nЧтобы добавить книгу на это место выберете второй пункт в меню добавления\n";
            break;
            }
          else
            {
            cout << "В библиотеке нет места\n";
            break;
            }
          }              
        pBk = new book;
        pBk->add(d);
        if (beg==NULL)
          { 
          beg=pBk;
          }
        else
          { 
          end->next=pBk;			
          }
        end=pBk;
        end->next=NULL;   
        d++;
        break;
      case 2:		//добавление на место, оставшееся после удаления
        if(idm==sh*kol*pol)
          {
          if(idm==x)
            {
            cout <<  "В библиотеке нет места\n";
            break;
            }
          }      
        for(j=1; j<=idm; j++)
          {
          pBk=beg;
          kont=0;
          while(pBk!=NULL)
            {
            if (j==(pBk->getId()))
              {
              kont =1;
              break;
              }
            pBk=pBk->next;
            }
          it=it*kont;
        if(it==1||beg==NULL)
            {
            cout << "Еще не появилось свободное место после удаления!\n";
            break;
            }
          }
        cout << "\nВведите шкаф, полку и счет от начала полки со свободным местом\n";
        cin >> shc >> polc >> kolc;
        idd=pol*kol*(shc-1)+kol*(polc-1)+kolc;
        pBk=beg;
        kont=1;
        while(pBk!=NULL)
          {
          if(pBk->poid(idd))
            {
            cout << "\nМесто занято!\n";
            kont=0;
            break;
            }
          pBk=pBk->next;
          }
        if(kont==0) break;
        pBk = new book;
        pBk->add(idd);
        if (beg==NULL)
          { 
          cout << "указатель на начало изменен " << endl;
          beg=pBk;
          }
        else
          {
          cout << "указательн а начало не изменен " << endl; 
          end->next=pBk;			
          }
        end=pBk;
        end->next=NULL;
        break;
      case 3:
        if(beg!=NULL) save(data, beg);
        return(beg);
      }
    } 
  }

