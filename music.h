//music class header file - 11.11.2025
#include "media.h"

using namespace std;

Class music
{
 private:
  char artist[81];
  char duration[5];
  char publisher[81];
 public:
  void setArt(char in_a[81]);
  void setDur(char in_d[5]);
  void setPub(char in_p[81]);
  char getA();
  char getD();
  char getP();
}
