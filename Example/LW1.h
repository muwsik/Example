/*��������, ��� ������� ��� ������������ ����� ��������� �����������*/
static const float epsilon = 1e-6;

//I. ����� "����������� ������"
//- ������������ �� ��������� �������������� � ������� "���������" 
//  �� ��������� �������, ������� �������� � ������� �������� ������
//- �������� � ���� �������������� ��������� - "������� ������",
//  ������� ������ �������� �������� ������ � ��������� �� ��������� �������  
class LIST
{
private:
  //��������� "������� ������"
  struct Node
  {
    /*�������� �������� ������*/
    float value;

    /*��������� �� ��������� ������� ������*/
    Node* next;
  };

  /*��������� �� ������ ������� ������*/
  Node* head;

public:

  /*����������� �� ���������*/
  LIST();

  /*����������� �����������*/
  LIST(const LIST&);

  /*����������*/
  ~LIST();

  /*�������� �������� �������� ������
  (��� �������� ������ �� �������)*/
  float at(unsigned int index)const;

  /*�������� �������� �������� ������*/
  bool set(unsigned int index, float value);

  /*�������� � ������ �������*/
  bool insert(unsigned int index, float value);

  /*������� ������� ������*/
  bool remove(unsigned int index);

  /*������ ��������� ������*/
  friend void print();


  /*1. ������������� ������ ��������� ������*/
  LIST(unsigned int size);

  /*2. ������������� ��������� value ��������� ������*/
  LIST(unsigned int size, float value);

  /*3. ���������� true, ���� ������ ����*/
  bool isEmpty() const;

  /*4. ���������� ������ �������� ��������� �� ��������� value*/
  LIST findValue(float value) const;

  /*5. ���������� ��������� ������ � ����������� �� ������� order*/
  LIST sort(bool order) const;

  /*6. ���������� ������ this � ������ other*/
  LIST splice(const LIST other) const;

  /*7. ��������� ������ ������ �� ���������� ���������*/
  LIST unique() const;

  /*8. ������ ������� ��������� � ������ �� ��������*/
  LIST reverse() const;

  /*9. ���������� ��������������� ������ this � other*/
  LIST merge(const LIST other) const;

  /*10. ������� ������*/
  bool clear();

  /*11. ������� �������� ������ � ��������� [first, last)*/
  bool erase(unsigned int first, unsigned int last);

  /*12. �������� ������ ������*/
  void resize(unsigned int newSize);

  /*13. ��������� ������� � ������ ������*/
  bool push_front(float value);

  /*14. ���������� ������� ������ ������*/
  unsigned int size() const;

};
///https://habr.com/ru/sandbox/153128/


//II. ����� "���������"
//- ������ ���������� ��������, ��������������� �� ��������
//- ������������ �� ��������� �������������� � ������� �������� ����������
class SET
{
private:

  /*��������� �� ������ ������� ���������*/
  float* begin;

  /*��������� �� ��������� ������� ���������*/
  float* end;

public:

  /*����������� �� ���������*/
  SET();

  /*����������� �����������*/
  SET(const SET&);

  /*����������*/
  ~SET();

  /*�������� �������� �������� ���������
  (��� �������� ������ �� �������)*/
  float at(unsigned int index) const;

  /*�������� �������� �������� ���������*/
  bool set(unsigned int index, float value);

  /*�������� � ���������� �������*/
  bool push(float value);

  /*������� ������� ���������*/
  bool remove(unsigned int index);

  /*������ ��������� ���������*/
  friend void print();


  /*1. ����������� ��������*/
  SET inUnion(const SET A) const;

  /*2. ����������� ��������*/
  SET intersection(const SET A) const;

  /*3. ����������� �������� ��������� � ���������� A*/
  void update(const SET A);

  /*4. �������� ��������
       (��������, �������� � this, �� �� �������� � �)*/
  SET difference(const SET A) const;

  /*5. �������������� �������� ��������
       (��������, �������� � this ��� � �, �� �� � ��� �� ��� ������������)*/
  SET symmetricDifference(const SET A) const;

  /*6. ���������� true, ���� this �������� ������������� A*/
  bool isSubset(const SET A) const;

  /*7. ������� ������� � �������� ���������*/
  unsigned int find(float value) const;

  /*8. ���������� true, ���� ��������� this ����� ������ ���������, ��� ��������� A*/
  bool isLess(const SET A) const;

  /*9. ���������� ������� ������ ���������*/
  bool size(const SET A) const;

