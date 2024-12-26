#include "ArrayList.hpp"
#include "ArrayListException.hpp"

template <typename T>
void ArrayList<T>::resize(long newCapcity) {
  T* newData = new T[newCapcity];
  for (long i = 0; i < size; i++) {
    newData[i] = data[i];
  }
  delete[] data;
  data = newData;
  capacity = newCapcity;
}

template <typename T>
void ArrayList<T>::swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}
template <typename T>
ArrayList<T>::ArrayList() : data{new T[1]}, capacity{1}, size{0} {}

template <typename T>
ArrayList<T>::ArrayList(const initializer_list<T> list) {
  data = new T[list.size() > 0 ? list.size() : 1];
  capacity = list.size() > 0 ? list.size() : 1;
  size = list.size();

  long index = 0;
  for (const auto dt : list) {
    data[index] = dt;
    index++;
  }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& source) {
  data = new T[source.capacity];
  capacity = source.capacity;
  size = source.size;
  for (long i = 0; i < size; i++) {
    data[i] = source.data[i];
  }
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete[] data;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
  if (this != &other) {
    T* newData = new T[other.capacity];
    for (long i = 0; i < size; i++) {
      newData[i] = other.data[i];
    }
    data = newData;
    capacity = other.capacity;
    size = other.size;
  }
  return *this;
}

template <typename T>
T& ArrayList<T>::operator[](long index) {
  if (index < 0 || index >= size) {
    throw ArrayListException{"Index out of range!"};
  }
  return data[index];
}

template <typename T>
void ArrayList<T>::addLast(const T& value) {
  if (size == capacity) {
    resize(capacity * 2);
  }
  data[size] = value;
  size++;
}

template <typename T>
void ArrayList<T>::addFirst(const T& value) {
  if (size == capacity) {
    capacity *= 2;
    T* newData = new T[capacity];
    newData[0] = value;
    for (long i = 0; i < size; i++) {
      newData[i + 1] = data[i];
    }
    delete[] data;
    data = newData;
  } else {
    for (long i = size; i > 0; i--) {
      data[i] = data[i - 1];
    }
    data[0] = value;
  }
  size++;
}

template <typename T>
T ArrayList<T>::get(long index) const {
  if (index < 0 || index >= size) {
    throw ArrayListException{"Index out of range"};
  }
  return data[index];
}

template <typename T>
void ArrayList<T>::set(long index, const T& value) {
  if (index < 0 || index >= size) {
    throw ArrayListException{"Index out of range"};
  }
  data[index] = value;
}

template <typename T>
void ArrayList<T>::insert(long index, const T& value) {
  if (index < 0 || index > size) {
    throw ArrayListException{"Index out of range"};
  }
  if (size == capacity) {
    resize(capacity * 2);
  }
  for (long i = size; i > index; i--) {
    data[i] = data[i - 1];
  }
  data[index] = value;
  size++;
}

template <typename T>
void ArrayList<T>::deleteAt(long index) {
  if (index < 0 || index >= size) {
    throw ArrayListException{"Index out of range"};
  }
  for (long i = index; i < size - 1; i++) {
    data[i] = data[i + 1];
  }
  size--;
  if (size < capacity / 4 && capacity > 1) {
    resize(capacity / 2);
  }
}

template <typename T>
long ArrayList<T>::getSize() const {
  return size;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
  return size == 0;
}

template <typename T>
void ArrayList<T>::clear() {
  size = 0;
  data = nullptr;
  resize(1);
}

template <typename T>
T* ArrayList<T>::getAllData() const {
  return data;
}

template <typename T>
void ArrayList<T>::reverse() {
  long leftIndex = 0;
  long rightIndex = size - 1;
  while (leftIndex < rightIndex) {
    swap(data[leftIndex], data[rightIndex]);
    ++leftIndex;
    --rightIndex;
  }
}
