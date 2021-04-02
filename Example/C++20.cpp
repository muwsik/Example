
#include <iostream>
#include <ranges>
#include <string>
#include <list>


int main_cxx20(void)
{
  std::string my_string{ "1234567" };


  for (const auto symbol : my_string | std::ranges::views::reverse)
  {
    std::cout << symbol;
  }



  return 0;
}
