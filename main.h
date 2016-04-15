#include <fstream>
#include <iostream>
using namespace std;
class book
  {
  int id;
  int jnr;
  bool nal;
  char ttl[150];
  char avtf[100];
  char avti[100];
  char avto[100];
public:
  book *next;			//указатель на следующий эемент
  void add(int id);		//функция добавления
  void show(const int& pol, const int& kol);		//функция показа книги
  void load(char* str);		//добавление книги(для загрузки из файла)
  bool poid(const int& idd);	//поиск по айди
  bool pottl(string ttll);	      //по названию
  bool poavtf(string ttll);	      //по фамилии автора
  bool pojnr(int jnrr);		      //по жанру
  int getNal();			//возврат информации о наличии
  void change();		//изменение информации о наличии
  string getTtl();		//возврат названия
  string getAvtf();		//возврат фамилии автора
  void save(int& ids, int& jnrs, int& nals, char* avtfs, char* avtis, char* avtos, char* ttls); //возврат всей информации о книге(через ссылки)
  int getId();			//возврат айди
  };

int menu(char* data);			//меню
book* add(char* data, book *beg);	//добавление
book* load(char* data);			//загрузка из файла
int save(char* data, book *beg);	//сохранение в файл
int prov(char* data);  			//проверка на наличие файла
book* show(char* data, book *pBk);	//вывод списка на экран
bool poisk(char* data, book *beg);	//поиск
bool change(char* data, book *beg);	//изменение информации о наличии
book* delet(char* data, book *beg);	//удаление
