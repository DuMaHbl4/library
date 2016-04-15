#include "main.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void book::load(char* ctr)
  {
  int g=0 , i=0, n=0;
  g=atoi(&ctr[0]);		//считывание из строки айди, жанра и наличия
  id=g;
  do{ n++;} while(g/=10);
  jnr=atoi(&ctr[n+1]);
  nal=atoi(&ctr[n+3]);
  while(ctr[n+5+i]!=' ')	//считывается ФИО автора
    {
    i++;
    avtf[g]=ctr[n+4+i];
    g++;
    }
  g=0;
  while(ctr[n+6+i]!=' ')
    {
    i++;
    avti[g]=ctr[n+5+i];
    g++;
    }
  g=0;
  while(ctr[n+7+i]!=' ')
    {
    i++;
    avto[g]=ctr[n+6+i];
    g++;
    }
  g=0;
  while((n+8+i)!=strlen(ctr))	//считывается название книги
    {
    i++;
    ttl[g]=ctr[n+7+i];
    g++;
    }
  }

book* load(char* data)		//функция загрузки списка из файла
  {  
  string str;
  book *beg=NULL, *pBk, *end=NULL;
  ifstream f;
  f.open(data);
  getline(f, str);	
  while(!f.eof())
    {
    getline(f, str);
    if(str.length()<1)
    break;
    char *ctr=new char[str.length()+1];
    strcpy(ctr, str.c_str());
    pBk=new book;
    pBk->load(ctr);
    if(beg==NULL) beg=pBk;
    else end->next=pBk;
    end=pBk;
    end->next=NULL;
    }
  return beg;
  }
