//music class header file - 11.11.2025
#ifndef MUSIC
#define MUSIC
#include "media.h"
#include <cstring>

using namespace std;

class music : public media
{
 private:
  char artist[81];
  char duration[5];
  char publisher[81];
 public:
  music();
  void setArt(char in_a[81]);
  void setDur(char in_d[5]);
  void setPub(char in_p[81]);
  char* getA();
  char* getD();
  char* getP();
};

#endif // MUSIC
