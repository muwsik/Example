#include <cstdio>

class B
{
public:
  int l;

  //B() : l(-32)
  //{   }
};

class A
{
  int i;
  int array[3];
  B b;

//public:
//  A() = default;

//public:
//  A() : i{ 5 }
//  {   }

//public:
//  A(const A& object) = default;

public:
  void print(const char *str)
  {
    printf("%s = { i = %d | array = { %d %d %d } | b.l = %d }\n",
      str, i, array[0], array[1], array[2], b.l
    );
  }

public:
  ~A() = default;
};



int main_lw2(void)
{
  A k;
  A i{};
  A j = A();

  k.print("k");

  i.print("i");
  j.print("j");

  return 0;
}