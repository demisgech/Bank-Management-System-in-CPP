#include "HashMap.hpp"
#include "HashMapException.hpp"

template <typename K, typename V>
Node<K, V>::Node(const K& key, const V& value) {
  this->key = key;
  this->value = value;
  this->next = nullptr;
}

template <typename K, typename V>
const float HashMap<K, V>::LOAD_FACTOR = 0.75f;

template <typename K, typename V>
int HashMap<K, V>::hash(K key) const {
  return std::hash<K>{}(key) % capacity;
}

template <typename K, typename V>
void HashMap<K, V>::rehash() {
  capacity *= 2;
  ArrayList<Node<K, V>*> newTable;
  for (long i = 0; i < capacity; ++i) {
    newTable.addLast(nullptr);
  }
  for (long i = 0; i < table.getSize(); ++i) {
    Node<K, V>* node = table.get(i);
    while (node != nullptr) {
      Node<K, V>* next = node->next;
      int hashValue = std::hash<K>{}(node->key) % capacity;
      node->next = newTable.get(hashValue);
      newTable.set(hashValue, node);
      node = next;
    }
  }
  table = std::move(newTable);
}

template <typename K, typename V>
HashMap<K, V>::HashMap() : capacity(DEFAULT_CAPACITY), size(0) {
  for (long i = 0; i < capacity; ++i) {
    table.addLast(nullptr);
  }
}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {
  for (long i = 0; i < table.getSize(); i++) {
    Node<K, V>* node = table.get(i);
    while (node != nullptr) {
      Node<K, V>* next = node->next;
      delete node;
      node = next;
    }
  }
}

template <typename K, typename V>
void HashMap<K, V>::put(const K& key, const V& value) {
  int hashValue = hash(key);
  Node<K, V>* node = table.get(hashValue);
  while (node != nullptr) {
    if (node->key == key) {
      node->value = value;
      return;
    }
    node = node->next;
  }
  Node<K, V>* newNode = new Node<K, V>(key, value);
  newNode->next = table.get(hashValue);
  table.set(hashValue, newNode);
  size++;
  if (size > capacity * LOAD_FACTOR) {
    rehash();
  }
}

template <typename K, typename V>
V HashMap<K, V>::get(const K& key) {
  int hashValue = hash(key);
  Node<K, V>* node = table.get(hashValue);
  while (node != nullptr) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return V();
}

template <typename K, typename V>
bool HashMap<K, V>::contains(const K& key) {
  int hashValue = hash(key);
  Node<K, V>* node = table.get(hashValue);
  while (node != nullptr) {
    if (node->key == key) {
      return true;
    }
    node = node->next;
  }
  return false;
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
  int hashValue = hash(key);
  Node<K, V>* node = table.get(hashValue);
  Node<K, V>* prev = nullptr;
  while (node != nullptr) {
    if (node->key == key) {
      if (prev != nullptr) {
        prev->next = node->next;
      } else {
        table.set(hashValue, node->next);
      }
      delete node;
      size--;
      return;
    }
    prev = node;
    node = node->next;
  }
}

template <typename K, typename V>
ArrayList<K> HashMap<K, V>::keySet() {
  ArrayList<K> keys;
  for (long i = 0; i < table.getSize(); ++i) {
    Node<K, V>* node = table.get(i);
    while (node != nullptr) {
      keys.addLast(node->key);
      node = node->next;
    }
  }
  return keys;
}
