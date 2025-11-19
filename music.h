//music class header file - 11.19.2025
#ifndef MUSIC
#define MUSIC
#include "media.h"
#include <cstring>

using namespace std;

class music : public media
{
 private:
  char* artist;
  char* duration;
  char* publisher;
 public:
  music();
  ~music();
  void setArt(char in_a[81]);
  void setDur(char in_d[5]);
  void setPub(char in_p[81]);
  char* getA();
  char* getD();
  char* getP();
};

#endif // MUSIC
