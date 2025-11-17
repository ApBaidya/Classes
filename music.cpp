//11.13.2025
#include "media.h"
#include <cstring>
#include "music.h"

music::music()
{
  strcpy(name, "music");
  strcpy(artist, "none");
  strcpy(duration, "none");
  strcpy(publisher, "none");
}

void music::setArt(char in_a[81])
{
  //reset title
  artist[0] = '\0';
  //strcpy the input to title
  strcpy(artist, in_a);
}
void music::setDur(char in_d[5])
{
  //reset title
  duration[0] = '\0';
  //strcpy the input to title
  strcpy(duration, in_d);
}
void music::setPub(char in_p[81])
{
  //reset title
  publisher[0] = '\0';
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