  /*10. ���������� true, ���� ��������� �������� �������� �������*/
  bool conteins(float value) const;

  /*11. ���������� true, ���� ��������� ������*/
  bool isEmpty();
};


//III. ����� "������"
//- ������������ �� ��������� �������������� � ������� �������� ����������
//- �������� ��������� ����� �/�++, ����� ������ ������ ������ �������������
//  �������� ����� ������ '\0'
class STRING
{
private:
  char* buff;

public:
  /*����������� �� ���������*/
  STRING();

  /*����������� �����������*/
  STRING(const STRING&);

  /*����������*/
  ~STRING();

  /*�������� �������� ������� ������
  (��� �������� ������ �� �������)*/
  float at(unsigned int index);

  /*�������� ������ ������*/
  bool set(unsigned int index, char symbol)

  /*�������� � ������ ������*/
  bool insert(unsigned int index, char symbol);

  /*������� ������� ������*/
  bool remove(unsigned int index);

  /*������ ������*/
  friend void print();


  /*1. ������������� ������� � ����� � (�����������)*/
  STRING(const char* const c_string);

  /*2. ���������� true, ���� ������ ������*/
  bool isEmpty() const;

  /*3. ����� ������*/
  unsigned int length() const;

  /*4. ��������� ����� this � other*/
  int compare(const STRING other) const;

  /*5. ��������� � ����� ������� ������ this ������ other*/
  STRING append(const STRING other) const;

  /*6. ������ ��������� ������� count ������� � ������� start*/
  STRING substr(unsigned int start, unsigned int count) const;

  /*7. ��������� ������� ������*/
  void resize(unsigned int newSize);

  /*8. �������� � ������ this ������� � ��������� [start, count)
       �� ��� ������� �� ������ �_str*/
  STRING replace(unsigned int start, unsigned int count,
    const char* const c_str) const;

  /*9. ������� ������ ������, ������ ������ �� �������� � ��������
        ������������������ �������� str, ������� � ������� start*/
  unsigned int findFirstOf(const STRING str, unsigned int start) const;

  /*10. ������� ��������� ������, ������ ������ �� �������� � ��������
        ������������������ �������� str, ������� � ������� start*/
  unsigned int findLastOf(const STRING str, unsigned int start) const;

  /*11. ������� ������ ���������, ������ str, ������� � ������� start*/
  unsigned int find(const STRING str, unsigned int start) const;

  /*12. ������� ��������� ���������, ������ str, ������� � ������� start*/
  unsigned int rfind(const STRING str, unsigned int start) const;

};


//IV. ����� "������"
//- ������������ �� ��������� �������������� � ������� �������� ����������
class VECTOR
{
private:

  /*��������� �� ������ ������� �������*/
  float* begin;

  /*��������� �� ��������� ������� �������*/
  float* end;

public:
  /*����������� �� ���������*/
  VECTOR();

  /*����������� �����������*/
  VECTOR(const VECTOR&);

  /*����������*/
  ~VECTOR();

  /*�������� �������� �������� �������
  (��� �������� ������ �� �������)*/
  float at(unsigned int index);

  /*�������� �������� �������� �������*/
  bool set(unsigned int index, float value);

  /*�������� � ������ �������*/
  bool insert(unsigned int index, float value);

  /*������� ������� �������*/
  bool remove(unsigned int index);

  /*������ �������*/
  friend void print();


  /*1. ������������� ������ ��������� �������*/
  VECTOR(unsigned int size);

  /*2. ������������� ��������� value ��������� �������*/
  VECTOR(unsigned int size, float value);

  /*3. ���������� true, ���� ������ ������*/
  bool isEmpty() const;

  /*4. ���������� ������� ������ �������*/
  unsigned int size() const;

  /*5. ������� ������*/
  void clear();

  /*6. ������� �������� ������� � ��������� [first, last)*/
  bool erase(unsigned int first, unsigned int last);

  /*7. �������� ������� �� �������� value � ����� �������*/
  void push_back(float value);

  /*8. ������� ��������� ������� �������*/
  void pop_ba�k();

  /*9. ��������� ������� �������*/
  void resize(unsigned int newSize);

  /*10. ���������� ��������� ������� � ����������� �� ������� order*/
  VECTOR sort(bool order) const;

  /*11. ���������� ����� �������*/
  float Norm() const;

  /*12. ��������� ������������ ��������*/
  float Mult(const VECTOR other) const;

};