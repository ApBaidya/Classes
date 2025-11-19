//11.19.2025
#include "media.h"
#include <cstring>
#include "video.h"

using namespace std;

video::video()
{
  name = new char[7];
  strcpy(name, "video");//I wanted to change name in each class
  publisher=new char[81];
  rating = 0;
}
video::~video()//hello again, destructor
{
  delete publisher;
}

void video::setP(char input_p[81])
{
  strcpy(publisher, input_p);
}
void video::setR(float input_r)
{
  rating = input_r;
}

char* video::getP()
{
  return publisher;
}
float video::getR()
{
  return rating;
}
