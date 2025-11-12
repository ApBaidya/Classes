//Movies class header file - 11.11.2025
#include "media.h"
using namespace std;

Class movies
{
 private:
  char director[81];
  char duration[5];
  float rating;
 public:
  void setDir(char in_dir[81]);
  void setDur(char in_dur[5]);
  void setR(float in_r);
}

