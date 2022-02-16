/*Точность, при которой два вещественных числа считаются одинаковыми*/
static const float epsilon = 1e-6;

//I. Класс "Односвязный список"
//- Итерирование по элементам осуществляется с помощью "указателя" 
//  на следующий элемент, который хранится в текущем элементе списка
//- Содержит в себе дополнительную структуру - "Элемент списка",
//  которая хранит значение элемента списка и указатель на следующий элемент  
class LIST
{
private:
  //Структура "Элемент списка"
  struct Node
  {
    /*Значение элемента списка*/
    float value;

    /*Указатель на следующий элемент списка*/
    Node* next;
  };

  /*Указатель на первый элемент списка*/
  Node* head;

public:

  /*Конструктор по умолчанию*/
  LIST();

  /*Конструктор копирования*/
  LIST(const LIST&);

  /*Деструктор*/
  ~LIST();

  /*Получить значение элемента списка
  (без проверки выхода за границу)*/
  float at(unsigned int index)const;

  /*Изменяет значение элемента списка*/
  bool set(unsigned int index, float value);

  /*Добавить в список элемент*/
  bool insert(unsigned int index, float value);

  /*Удалить элемент списка*/
  bool remove(unsigned int index);

  /*Печать элементов списка*/
  friend void print();


  /*1. Инициализация нулями элементов списка*/
  LIST(unsigned int size);

  /*2. Инициализация значением value элементов списка*/
  LIST(unsigned int size, float value);

  /*3. Возвращает true, если список пуст*/
  bool isEmpty() const;

  /*4. Возвращает список индексов элементов со значением value*/
  LIST findValue(float value) const;

  /*5. Сортировка элементов списка в зависимости от порядка order*/
  LIST sort(bool order) const;

  /*6. Объединяет список this и список other*/
  LIST splice(const LIST other) const;

  /*7. Формирует список только из уникальных элементов*/
  LIST unique() const;

  /*8. Меняет порядок элементов в списке на обратный*/
  LIST reverse() const;

  /*9. Объединяет отсортированные списки this и other*/
  LIST merge(const LIST other) const;

  /*10. Очищает список*/
  bool clear();

  /*11. Удаляет элементы списка в интервале [first, last)*/
  bool erase(unsigned int first, unsigned int last);

  /*12. Изменяет размер списка*/
  void resize(unsigned int newSize);

  /*13. Добавляет элемент в начало списка*/
  bool push_front(float value);

  /*14. Возвращает текущий размер списка*/
  unsigned int size() const;

};
///https://habr.com/ru/sandbox/153128/


//II. Класс "Множество"
//- Хранит уникальные элементы, отсортированные по значению
//- Итерирование по элементам осуществляется с помощью адресной арифметики
class SET
{
private:

  /*Указатель на первый элемент множества*/
  float* begin;

  /*Указатель на последний элемент множества*/
  float* end;

public:

  /*Конструктор по умолчанию*/
  SET();

  /*Конструктор копирования*/
  SET(const SET&);

  /*Деструктор*/
  ~SET();

  /*Получить значение элемента множества
  (без проверки выхода за границу)*/
  float at(unsigned int index) const;

  /*Изменяет значение элемента множества*/
  bool set(unsigned int index, float value);

  /*Добавить в множествао элемент*/
  bool push(float value);

  /*Удалить элемент множества*/
  bool remove(unsigned int index);

  /*Печать элементов множества*/
  friend void print();


  /*1. Объединение множеств*/
  SET inUnion(const SET A) const;

  /*2. Пересечение множеств*/
  SET intersection(const SET A) const;

  /*3. Объединение текущего множества с множеством A*/
  void update(const SET A);

  /*4. Разность множеств
       (элементы, входящие в this, но не входящие в А)*/
  SET difference(const SET A) const;

  /*5. Симметрическая разность множеств
       (элементы, входящие в this или в А, но не в оба из них одновременно)*/
  SET symmetricDifference(const SET A) const;

  /*6. Возвращает true, если this является подмножеством A*/
  bool isSubset(const SET A) const;

  /*7. Находит элемент с заданным значением*/
  unsigned int find(float value) const;

  /*8. Возвращает true, если множество this имеет меньше элементов, чем множество A*/
  bool isLess(const SET A) const;

  /*9. Возвращает текущий размер множества*/
  bool size(const SET A) const;

