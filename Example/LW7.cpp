#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <iomanip>

/// C++
class CPP
{
private:
  int         _int;
  float       _float;
  std::string _string;
  std::vector<char> _vectorChars;

public:
  explicit CPP(int vInt, float vFloat, std::string vString, std::vector<char> vVectorChars) noexcept
    : _int(vInt), _float(vFloat), _string(vString), _vectorChars(vVectorChars)
  { }

#if _HAS_CXX17 
public:
  auto GetFields()
  {
    return std::tuple<int, float&, std::string, std::vector<char>>{ _int, _float, _string, _vectorChars };
  }
#else
public:
  std::tuple<int, float&, std::string, std::vector<char>> GetFields()
  {
    return std::tuple<int, float&, std::string, std::vector<char>>
      {_int, _float, _string, _vectorChars};
  }
#endif // !_HAS_CXX17 


  void Print()
  {
    std::cout << _int << std::endl << _float << std::endl
      << _string << std::endl << _vectorChars.data() << std::endl;
  }
};


int main_lw7(void)
{
  {
    CPP cpp14{ 14, 3.333f, "C++14", {1, 2, 3, '\0'} };

    int i;
    float j;
    std::string k;
    std::vector<char> l;

    std::tie(i, j, k, l) = cpp14.GetFields();
    std::cout << i << std::endl << j << std::endl
      << k << std::endl << l.data() << std::endl;

    std::get<1>(cpp14.GetFields()) = -2.09999f;
    cpp14.Print();

    j = -214524.3f;
    cpp14.Print();
  }

  {
    CPP cpp17{ 17, 2.2222f, "C++17", {4, 3, 2, 1, '\0'} };
    const auto& [i, j, k, l] = cpp17.GetFields();
    std::cout << i << std::endl << j << std::endl
      << k << std::endl << l.data() << std::setw(10) << std::endl;

    j = -54526437.0f;
    cpp17.Print();
  }

  return 0;
}