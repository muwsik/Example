#include <iostream>

struct C
{
  int j = 0;

  C()
  {
    std::cout << "Constructor object C's! | this " << this << std::endl;
  }

  ~C()
  {
    std::cout << "Destructor object C's!| this " << this << std::endl;
  }

  void reset()
  {
    this->~C();
    new (this) C();
  }

};

int main_lw3(void)
{
  C* pointer = (C*)calloc(1, sizeof(C));
  std::cout << "pointer = " << pointer << std::endl;

  new (pointer) C();

  //pointer->reset();

  pointer->~C();

  free(pointer);


  return EXIT_SUCCESS;
}