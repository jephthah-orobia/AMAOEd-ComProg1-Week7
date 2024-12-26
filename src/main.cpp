/* ****************************************************************
 * @author: JEPHTHAH M. OROBIA
 * @app name: AMAOEd-Cpp-MyTemplate
 * @app desc: This is my personalized boilerplate for C++ console app
 * ****************************************************************/


#include <iostream>
#include <limits>
#include <tuple>
#include <functional>

#include "whatsNext.h"
#include "getMaxCharPerLine.h"

using namespace std;

int main()
{
  int h, i=1, maxCharPerLine = getMaxCharPerLine();

  cout << "Let's make a right triangle!" << endl;
  cout << "How many asterisk tall do you want it?\nFor best result, pick an odd number [2-"<< maxCharPerLine <<" integers only]: ";

  while (true)
  {
    cin >> noskipws >> h;
    if (!cin.fail() && h > 1 && h <= maxCharPerLine)
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl << "Invalid height. Try again [3-"<< maxCharPerLine <<" integers only]: ";
    }
  }

  system("cls"); //clear the screen

  while(i <= h){
    int r = 1;
    while(r <= i){
      if(r == 1
          || r == i
          || (i == h
              && ((h % 2 == 0 && r > h/2 + 1 && r % 2 == 0)
              || (r < h/2 + 1 && r%2 == 1)
              || (h % 2 == 1 && r%2 == 1))))
        cout << "*";
      else
        cout << " ";
      r++;
    };
    cout << endl;
    i++;
  }

  cout << endl << "Above is a " << h << " tall right triangle." << endl;

  map<char, tuple<string, function<int()>>> actions = {
      {'r', make_tuple("Re-Run App",
                       []()
                       {
                         system("cls");
                         return main();
                       })},
      };

  return whatsNext(actions);
}
