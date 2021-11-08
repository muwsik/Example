#include <iostream>

class Base
{
private:
  int _private_member;
public:
  float _public_member;

public:
  Base() : _private_member{}, _public_member{}
  {   }

public:
  Base(const int first, const float second) :
    _private_member(first), _public_member(second)
  {   }

public:
  ~Base() = default;
};


class Product : Base
{
private:
  int* _private_member;
public:
  char _public_member;

public:
  Product() : _private_member{}, _public_member{}
  {
    dynamic_cast<Base*>(this)->_public_member; /* ѕотенциальное разыменование нулевого указател€ */
    /* ѕомните, каждый раз, когда используетс€ dynamic_cast в мире умирает один котЄнок (с) */
    Base::_public_member;
  }

public:
  Product(int* first, const char second) : 
    _private_member(first), _public_member(second)
  {   }

public:
  ~Product() = default;
};

int main(void)
{
  Base objectA(1, 5.0);
  Product objectB(nullptr, '4');

  Product obj;

  return EXIT_SUCCESS;
}