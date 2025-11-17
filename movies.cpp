//11.13.2025
#include "media.h"
#include <cstring>
using namespace std;

movies::movies()
{
  director[81] = "none";
  duration[5] = "none";
  rating = 0;
  title = "movies"; 
}

movies::setDir(char in_dir[81])
{
  title[0] = '\0';
  strcpy(director, in_dir);
}
movies::setDur(char in_dur[5])
{
  title[0] = '\0';
  strcpy(duration, in_dur);
}
movies::setR(float in_r)
{
  rating = in_r;
}

char* movies::getDir()
{
  return director;
}
char* movies::getDur()
{
  return duration;
}
float movies::getR()
{
  return rating;
}
char* movies::getName()
{
  return title;
}
