/* ****************************************************************
 * @author: JEPHTHAH M. OROBIA
 * @app name: AMAOEd-Cpp-MyTemplate
 * @app desc: This is my personalized boilerplate for C++ console app
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include "whatsNext.h"

using namespace std;

int main()
{

  char name[50];

  const char *divider = "\n================================================\n";

  cout << "Let's try basic input-output console routine!" << endl
       << divider << endl;

  cout << "What is your first name? ";

  cin >> name;

  cout << "Hello " << name << endl
       << divider << endl;

  map<char, tuple<string, function<int()>>> actions = {
      {'A', make_tuple("Re-Run App",
                       []()
                       {
                         system("cls");
                         return main();
                       })},
      {'B', make_tuple("Count 10 to 1 the re-run app",
                       []()
                       {
                         system("cls");
                         for (int i = 10; i > 0; i--)
                         {
                           cout << i << endl;
                           this_thread::sleep_for(chrono::seconds(1));
                         };
                         system("cls");
                         return main();
                       })},
      {'b', make_tuple("Count 1 to 10 the re-run app",
                       []()
                       {
                         system("cls");
                         for (int i = 1; i <= 10; i++)
                         {
                           cout << i << endl;
                           this_thread::sleep_for(chrono::seconds(1));
                         };
                         system("cls");
                         return main();
                       })}};

  return whatsNext(actions);
}
