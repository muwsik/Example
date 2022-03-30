#include <iostream>

class Abstract
{
private:
  int _field;


public:
  virtual Abstract* Foo(const Abstract* const value,
    Abstract* const memory) const = 0;

public:
  virtual void print() const
  {
    std::cout << " > class Abstract: _field  = " << _field << std::endl;
  }

public:
  Abstract() : _field{}
  {
    std::cout << "Abstract()" << std::endl;
  }

public:
  Abstract(const Abstract& obj) : _field{ obj._field }
  {
    std::cout << "Abstract(const Abstract&)" << std::endl;
  }

public:
  virtual ~Abstract()
  {
    std::cout << "~Abstract()" << std::endl;
  }
};


class Base : public Abstract
{
private:
  int _member;


public:
  Base() : _member{}
  {
    std::cout << "Base()" << std::endl;
  }

public:
  Base(const int first) : _member(first)
  {
    std::cout << "Base(const int)" << std::endl;
  }

public:
  Base(const Base& obj) : Abstract(obj), _member(obj._member)
  {
    std::cout << "Base(const Base&)" << std::endl;
  }

public:
  virtual Abstract* Foo(const Abstract* const value,
    Abstract* const memory) const override
  {
    const Base* const temp_value = dynamic_cast<const Base* const>(value);
    Base* const temp_memory = dynamic_cast<Base* const>(memory);

    if ((temp_value != nullptr) && (temp_memory != nullptr))
    {
      temp_memory->_member = temp_value->_member + this->_member;
    }
    else
      return nullptr;

    return temp_memory;
  }

public:
  void print() const override
  {
    std::cout << " > class Base: _member  = " << _member << std::endl;
    Abstract::print();
  }

public:
  virtual ~Base()
  {
    std::cout << "~Base()" << std::endl;
  }
};


class Product : public Base
{
private:
  int* _member;


public:
  Product() : _member{ new int(0) }
  {
    std::cout << "Product()" << std::endl;
  }

public:
  Product(int* first) : _member{ new int(*first) }
  {
    std::cout << "Product(int*)" << std::endl;
  }

public:
  Product(const Product& obj) : Base{ obj } //_member{ new int{ *(obj._member) } }
  {
    _member = new int{ *(obj._member) };
    std::cout << "Product(const Product&)" << std::endl;
  }

public:
  virtual Abstract* Foo(const Abstract* const value,
    Abstract* const memory) const override
  {
    const Product* const temp_value = dynamic_cast<const Product* const>(value);
    Product* const temp_memory = dynamic_cast<Product* const>(memory);

    if ((temp_value != nullptr) && (temp_memory != nullptr))
    {
      *(temp_memory->_member) = *(temp_value->_member) + *(this->_member);
    }
    else
      return nullptr;

    return temp_memory;
  }

public:
  void print() const
  {
    std::cout << " > class Product: _member  = " << *_member << std::endl;
    Base::print();
  }

public:
  virtual ~Product()
  {
    std::cout << "~Product()" << std::endl;
    delete this->_member;
  }
};


int main(void)
{
  int temp = 7;

  Base objBase(12);
  Product objProduct(&temp);

  Base resultBase;
  Product resultProduct;

  Abstract* result = objProduct.Foo(&objBase, &resultProduct);
  if (result != nullptr)
    result->print();
  else
    std::cout << " > Uncorrect!" << std::endl;

  return EXIT_SUCCESS;
}