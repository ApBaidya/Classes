//media file 11.16.2025
//https://stackoverflow.com/questions/1559487/how-to-empty-a-char-array <- clear char array
#include <cstring>
#include "media.h"
using namespace std;

media::media()
{
  strcpy(title, "none");
  year = 0;
  strcpy(name, "media");
}

void media::setTitle(char input_t[81])
{
  //reset title
  title[0] = '\0';
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
