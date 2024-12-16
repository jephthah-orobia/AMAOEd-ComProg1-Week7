/* ****************************************************************
 * @author: JEPHTHAH M. OROBIA
 * @app name: AMAOEd-Cpp-MyTemplate
 * @app desc: This is my personalized boilerplate for C++ console app
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "whatsNext.h"

using namespace std;

int gcd(int a, int b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{

  int h, w, gcf, h1, w1;

  const char *divider = "\n================================================\n";

  cout << "Let's make a right triangle!" << endl
       << divider << endl;

  cout << "How tall do you want it? [3-40 integers only]: ";

  while (true)
  {
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (!cin.fail() && h > 2 && h < 41)
    {
      break;
    }
    else
    {
      cin.clear();
      cout << "Invalid height. Try again [3-40 integers only]: ";
    }
  }

  cout << "You want a " << h << " asterisk tall right triangle." << endl
       << divider << endl;

  // LOOPING IMPLENTATION HERE
  // Clear the screen before showing the triangle.

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
