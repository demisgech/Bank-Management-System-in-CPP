#ifndef MAP__HPP
#define MAP__HPP

#include "ArrayList.hpp"

// Map interface
template <typename K, typename V>
class Map {
 public:
  virtual void put(const K &key, const V &value) = 0;
  virtual V get(const K &key) = 0;
  virtual bool contains(const K &key) = 0;
  virtual void remove(const K &key) = 0;
  virtual ArrayList<K> keySet() = 0;

  virtual ~Map() = default;
};
#endif
