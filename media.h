///media class header file - 11.13.2025
#ifndef MEDIA
#define MEDIA

#include <cstring>

using namespace std;

class media
{
 protected:
  char name[7];
 private:
  char title[81];
  int year;
 public:
  media();
  void setTitle(char input_t[81]);
  void setYear(int input_yr);
  char* getTitle();
  int getYear();
  virtual char* getName();
};

#endif // MEDIA
