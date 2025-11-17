
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
  finish classes
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
void ADD(vector<media*>& d, char m[7]);
void SEARCH(vector<media*>& d);
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
      ADD(database, media_type);
    }

    else if (input == 's')
    {
      SEARCH(database);
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



void ADD(vector<media*> &d, char m[7])
{
  cout << m;
  if(strcmp(m, "music") == 0)
  {
    cout << "a";
    music* m = new music();
    char t[81];
    cout << "title: ";
    cin >> t;
    cin.ignore(50, '\n');
    cin.clear();  
    (*m).setTitle(t);

    int yr;
    cout << "year: ";
    cin >> yr;
    (*m).setYear(yr);

    char a[81];
    cout << "artist: ";
    cin >> a;
    cin.ignore(50, '\n');
    cin.clear();
    (*m).setArt(a);

    char dur[5];
    cout << "duration: ";
    cin >> dur;
    cin.ignore(50, '\n');
    cin.clear();
    (*m).setDur(dur);
    
    char pub[81];
    cout << "publisher: ";
    cin >> pub;
    cin.ignore(50, '\n');
    cin.clear();
    (*m).setPub(pub);
    d.push_back(m);
  }
  /*
  else if(strcmp(m, "movies"))
  {
  }
  else if(strcp(m, "video"))
  {
  }*/
}



void SEARCH(vector<media*>& d)
{
  char method = 'n';
  int year = 0;
  char in_ti[81];
  cout << "search by [y]year or [t]title? ";
  cin >> method;
  cout << endl;
  cin.ignore(50,'\n');
  cin.clear();
  if(method == 'y')
  {
    cout << "year: ";
    cin >> year;
    cout << endl;
    for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)
    {
      //cout << "year" << (*it)->getYear();
      if((*it)->getYear() == year)
      {
	cout << 'a';
	if(strcmp((*it)->getName(), "music") == 0)
	{
	  cout << 'b';
	  cout << "Title: " << ((music*)(*it))->getTitle() << endl;
	  cout << "Year: " << ((music*)(*it))->getYear() << endl;
	  cout << "Artist: " << ((music*)(*it))->getA() << endl;
	  cout << "Duration: " << ((music*)(*it))->getD() << endl;
	  cout << "Publisher: " << ((music*)(*it))->getP() << endl;
	}
      }
    }
  }
  else if(method == 't')
  {
    cout << "title: ";
    cin >> in_ti;
    cout << endl;
    cin.ignore(50, '\n');
    cin.clear();
    for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)
    {
      cout << "title" << (*it)->getTitle();
      if(strcmp((*it)->getTitle(),in_ti) == 0)
      {
        //cout << 'a';
        if(strcmp((*it)->getName(), "music") == 0)
        {
          //cout << 'b';
          cout << "Title: " << ((music*)(*it))->getTitle() << endl;
          cout << "Year: " << ((music*)(*it))->getYear() << endl;
          cout << "Artist: " << ((music*)(*it))->getA() << endl;
          cout << "Duration: " << ((music*)(*it))->getD() << endl;
          cout << "Publisher: " << ((music*)(*it))->getP() << endl;
        }
      }
    }

  }
}



void DELETE()
{

}



void QUIT()
{

}
