#include "LW6.h"
#include <iostream>
#include <iomanip>


DEFINE_ARRAY(int, IntArray)
DEFINE_ARRAY(double, RealArray)
DEFINE_ARRAY(IntArray, IntMatrix)

void exp_with_int_matrix(void)
{
  IntMatrix matrix(9, IntArray(11));

  for (size_t i = 0; i < matrix.Size(); i++)
    for (size_t j = 0; j < matrix[i].Size(); j++)
      matrix[i][j] = rand() % (100) - static_cast<int>(i * j);

  for (size_t i = 0; i < matrix.Size(); i++)
  {
    for (size_t j = 0; j < matrix[i].Size(); j++)
      std::cout << std::setw(3) << matrix.operator[](i).operator[](j) << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void exp_with_real(void)
{
  RealArray array(20);

  for (size_t i = 0; i < array.Size(); i++)
  {
    array[i] = 3.14 * i;
  }

  for (size_t i = 0; i < array.Size(); i++)
  {
    std::cout << array[i] << ' ';
  }
  std::cout << std::endl;
}

int main_cpp88(void)
{
  IntArray my_lovely_integer_array(10);

  for (size_t i = 0; i < my_lovely_integer_array.Size(); i++)
  {
    my_lovely_integer_array[i] = (int)i;
  }

  for (size_t i = 0; i < my_lovely_integer_array.Size(); i++)
  {
    std::cout << my_lovely_integer_array[i] << ' ';
  }
  std::cout << std::endl;

  exp_with_real();

  exp_with_int_matrix();

  return 0;
}