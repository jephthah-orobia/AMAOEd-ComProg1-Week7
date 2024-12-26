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
  int h, maxCharPerLine = getMaxCharPerLine();

  cout << "Let's make a right triangle!" << endl;
  cout << "How many asterisk tall do you want it?\nFor best result, pick an odd number [2-"<< maxCharPerLine <<" integers only]: ";

  while (true)
  {
    cin >> h;
    if (!cin.fail() && h > 1 && h <= maxCharPerLine)
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid height. Try again [3-"<< maxCharPerLine <<" integers only]: ";
    }
  }

  system("cls"); //clear the screen

  for(int i=1; i <= h; i++){
    for(int r=0; r < maxCharPerLine; r++){
      if(r == maxCharPerLine - 1 || r == maxCharPerLine - i || ( i == h && r > maxCharPerLine - i && (r - maxCharPerLine + i) % 2 == 0)){
        cout << "*";
      } else {
        cout << " ";
      }
    };
    cout << endl;
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
