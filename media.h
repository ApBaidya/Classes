///media class header file - 11.19.2025
#ifndef MEDIA
#define MEDIA

#include <cstring>

using namespace std;

class media
{
 protected:
  char* name;//want to give the child classes access
 private:
  char* title;
  //char title[81];
  int year;
 public:
  media();
  virtual ~media();//virtual destructor over here
  void setTitle(char input_t[81]);
  void setYear(int input_yr);
  char* getTitle();
  int getYear();
  virtual char* getName();//made this virtual as name is different for each class
};

#endif // MEDIA
