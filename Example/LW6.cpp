
#include <type_traits>
#include <functional>
#include <iostream>
#include <string>
#include <chrono>
#include <tuple>

/*
#define TIME_CAST(time_to_cast) \
  std::chrono::duration_cast<std::chrono::microseconds>(time_to_cast) 
*/

///////////////////// Шаблонный класс /////////////////

template<typename T>
class ExampleLW6
{

public:
  ExampleLW6(T value) : _field(value)
  {		}

public:
  void foo(void);

public:
  ~ExampleLW6()
  {		}

public:
  template <typename U>
  friend std::ostream& operator<<(std::ostream& stream, const ExampleLW6<U>& obj);

public:
  T _field;
  //private:
  //  std::string str{ "pepega" };
};

template <typename U>
std::ostream& operator<<(std::ostream& stream, const ExampleLW6<U>& obj)
{
  stream << obj._field << std::endl;
  return stream;
}

///////// Частичная специализация шаблона-класса ////////////

template<typename T>
class ExampleLW6<T*>
{
public:
  ExampleLW6(T* value, size_t size) : _size(size)
  {
    throw std::exception();
    //_field = new T[_size];
    //memcpy((void*)_field, value, _size * sizeof(T));
  }

public:
  ~ExampleLW6()
  {
    delete[] _field;
  }

public:
  template <typename U>
  friend std::ostream& operator<< (std::ostream& stream, const ExampleLW6<U*>& obj);

private:
  T* _field;
private:
  size_t _size;
};

template <typename U>
std::ostream& operator<<(std::ostream& stream, const ExampleLW6<U*>& obj)
{
  for (size_t i = 0; i < obj._size; ++i)
  {
    stream << obj._field[i] << " ";
  }

  return stream << std::endl;
}

template <>
std::ostream& operator<< <const char>(std::ostream& stream, const ExampleLW6<const char*>& obj)
{
  for (size_t i = 0; i < obj._size; ++i)
  {
    stream << obj._field[i];
  }

  return stream << std::endl;
}

///////// Полная специализация шаблона-функции ///////

template<typename X, typename Y>
auto conv_v1(const X& x, const Y& y) -> decltype(x + y)
{
  return x + y;
}

template<typename Y>
auto conv_v1(const int& x, const Y& y) -> decltype(2ull * x + y)
{
  return 2ull * x + y;
}

template<>
auto conv_v1<int, double>(const int& x, const double& y) -> decltype(4ull * x + y)
{
  return 4ull * x + y;
}

template<>
auto conv_v1<double>(const int& x, const double& y) -> decltype(6ull * x + y)
{
  return 6ull * x + y;
}

///// Вариативный шаблон и свёртка ///////////

auto conv_v2()
{
  return 0;
}

template<typename FirstType, typename ... OtherTypes>
auto conv_v2(const FirstType& first, const OtherTypes& ... args)
{
  return first + conv_v2(args...);
}

template<typename ... Types>
constexpr auto conv_v3(const Types& ... args)
{
  return (args + ...);
}

//////////////////////////////////////////////////////


template <class FunctionType, class ...ArgsTypes>
auto Timer(FunctionType&& f, ArgsTypes&& ...args)
{
  //if constexpr (std::is_same_v<std::invoke_result_t<FunctionType, ArgsTypes...>, void>)
  if constexpr (std::is_void_v<decltype(f(args...))>)
  {
    auto start = std::chrono::high_resolution_clock::now();
    f(std::forward<ArgsTypes>(args)...);
    auto end = std::chrono::high_resolution_clock::now();

    return end - start;
  }
  else
  {
    auto start = std::chrono::high_resolution_clock::now();
    //auto temp = f(std::forward<ArgsTypes>(args)...);
    auto temp = f(std::forward<ArgsTypes>(args)...);
    auto end = std::chrono::high_resolution_clock::now();

    return std::pair(temp, end - start);
  }
}

template <class ObjectType, class FunctionType, class ...ArgsTypes>
auto Timer(ObjectType& o, FunctionType&& f, ArgsTypes&& ...args)
{
  if constexpr (std::is_void_v<decltype((o.*f)(args...))>)
  {
    auto start = std::chrono::high_resolution_clock::now();
    (o.*f)(std::forward<ArgsTypes>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
  }
  else
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto temp = (o.*f)(std::forward<ArgsTypes>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::pair(temp, end - start);
  }
}


int bar(int& i, float j)
{
  //std::cout << i << " " << j << std::endl;
  std::cout << "int bar(int& i, float j)" << std::endl;
  return i = 5;
}

int foo(int j)
{
  std::cout << "int foo(int j)" << std::endl;
  return j = -5;
}

void foo(float j)
{
  std::cout << "void foo(float j)" << std::endl;
  //std::cout << j << std::endl;
}

class L
{
  std::string temp{ "0_" };

public:
  L() = default;
public:
  ~L() = default;

public:
  L(const std::string_view& str) :temp(str)
  {  }

public:
  bool foo(const std::string_view& str)
  {
    std::cout << "bool L::foo(const std::string_view& str)" << std::endl;
    std::cout << temp << str << std::endl;
    return true;
  }

public:
  void foo(void)
  {
    std::cout << "void L::foo(void)" << std::endl;
    //std::cout << temp << std::endl;
  }
};

int main_lw6(void)
{
  int i = -32;
  float j = 2.02f;
  L l, l2{ "text_" };

  auto rez1 = Timer(&bar, i, j);
  std::cout << rez1.first << std::endl;
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(rez1.second) << std::endl;
  std::cout << "-----------------" << std::endl;

  auto rez5 = Timer<int(*)(int), int&>(&foo, i);
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(rez5.second) << std::endl;
  std::cout << "-----------------" << std::endl;

  auto rez2 = Timer<void(*)(float), float&>(&foo, j);
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(rez2) << std::endl;
  std::cout << "-----------------" << std::endl;

  bool (L::* foo1)(const std::string_view &) = &L::foo;
  auto res3 = Timer(l, foo1, "123");
  std::cout << res3.first << std::endl;
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(res3.second)<< std::endl;
  std::cout << "-----------------" << std::endl;
  
  void (L::* foo2)(void) = &L::foo;
  auto res4 = Timer(l, foo2);
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(res4) << std::endl;

  return 0;
}

//////////////////////////////////////////////////////

int main_lw6_v2(void)
{

  ::ExampleLW6 temp(10u);
  std::cout << temp;

  ::ExampleLW6<::ExampleLW6<uint32_t>> test(temp);
  std::cout << test;



  const char* str = "text";
  ::ExampleLW6<const char*> temp2(str, 5);
  std::cout << temp2;

  float temp_array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  ::ExampleLW6<float*> temp3(temp_array, 10);
  std::cout << temp3;



  std::cout << conv_v1(3, 4.5) << std::endl;

  std::cout << conv_v1('4', conv_v1(2u, conv_v1(4.155, 85))) << std::endl;
  std::cout << conv_v2('4', 2u, 4.155, 85) << std::endl;
  std::cout << conv_v3('4', 2u, 4.155, 85) << std::endl;

  return EXIT_SUCCESS;
}