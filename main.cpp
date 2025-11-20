/*
https://www.youtube.com/watch?v=RU5JUHAiR18 <-- understanding header guards
This is the main code
Aparajita Baidya
11.19.2025
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
void DELETE(vector<media*>& d);
void QUIT(vector<media*>& d);



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
    //what method to use
    cout << "Your input: ";
    cin >> input;
    cout << endl;
    cin.ignore(50,'\n');
    cin.clear();
    
    //cout << input << endl;
    if (input == 'a')
    {
      //get media type to type cast them pointers
      cout << "What type of media? (movies, music, video (just type video for video game))? ";
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
      DELETE(database);
    }

    else if (input == 'q')
    {
      QUIT(database);
    }

    else
    {
      cout << "Enter a valid input." << endl;
    }
  }
  cout<<"bye"<<endl;
  return 0;
}



void ADD(vector<media*> &d, char m[7])
{
  //cout << m;
  if(strcmp(m, "music") == 0)
  {
    //set the specifics for music
    music* m = new music();//make new music object
    char t[81];//just a little temporary fellow

    cout << "title: ";
    cin >> t;
    cin.ignore(50, '\n');
    cin.clear();  
    (*m).setTitle(t);//use the set function (same pattern for everything in this function)

    int yr;
    cout << "year: ";
    cin >> yr;
    (*m).setYear(yr);

    char a[81];//each one of these sections has a year and title, and then the specific parameters the object takes
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
  
  else if(strcmp(m, "movies")==0)
  {
    movies* m = new movies();
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

    char dir[81];
    cout<<"director: ";
    cin>>dir;
    cin.ignore(50, '\n');
    cin.clear();
    (*m).setDir(dir);

    char dur[5];
    cout<<"duration: ";
    cin>>dur;
    cin.ignore(50,'\n');
    cin.clear();
    (*m).setDur(dur);

    float r;
    cout << "rating: ";
    cin>>r;
    (*m).setR(r);
    d.push_back(m);
  }
  else if(strcmp(m, "video") == 0)
  {   
    video* v = new video();
    char t[81];
    
    cout << "title: ";
    cin >> t;
    cin.ignore(50, '\n');
    cin.clear();
    (*v).setTitle(t);

    int yr;
    cout << "year: ";
    cin >> yr;
    (*v).setYear(yr);

    char pub[81];
    cout<<"publisher: ";
    cin>>pub;
    cin.ignore(50, '\n');
    cin.clear();
    (*v).setP(pub);

    float r;
    cout<<"rating: ";
    cin>>r;
    (*v).setR(r);
    d.push_back(v);
  }
}



void SEARCH(vector<media*>& d)
{
  //some temporary friends here
  char method = 'n';
  int year = 0;
  char in_ti[81];
  cout << "search by [y]year or [t]title? ";
  cin >> method;
  cout << endl;
  cin.ignore(50,'\n');
  cin.clear();
  if(method == 'y')//search by year
  {
    cout << "year: ";
    cin >> year;//get the year
    cout << endl;
    for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)//iterate
    {
      //cout << "year" << (*it)->getYear();
      if((*it)->getYear() == year)//if the object's year equals the desired one
	if(strcmp((*it)->getName(), "music") == 0)//checking the object's name
	{
	  cout << "Title: " << ((music*)(*it))->getTitle() << endl;//after finding name, cast the pointers to get the specific functions (everything in this function follows this pattern)
	  cout << "Year: " << ((music*)(*it))->getYear() << endl;
	  cout << "Artist: " << ((music*)(*it))->getA() << endl;
	  cout << "Duration: " << ((music*)(*it))->getD() << endl;
	  cout << "Publisher: " << ((music*)(*it))->getP() << endl;
	}
	else if(strcmp((*it)->getName(), "movies") == 0)
	{
	  cout << "Title: " << ((movies*)(*it))->getTitle()<<endl;
	  cout << "Year: " << ((movies*)(*it))->getYear()<<endl;
	  cout<<"Director: "<<((movies*)(*it))->getDir()<<endl;
	  cout<<"Duration: "<<((movies*)(*it))->getDur()<<endl;
	  cout<<"Rating: "<<((movies*)(*it))->getR()<<endl;
	}
	else if(strcmp((*it)->getName(), "video") == 0)
	{
	  cout << "Title: " << ((video*)(*it))->getTitle()<<endl;
	  cout << "Year: " << ((video*)(*it))->getYear()<<endl;
	  cout << "Publisher: " << ((video*)(*it))->getP()<<endl;
	  cout << "Rating: " << ((video*)(*it))->getR()<<endl;
	}
	cout<<endl;
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
      //cout << "title" << (*it)->getTitle();
      if(strcmp((*it)->getTitle(),in_ti) == 0)
      {
        if(strcmp((*it)->getName(), "music") == 0)
        {
          cout << "Title: " << ((music*)(*it))->getTitle() << endl;
          cout << "Year: " << ((music*)(*it))->getYear() << endl;
          cout << "Artist: " << ((music*)(*it))->getA() << endl;
          cout << "Duration: " << ((music*)(*it))->getD() << endl;
          cout << "Publisher: " << ((music*)(*it))->getP() << endl;
        }
	else if(strcmp((*it)->getName(), "movies") == 0)
	{
          cout << "Title: " << ((movies*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((movies*)(*it))->getYear()<<endl;
          cout<<"Director: "<<((movies*)(*it))->getDir()<<endl;
          cout<<"Duration: "<<((movies*)(*it))->getDur()<<endl;
          cout<<"Rating: "<<((movies*)(*it))->getR()<<endl;
        }
        else if(strcmp((*it)->getName(), "video") == 0)
        {
          cout << "Title: " << ((video*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((video*)(*it))->getYear()<<endl;
          cout << "Publisher: " << ((video*)(*it))->getP()<<endl;
          cout << "Rating: " << ((video*)(*it))->getR()<<endl;
        }
	cout<<endl;
      }
    }
  }
}



void DELETE(vector<media*>& d)
{
  char method;
  char del;
  int yr;
  char in_t[81];
  cout<<"search by [y]year or [t]title: ";
  cin>>method;
  cin.ignore(50, '\n');
  cin.clear();
  if(method == 'y')
  {
    cout<<"year: ";//ask for year
    cin>>yr;
    cout<<endl;
    for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)
    {
      //cout<<"aaaa";
      if((*it)->getYear() == yr)
      {
	cout << "found it!"<<endl;
        if(strcmp((*it)->getName(), "music") == 0)//cout detail according to object type
	{
          //this is pretty much what the search function does as well
          cout << "Title: " << ((music*)(*it))->getTitle() << endl;
          cout << "Year: " << ((music*)(*it))->getYear() << endl;
          cout << "Artist: " << ((music*)(*it))->getA() << endl;
          cout << "Duration: " << ((music*)(*it))->getD() << endl;
          cout << "Publisher: " << ((music*)(*it))->getP() << endl;
        }
        else if(strcmp((*it)->getName(), "movies") == 0)
        {
          cout << "Title: " << ((movies*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((movies*)(*it))->getYear()<<endl;
          cout<<"Director: "<<((movies*)(*it))->getDir()<<endl;
          cout<<"Duration: "<<((movies*)(*it))->getDur()<<endl;
          cout<<"Rating: "<<((movies*)(*it))->getR()<<endl;
        }
        else if(strcmp((*it)->getName(), "video") == 0)
        {
          cout << "Title: " << ((video*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((video*)(*it))->getYear()<<endl;
          cout << "Publisher: " << ((video*)(*it))->getP()<<endl;
          cout << "Rating: " << ((video*)(*it))->getR()<<endl;
        }
        cout<<endl;
	cout<<"do you want to delete this(y/n)? ";
	cin>>del;
	cin.ignore(50, '\n');
	cin.clear();
	//ask if they want to delete the object: if y, delete. Else if n, skip it
	if(del=='y')
	{
	  delete *it;//if they wanna delete something
	  d.erase(it);//delete the object and pointer
	  return;//then LEAVE...
	}
      }
    }
  }
  else if(method == 't')
  {
    cout<<"title: ";//ask for title
    cin>>in_t;
    cout<<endl;
    cin.ignore(50,'\n');
    cin.clear();
    for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)
    {
      //cout<<"aaaa";
      if(strcmp((*it)->getTitle(), in_t)==0)
      {
	cout << "found it!"<<endl;
	if(strcmp((*it)->getName(), "music") == 0)
        {
          //the same code as the other way to delete
          cout << "Title: " << ((music*)(*it))->getTitle() << endl;
          cout << "Year: " << ((music*)(*it))->getYear() << endl;
          cout << "Artist: " << ((music*)(*it))->getA() << endl;
          cout << "Duration: " << ((music*)(*it))->getD() << endl;
          cout << "Publisher: " << ((music*)(*it))->getP() << endl;
        }
        else if(strcmp((*it)->getName(), "movies") == 0)
        {
          cout << "Title: " << ((movies*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((movies*)(*it))->getYear()<<endl;
          cout<<"Director: "<<((movies*)(*it))->getDir()<<endl;
          cout<<"Duration: "<<((movies*)(*it))->getDur()<<endl;
          cout<<"Rating: "<<((movies*)(*it))->getR()<<endl;
        }
        else if(strcmp((*it)->getName(), "video") == 0)
        {
          cout << "Title: " << ((video*)(*it))->getTitle()<<endl;
          cout << "Year: " << ((video*)(*it))->getYear()<<endl;
          cout << "Publisher: " << ((video*)(*it))->getP()<<endl;
          cout << "Rating: " << ((video*)(*it))->getR()<<endl;
        }
	cout<<endl;
        cout<<"do you want to delete this(y/n)? ";
        cin>>del;
        cin.ignore(50, '\n');
        cin.clear();
        //ask if they want to delete the object: if y, delete. Else if n, skip it
        if(del=='y')
        {
          delete *it;//if they wanna delete something
          d.erase(it);//delete the object and pointer
          return;//then LEAVE...
        }
      }
    }
  }
}

void QUIT(vector<media*>& d)
{
  for(vector<media*>::iterator it = d.begin(); it != d.end(); ++it)
  {
    delete *it;//DELETE EVERY OBJECT (their pointers still remain...)
  }
  d.clear();//the end.
}
