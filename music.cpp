//11.19.2025
#include "media.h"
#include <cstring>
#include "music.h"

music::music()
{
  name = new char[7];
  strcpy(name, "music");
  artist = new char[81];
  duration = new char[5];
  publisher=new char[81];
}
music::~music()
{
  delete artist;
  delete duration;
  delete publisher;
}

void music::setArt(char in_a[81])
{
  //strcpy the input to title
  strcpy(artist, in_a);
}
void music::setDur(char in_d[5])
{
  //strcpy the input to title
  strcpy(duration, in_d);
}
void music::setPub(char in_p[81])
{
  //strcpy the input to title
  strcpy(publisher, in_p);
}

char* music::getA()
{
  return artist;
}
char* music::getD()
{
  return duration;
}
char* music::getP()
{
  return publisher;
}

