//media class header - 11.11.2025
#include "media.h"

using namespace std;

class video
{
  video();
 private:
  char publisher[81];
  float rating;
 public:
  void setP(char input_p[81]);
  void setR(float input_r);
  char getP();
  float getR();
  virtual char* getName();
}
