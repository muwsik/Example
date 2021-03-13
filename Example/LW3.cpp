#include <iostream>

struct C
{
  int j = 0;

  C()
  {
    std::cout << "Constructor object C's! | " << this << std::endl;
  }

  ~C()
  {
    std::cout << "Destructor object C's!| " << this << std::endl;
  }

  //operator int()
  //{
  //  return j;
  //}
};

int main_lw3(void)
{
  int *temp = new int[3]{ 1, 2, 3 };
  int size = *(temp - 1);

  std::cout << size << std::endl;

  delete[] temp;
  return 0;
}

int main_class_lw3(void)
{
  //size_t i = 0;
  //std::cin >> i;

  C* temp = new C[15];

  C size = *(temp - 1);

  std::cout << size.j << std::endl;;

  delete[] temp;
  return 0;
}