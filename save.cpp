#include "main.h"
#include <fstream>
#include <iostream>
using namespace std;

int book::getId()
  {
  return(id);
  }

void book::save(int& ids, int& jnrs, int& nals, char* avtfs, char* avtis, char* avtos, char* ttls)
  {
  int i;
  ids=id;
  jnrs=jnr;
  nals=nal;
  for(i=0; i<100; i++)
    {
    avtfs[i]=avtf[i];
    avtis[i]=avti[i];
    avtos[i]=avto[i];
    }
  for(i=0; i<150; i++)
    ttls[i]=ttl[i];
  }

int save(char* data, book *beg)
  {
  int ids;
  int jnrs;
  int nals; 
  char avtfs[100]; 
  char avtis[100]; 
  char avtos[100]; 
  char ttls[150];
  int id, sh, pol, kol;
  ifstream f;
  f.open(data);
  f >> id >> sh >> pol >> kol;
  f.close();
  book *pBk;
  id=0;
  pBk=beg;
  if(pBk!=NULL)
    {
    while(pBk!=NULL)
      {
      if(pBk->getId()>id) id=pBk->getId();
      pBk=pBk->next;
      cout << id << ' ';
      }
    }
  ofstream fi;          //запись в файл
  fi.open(data);
  fi << id << ' ' << sh << ' ' << pol << ' ' << kol ;
  pBk=beg;
  while(pBk!=NULL)
    {
    pBk->save(ids, jnrs, nals, avtfs, avtis, avtos, ttls);
    fi << endl << ids << ' '  <<  jnrs << ' ' << nals << ' ' << avtfs << ' ' << avtis << ' ' << avtos << ' ' << ttls;
    pBk=pBk->next;
    }
  fi.close();
  }                         
