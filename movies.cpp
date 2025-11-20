//11.19.2025
#include "media.h"
#include "movies.h"
#include <cstring>
using namespace std;

movies::movies()
{
  name = new char[7];//delete only works on these 'new' fellows
  strcpy(name, "movies");
  director = new char[81];
  duration = new char[5];
  rating = 0;
}
movies::~movies()//eradication
{
  delete[] director;
  delete[] duration;
}
//sets and gets over here
void movies::setDir(char in_dir[81])
{
  strcpy(director, in_dir);//then set it
}
void movies::setDur(char in_dur[5])
{
  strcpy(duration, in_dur);
}
void movies::setR(float in_r)
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

