/* ****************************************************************
 * @author: JEPHTHAH M. OROBIA
 * @app name: Right-Aligned Right Triangle Generator
 * @app desc: This console app draws a right triangle alinged to the
 *            right of the window using asterisk based on user's input.
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
  int h, maxW = getMaxCharPerLine() / 2;

  cout << "Let's make a right triangle!" << endl;
  cout << "How many asterisk tall do you want it? [2-"<< maxW <<" integers only]: ";

  while (true)
  {
    cin >> h;
    if (!cin.fail() && h > 1 && h <= maxW)
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid height. Try again [2-"<< maxW <<" integers only]: ";
    }
  }

  system("cls"); //clear the screen

  // the variable names is for for easier visualization, think of grid
  for(int row=1; row <= h; row++){
    for(int col=0; col < 2*maxW; col++){
      if(col == 2*maxW - 1 // the vertical leg of the right triangle
        || col == 2*maxW - 2*row + 1 // the hypotenuse of the right triangle
        || ( row == h // the base or the horizontal leg of the right triangle
              && col > 2*maxW - 2*row + 1
              && (col - (2*maxW - 2*row + 1)) % 2 == 0))
        {
        cout << "*";
      } else {
        cout << " ";
      }
    };
    cout << endl;
  }
  
  cout << endl << "Above (to the right) is a " << h << " tall right triangle." << endl;

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
