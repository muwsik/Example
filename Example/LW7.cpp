#include <iostream>

void foo1(int** ptr, size_t new_size)
{
  delete[] *ptr;
  *ptr = new int[new_size];

  for (size_t i = 0; i < new_size; i++)
  {
    (*ptr)[i] = int(i + i);
  }
}


void print(int* ptr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << ptr[i] << " ";
  }
  std::cout << std::endl;
}

int main_(void)
{
  int* ptr = new int[5]{ 1,2,3,4,5 };
  print(ptr, 5);

  foo1(&ptr, 3);
  print(ptr, 3);

  foo1(&ptr, 8);
  print(ptr, 8);

  delete[] ptr;

  return 0;
}