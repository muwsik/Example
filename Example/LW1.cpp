#include <iostream>

//clang -fno-elide-constructors

class foo {
public:

  foo() { std::cout << "foo::foo( ) | this = " << this << std::endl; }
  foo(const foo& T) {
    std::cout << "foo::foo( const foo& T ) | T = " << &T
      << " | this = " << this << std::endl;
  }
  ~foo() { std::cout << "foo::~foo( ) | " << this << std::endl; }
};

foo bar() {
  foo local_foo;
  return local_foo;
}

foo bar2()
{
  return foo();
}

int main_lw1()
{
  std::cout << " foo f = bar() " << std::endl;
  foo f = bar();

  std::cout << " foo f = bar2() " << std::endl;
  foo f2 = bar2();

  return 0;
}

// #define CONST 2.01
 constexpr auto CONST = 2.01;

int main_(void)
{
  double f;
  while (true)
  {
    std::cin >> f ;

    if ((CONST - f) == 0.0)
      std::cout << "is 2.01";
    else
      std::cout << "other";

    std::cout << std::endl << std::endl;
  }

  return EXIT_SUCCESS;
}









// 2.0099999999999998