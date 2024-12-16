/* ****************************************************************
 * @author: Jephthah Orobia
 * @app name: whats-next.h
 * @app desc: This library shall contain a function that will stop
 *            the console from exiting and prints options of what to
 *            do next and when user inputs a character, the
 *            the defined action will be invoked.
 * @history:
 *  - 2018/02/08
 *      -- Created _pause() function
 * ****************************************************************/

#ifndef _WHATSNEXT
#define _WHATSNEXT

#include <iostream>
#include <map>
#include <tuple>
#include <functional>

using namespace std;


int whatsNext(map<char, tuple<string, function<int()>>> actionMap)
{
  // Clear the input buffer so that the console doesn't exit immediately
  if(cin.fail()) cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Options:";

  for (const auto& kv: actionMap){
    cout << endl << "\t" << kv.first << "\t - " << get<0>(kv.second);
  }
  cout << endl << "Other keys\t - Exit the app" << endl << endl;

  cout << "Type corresponding key to choose what to do next: ";

  char c = getchar();

  // Clear the input buffer so that the rest of character inputs are ignored.
  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  if(actionMap.find(c) != actionMap.end()){
    return get<1>(actionMap[c])();
  } else {
    return 0;
  }
}

#endif
