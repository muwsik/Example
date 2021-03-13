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