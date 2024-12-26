#ifndef HASHMAP__HPP
#define HASHMAP__HPP

#include "Map.hpp"

template <typename K, typename V>
class Node {
 public:
  K key;
  V value;
  Node* next;
  Node(const K& key, const V& value);
};

// Concrete implementation of Map interface
template <typename K, typename V>
class HashMap : public Map<K, V> {
 private:
  static const int DEFAULT_CAPACITY = 16;
  static const float LOAD_FACTOR;
  int capacity;
  int size;
  ArrayList<Node<K, V>*> table;
  int hash(K key) const;
  void rehash();

 public:
  HashMap();
  ~HashMap();

  void put(const K& key, const V& value) override;
  V get(const K& key) override;
  bool contains(const K& key) override;
  void remove(const K& key) override;
  ArrayList<K> keySet() override;
};

#include "../src/HashMap.inl"

#endif
