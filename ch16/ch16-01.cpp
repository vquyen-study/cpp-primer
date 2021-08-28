#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.1: Define instantiation.
 *  When the compiler instantiates a template, it creates a new “instance” of
 *  the template using the actual template argument(s) in place of the
 *  corresponding template parameter(s).
 * 
 */

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct Color
{
    set<string> sset;
};

struct RedFlower : Flower, Color
{
  Flower& flower;

  RedFlower(Flower &flower) : flower(flower) 
  {
      if (sset.empty())
          sset.insert(" that is red");
      else
        sset.insert(" and red");
  }

  string str() override
  {
    ostringstream oss;
    string s = flower.str();
    oss << s;
    for (auto&& p : sset)
        oss << p;
    
    return oss.str();

  }
};

struct BlueFlower : Flower, Color
{
  Flower& flower;

  BlueFlower(Flower &flower) : flower(flower) 
  {
      if (sset.empty())
          sset.insert(" that is blue");
      else
        sset.insert(" and blue");
  }

  string str() override
  {
    ostringstream oss;
    string s = flower.str();
    oss << s;
    for (auto&& p : sset)
        oss << p;
    
    return oss.str();
  }
};

int main(int argc, char **argv)
{

    cout << "hello word ch16-01 " << endl;
    return 0;
}