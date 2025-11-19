//media class header - 11.19.2025
#ifndef VIDEO
#define VIDEO
#include "media.h"
#include <cstring>
using namespace std;

class video : public media
{
 private:
  char* publisher;
  float rating;
 public:
  video();//hello m a k e r
  ~video();//hello destructor
  void setP(char input_p[81]);//get and set functions here
  void setR(float input_r);
  char* getP();
  float getR();
};

#endif // VIDEO
