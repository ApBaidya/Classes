//media file 11.19.2025
//https://stackoverflow.com/questions/1559487/how-to-empty-a-char-array <- clear char array
#include <cstring>
#include "media.h"
using namespace std;

media::media()//life
{
  title = new char[81];
  //strcpy(title, "none");
  year = 0;
  name = new char[7];
  strcpy(name, "media");
}
media::~media()//death.
{
  delete title;
  delete name;
}
//set. Get. 
void media::setTitle(char input_t[81])
{
  //strcpy the input to title
  strcpy(title, input_t);
}
void media::setYear(int input_yr)
{
  year = input_yr;
}

char* media::getTitle()
{
  return title; //return pointer to the char array title!
}
int media::getYear()
{
  return year;
}
char* media::getName()
{
  return name;
}
