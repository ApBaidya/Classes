
/*
https://www.youtube.com/watch?v=RU5JUHAiR18 <-- understanding header guards
This is the main code
Aparajita Baidya
11.16.2025
1) vector contaning parent class
2) ADD (any of the child classes-> video games, music, movies)
3) SEARCH (search by title or year --> list all objects that match)
4) DELETE *use a destructor (delete based on title or year --> ask if user is sure)
5) QUIT (get rid of any left over data and end program)
*/

/*
to do
  make a virtual fuction in media class for the object name and use that to figure out what to typecast the pointer to be
  ADD
  DELETE
  SEARCH
  QUIT
  virtual destructor?
*/

#include <iostream>
#include <cstring>
#include <vector>
//remember to include the children
#include "movies.h"
#include "music.h"
#include "video.h"

using namespace std;



//declare functions
void ADD(char m[7]);
void SEARCH();
void DELETE();
void QUIT();



int main()
{
  //let them know t h e r u l e s
  cout << "Welcome! Here are the commands you can make: \n" << "[q] for QUIT \n" << "[a] for ADD \n" << "[s] for SEARCH \n" << "[d] for DELETE" << endl;

  //note any variables needed
  char input;
  char media_type[7];
  //create vector
  vector<media*> database;
  
  //main loop
  while (input != 'q')
  {
    music* m = new music();
    database.push_back(m);
    for(vector<media*>::iterator it = database.begin(); it != database.end(); ++it)
      {
        cout << (*it) -> getName();
      }
    
    cout << "Your input: ";
    cin >> input;
    cout << endl;
    cin.ignore(50,'\n');
    cin.clear();

    //cout << input << endl;
    if (input == 'a')
    {
      cout << "What type of media? (movie, music, video)? ";
      cin >> media_type;
      cout << endl;
      cin.ignore(50, '\n');
      cin.clear();
      //ADD(media_type);
    }

    else if (input == 's')
    {
      //SEARCH();
    }

    else if (input == 'd')
    {
      DELETE();
    }

    else if (input == 'q')
    {
      QUIT();
    }

    else
    {
      cout << "Enter a valid input." << endl;
    }
  }
  return 0;
}



void ADD(char m[7])
{

}



void SEARCH()
{
 
}



void DELETE()
{

}



void QUIT()
{

}
