#ifndef ARRAYLIST__HPP
#define ARRAYLIST__HPP

#include <initializer_list>

using namespace std;

template <typename T>
class ArrayList {
 private:
  T* data;
  long capacity;
  long size;
  void resize(long newCapcity);
  void swap(T& a, T& b);

 public:
  ArrayList();
  ArrayList(const initializer_list<T> list);
  ArrayList(const ArrayList& source);
  ~ArrayList();

  ArrayList& operator=(const ArrayList& other);
  T& operator[](long index);

  void addLast(const T& value);
  void addFirst(const T& value);

  T get(long index) const;
  void set(long index, const T& value);

  void insert(long index, const T& value);
  void deleteAt(long index);

  long getSize() const;
  bool isEmpty() const;
  void clear();

  T* getAllData() const;
  void reverse();

  T* begin();
  T* end();
};

#include "../src/ArrayList.inl"
#endif  // ARRAYLIST__HPP