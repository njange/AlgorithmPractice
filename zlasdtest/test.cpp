
#include "./exercise1a/test.hpp"
#include "./exercise1b/test.hpp"

#include "./exercise2a/test.hpp"
#include "./exercise2b/test.hpp"

#include "./exercise3a/test.hpp"
#include "./exercise3b/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void lasdtest() {
  cout << endl << "~*~#~*~ Welcome to the LASD Test Suite ~*~#~*~ " << endl;

  uint tottestnum = 0, tottesterr = 0;
  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;
  uint ftestnum = 0, ftesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1A(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise1B(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise1A(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise1B(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  cout << endl << "Exercise 1 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";
  cout << endl << "Exercise 1 (Full Test) (Errors/Tests: " << ftesterr << "/" << ftestnum << ")" << endl;
  tottesterr += ftesterr + stesterr; tottestnum += ftestnum + stestnum;

  stestnum = 0; stesterr = 0; ftestnum = 0; ftesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise2A(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise2B(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise2A(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise2B(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  cout << endl << "Exercise 2 (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";
  cout << endl << "Exercise 2 (Full Test) (Errors/Tests: " << ftesterr << "/" << ftestnum << ")" << endl;
  tottesterr += ftesterr + stesterr; tottestnum += ftestnum + stestnum;

  stestnum = 0; stesterr = 0; ftestnum = 0; ftesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise3A(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise3A(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  cout << endl << "Exercise 3A (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";
  cout << endl << "Exercise 3A (Full Test) (Errors/Tests: " << ftesterr << "/" << ftestnum << ")" << endl;
  tottesterr += ftesterr + stesterr; tottestnum += ftestnum + stestnum;

  stestnum = 0; stesterr = 0; ftestnum = 0; ftesterr = 0;

  loctestnum = 0; loctesterr = 0;
  testSimpleExercise3B(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  testFullExercise3B(loctestnum, loctesterr);
  ftestnum += loctestnum; ftesterr += loctesterr;

  cout << endl << "Exercise 3B (Simple Test) (Errors/Tests: " << stesterr << "/" << stestnum << ")";
  cout << endl << "Exercise 3B (Full Test) (Errors/Tests: " << ftesterr << "/" << ftestnum << ")" << endl;
  tottesterr += ftesterr + stesterr; tottestnum += ftestnum + stestnum;

  cout << endl << "Total Test (Full Test + Simple Test) (Errors/Tests: " << tottesterr << "/" << tottestnum << ")" << endl;

  cout << endl << "Goodbye!" << endl;
}
