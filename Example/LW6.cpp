
#include <type_traits>
#include <functional>
#include <iostream>
#include <string>
#include <chrono>
#include <tuple>


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
    _field = new T[_size];
    memcpy((void*)_field, value, _size * sizeof(T));
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

template<typename First, typename ... Types>
auto conv_v2(const First& first, const Types& ... args)
{
  return first + conv_v2(args...);
}

template<typename ... Types>
constexpr auto conv_v3(const Types& ... args)
{
  return (args + ...);
}

//////////////////////////////////////////////////////


template <class F, class ...Args>
auto Timer(F&& f, Args&& ...args)
{
  //if constexpr (std::is_same_v<std::invoke_result_t<F, Args...>, void>)
  if constexpr (std::is_void_v<decltype(f(args...))>)
  {
    auto start = std::chrono::high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();

    return end - start;
  }
  else
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto temp = f(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();

    return std::make_pair(temp, end - start);
  }
}

template <class O, class F, class ...Args>
auto Timer(O& o, F&& f, Args&& ...args)
{
  if constexpr (std::is_void_v<decltype((o.*f)(args...))>)
  {
    auto start = std::chrono::high_resolution_clock::now();
    (o.*f)(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
  }
  else
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto temp = (o.*f)(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::make_pair(temp, end - start);
  }
}


int bar(int& i, float j)
{
  std::cout << i << " " << j << std::endl;
  return i = 5;
}

void foo(float j)
{
  std::cout << j << std::endl;
}

class L
{
  std::string temp{ "0x" };

public:
  L() = default;

public:
  L(const std::string_view& str) :temp(str)
  {  }

public:
  bool foo(const std::string_view& str)
  {
    std::cout << temp << str << std::endl;
    return true;
  }

public:
  void foo(void)
  {
    std::cout << temp << std::endl;
  }
};

int main_lw6(void)
{
  int i = -32;
  float j = 2.02f;
  L l, l2{ "text_" };

  auto rez1 = Timer(&bar, i, j);
  std::cout << rez1.first << std::endl;
  std::cout << rez1.second.count() / 1'000'000'000.0 << std::endl;
  std::cout << "-----------------" << std::endl;

  auto rez2 = Timer(&foo, j);
  std::cout << rez2.count() / 1'000'000'000.0 << std::endl;
  std::cout << "-----------------" << std::endl;

  bool (L::* foo1)(const std::string_view &) = &L::foo;
  auto res3 = Timer(l, foo1, std::string("123"));
  std::cout << res3.first << std::endl;
  std::cout << res3.second.count() / 1'000'000'000.0 << std::endl;
  std::cout << "-----------------" << std::endl;
  
  void (L::* foo2)(void) = &L::foo;
  auto res4 = Timer(l, foo2);
  std::cout << res4.count() / 1'000'000'000.0 << std::endl;

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