#include <iostream>

struct C
{
  bool isOutput = true;
  int j = 0;

  C()
  {
    if (this->isOutput)
      std::cout << "Constructor object C's! | " << this << std::endl;
  }

  ~C()
  {
    if (this->isOutput)
      std::cout << "Destructor object C's!| " << this << std::endl;
  }
};

//int main(void)
//{
//  int *temp = new int[3]{ 1, 2, 3 };
//  int size = *(temp - 1);
//
//  std::cout << size << std::endl;
//
//  delete[] temp;
//  return 0;
//}

int main_lw3(void)
{
  size_t i = 0;
  std::cin >> i;

  C* temp = new C[i];

  C *size = (temp - 1);

  std::cout << size->j << std::endl;;

  delete[] temp;
  return 0;
}