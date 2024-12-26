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
  int h, //height
    row = 1, //current line counter, imagine a grid, the line is the row
    maxC = getMaxCharPerLine() / 2; // half the max so that width can be twice the height.

  cout << "Let's make a right triangle!" << endl;
  cout << "How many asterisk tall do you want it? [2-" << maxC << " integers only]: ";

  while (true)
  {
    cin >> noskipws >> h;
    if (!cin.fail() && h > 1 && h <= maxC)
    {
      break;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << endl
           << "Invalid height. Try again [3-" << maxC << " integers only]: ";
    }
  }

  system("cls"); // clear the screen

  while (row <= h)
  {
    int col = 1;
    while (col <= 2 * row)
    {
      if (col == 1            // vertical leg of the triangle
          || col == 2 * row - 1 // the hypotenuse
          || (row == h        // horizontal leg or the base of the triangle
              && col % 2 == 1))
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
      col++;
    };
    cout << endl;
    row++;
  }

  cout << endl
       << "Above is a " << h << " tall right triangle." << endl;

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