  /*10. Возвращает true, если множество содержит заданный элемент*/
  bool conteins(float value) const;

  /*11. Возвращает true, если множество пустое*/
  bool isEmpty();
};


//III. Класс "Строка"
//- Итерирование по элементам осуществляется с помощью адресной арифметики
//- Согласно стандарту языка С/С++, ЛЮБАЯ строка ВСЕГДА должна заканчиваться
//  символом конца строки '\0'
class STRING
{
private:
  char* buff;

public:
  /*Конструктор по умолчанию*/
  STRING();

  /*Конструктор копирования*/
  STRING(const STRING&);

  /*Деструктор*/
  ~STRING();

  /*Получить значение символа строки
  (без проверки выхода за границу)*/
  float at(unsigned int index);

  /*Заменяет символ строки*/
  bool set(unsigned int index, char symbol)

  /*Добавить в строку символ*/
  bool insert(unsigned int index, char symbol);

  /*Удалить элемент строки*/
  bool remove(unsigned int index);

  /*Печать строки*/
  friend void print();


  /*1. Инициализация строкой в стиле С (копирование)*/
  STRING(const char* const c_string);

  /*2. Возвращает true, если строка пустая*/
  bool isEmpty() const;

  /*3. Длина строки*/
  unsigned int length() const;

  /*4. Сравнение строк this и other*/
  int compare(const STRING other) const;

  /*5. Добавляет в конец текущей строки this строку other*/
  STRING append(const STRING other) const;

  /*6. Взятие подстроки размера count начиная с индекса start*/
  STRING substr(unsigned int start, unsigned int count) const;

  /*7. Изменение размера строки*/
  void resize(unsigned int newSize);

  /*8. Заменяем в строке this символы в диапазоне [start, count)
       на ВСЕ символы из строки с_str*/
  STRING replace(unsigned int start, unsigned int count,
    const char* const c_str) const;

  /*9. Находит первый символ, равный одному из символов в заданной
        последовательности символов str, начиная с позиции start*/
  unsigned int findFirstOf(const STRING str, unsigned int start) const;

  /*10. Находит последний символ, равный одному из символов в заданной
        последовательности символов str, начиная с позиции start*/
  unsigned int findLastOf(const STRING str, unsigned int start) const;

  /*11. Находит первую подстроку, равную str, начиная с позиции start*/
  unsigned int find(const STRING str, unsigned int start) const;

  /*12. Находит последную подстроку, равную str, начиная с позиции start*/
  unsigned int rfind(const STRING str, unsigned int start) const;

};


//IV. Класс "Вектор"
//- Итерирование по элементам осуществляется с помощью адресной арифметики
class VECTOR
{
private:

  /*Указатель на первый элемент массива*/
  float* begin;

  /*Указатель на последний элемент массива*/
  float* end;

public:
  /*Конструктор по умолчанию*/
  VECTOR();

  /*Конструктор копирования*/
  VECTOR(const VECTOR&);

  /*Деструктор*/
  ~VECTOR();

  /*Получить значение элемента массива
  (без проверки выхода за границу)*/
  float at(unsigned int index);

  /*Изменяет значение элемента массива*/
  bool set(unsigned int index, float value);

  /*Добавить в массив элемент*/
  bool insert(unsigned int index, float value);

  /*Удалить элемент массива*/
  bool remove(unsigned int index);

  /*Печать массива*/
  friend void print();


  /*1. Инициализация нулями элементов массива*/
  VECTOR(unsigned int size);

  /*2. Инициализация значением value элементов массива*/
  VECTOR(unsigned int size, float value);

  /*3. Возвращает true, если массив пустой*/
  bool isEmpty() const;

  /*4. Возвращает текущий размер массива*/
  unsigned int size() const;

  /*5. Очищает массив*/
  void clear();

  /*6. Удаляет элементы массива в интервале [first, last)*/
  bool erase(unsigned int first, unsigned int last);

  /*7. Добавить элемент со значеним value в конец массива*/
  void push_back(float value);

  /*8. Удалить последний элемент массива*/
  void pop_baсk();

  /*9. Изменение размера массива*/
  void resize(unsigned int newSize);

  /*10. Сортировка элементов массива в зависимости от порядка order*/
  VECTOR sort(bool order) const;

  /*11. Вычисление нормы вектора*/
  float Norm() const;

  /*12. Скалярное произведение векторов*/
  float Mult(const VECTOR other) const;

};