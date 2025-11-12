///media class header file - 11.11.2025

#include <cstring>

using namespace std;

class media
{
  media();
 private:
  char title[81];
  int year;
  char name[7];
 public:
  void setTitle(char input_t[81]);
  void setYear(int input_yr);
  char getTitle();
  int getYear();
  virtual char* getName();
}
