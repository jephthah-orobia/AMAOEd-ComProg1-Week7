/* ****************************************************************
 * @author: JEPHTHAH M. OROBIA
 * @app name: Inverted Equilateral Triangle Generator
 * @app desc: This console app draws an inverted equilataeral triangle
 *            on the screen based the user's prefered height.
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
  int h, row=1, maxCharPerLine = getMaxCharPerLine();

  cout << "Let's make an inverse equilateral triangle!" << endl;
  cout << "How many asterisk tall do you want it? [2-"<< maxCharPerLine / 2 <<" integers only]: ";

  while (true)
  {
    cin >> noskipws >> h;
    if (!cin.fail() && h > 1 && h <= maxCharPerLine/2)
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl << "Invalid height. Try again [3-"<< maxCharPerLine / 2 <<" integers only]: ";
    }
  }

  system("cls"); //clear the screen

  do {
    int col = 1;
    do {
      if(col == row || col == 2*h - row || (row == 1 && col % 2 == 1)){
        cout << "*";
      } else {
        cout << " ";
      }
      col++;
    } while (col < 2*h);
    cout << endl;
    row++;
  } while (row <= h);

  cout << endl << "Above is a " << h << " tall equilateral triangle." << endl;

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
