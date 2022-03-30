#include <iostream>
#include <string>
#include <chrono>

class ExampleLW5
{
  std::string _field{ '\0' };

public:
  ExampleLW5()
  {
    std::cout << "ExampleLW5()" << std::endl;
  }

public:
  ExampleLW5(std::string temp) : _field(temp)
  {
    std::cout << "ExampleLW5(std::string)" << std::endl;
  }

public:
  ExampleLW5(float temp) : _field(std::to_string(temp))
  {
    std::cout << "ExampleLW5(float)" << std::endl;
  }

public:
  ExampleLW5(int temp) : _field(std::to_string(temp))
  {
    std::cout << "ExampleLW5(int)" << std::endl;
  }

public:
  ~ExampleLW5()
  {
    std::cout << "~ExampleLW5" << std::endl;
  }

public:
  char& operator[](size_t index)
  {
    std::cout << "char& operator[](size_t)" << std::endl;
    return _field[index];
  }

public:
  char const& operator[](size_t index) const
  {
    std::cout << "char const& operator[](size_t) const" << std::endl;
    return _field[index];
  }

public:
  explicit operator std::string()
  {
    return _field;
  }

  //public:
  //  std::string operator+(const ExampleLW5 & temp)
  //  {
  //    return std::string(_field + temp._field);
  //  }

  //////////////////////////////// friends ////////////////////////////

  friend std::string operator+(const ExampleLW5& temp, const ExampleLW5& temp2)
  {
    return std::string(temp._field + temp2._field);
  }

  //friend std::string operator+(int temp, const ExampleLW5 & temp2)
  //{
  //  return std::string(std::to_string(temp) + temp2._field);
  //}

  //template <typename T>
  //friend std::string operator+(T temp, const ExampleLW5 & temp2)
  //{
  //  return std::string(std::to_string(temp) + temp2._field);
  //}

};



int main_lw5(void) 
{
  ExampleLW5 base{ " text " };

  const ::ExampleLW5   temp{ " addition " };
  int                  temp_int{ 1 };
  float                temp_float{ 3.5 };

  std::cout << base + temp << std::endl;
  std::cout << temp + base << std::endl;


  // int
  std::cout << base + temp_int << std::endl;
  std::cout << temp_int + base << std::endl;

  // float
  std::cout << base + temp_float << std::endl;
  std::cout << temp_float + base << std::endl;

  base[1];
  temp[1];

  return EXIT_SUCCESS;
}

template <typename T>
void foo(T temp, typename std::enable_if<std::is_same<T, uint64_t>::value>::type* = 0)
//void foo(T temp, typename std::enable_if_t<std::is_same_v<T, uint64_t>>* = nullptr)
{
  // typeof(temp) == uint64_t
}