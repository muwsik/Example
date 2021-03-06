#pragma once
#include <cstring>

#define DEFINE_ARRAY(Type, Name) \
  class Name \
  { \
    size_t size; \
    Type* ptr; \
  public: \
    Name():size{}, ptr{} { ; } \
    \
    Name(size_t count, Type default_value = Type()) \
      : size(count), ptr(new Type[count]{}) { \
      for (size_t i = 0; i < count; i++) { \
        ptr[i] = default_value; \
      } \
    } \
    \
    Name& operator=(Name& obj) { \
      if (this != &obj) { \
        size = obj.size; \
        delete[] ptr; \
        ptr = new Type[size]{}; \
        std::memcpy(ptr, obj.ptr, size); \
      } \
      return *this; \
    } \
    \
    Name(const Name& obj) : size(obj.size), ptr(new Type[size]{}) { \
      std::memcpy(ptr, obj.ptr, size); \
    } \
    \
    size_t Size() { return this->size; } \
    \
    ~Name() { delete[] ptr; }\
    \
    Type& operator[](size_t index) { return ptr[index]; } \
  };