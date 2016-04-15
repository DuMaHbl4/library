#include "main.h"
#include <iostream>
using namespace std;

int menu(char* data)
  {
  string tmp;
  book *beg;
  int i;
  if(prov(data)==1)
    return 0;
  beg=load(data);
  while(1)
    {
    cout << "\nВведите цифру от 1 до 6 для выбора соответствующего пункта меню\n\n1. Добавить книгу\n2. Поиск книги\n3. Вывести весь список книг на экран\n4. Отдать/принять книгу\n5. Удалить книгу\n6. Закрыть программу\n";
    cin >> i;
    if(cin.fail())
      {
      cin.clear();
      getline(cin, tmp);
      //cout << "Введите одну из цифр от 1 до 8!" << endl;
      }
    switch(i)
      {
      case 1: 
	beg=add(data, beg);
	break;
      case 2:
        while(1)
          { 
          if(!poisk(data, beg)) break;
          }
          break;
      case 5:
        if(beg==NULL)
          {
          cout << "Библиотека пуста\n";
          break;
          }
        else
          {
          beg=delet(data, beg);
          save(data, beg);
          break;
          }
      case 4:
        while(1)
          {
          if(!change(data, beg)) break;
          }
        if(beg!=NULL) save(data, beg);
	break;
      case 3:
        beg=show(data, beg);
        break; 
      case 6: return 0;
      default: cout << endl << endl << "Введите одну из цифр от 1 до 6!" << endl; 
      }
    }
  }
