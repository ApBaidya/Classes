//Movies class header file - 11.19.2025
#ifndef MOVIES
#define MOVIES
#include "media.h"
#include <cstring>
using namespace std;

class movies : public media
{
 private:
  char* director;
  char* duration;
  float rating;
 public:
  movies();
  ~movies();//the murderer
  void setDir(char in_dir[81]);
  void setDur(char in_dur[5]);
  void setR(float in_r);
  char* getDir();
  char* getDur();
  float getR();
};

#endif // MOVIES
