#include "main.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
  {
  if(argc!=2)
    {
    cout << "Введите имя файла в командной строке\nВот так: ./bib 1.txt\n";
    return 0;
    }
  menu(argv[1]);
  }
