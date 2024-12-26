#include <iostream>

#include "ArrayList.hpp"
#include "HashMap.hpp"

using namespace std;

int main() {
  cout << "Test ArrayList library" << endl;

  ArrayList<int> arrayList = {1, 2, 3};
  arrayList.addFirst(10);
  arrayList.addLast(11);

  auto value = arrayList[0];
  cout << "Value: " << value << endl;

  long size = arrayList.getSize();
  cout << "Size: " << size << endl;

  arrayList.deleteAt(arrayList.getSize() - 1);

  size = arrayList.getSize();
  cout << "Size: " << size << endl;

  auto lastValue = arrayList[arrayList.getSize() - 1];
  cout << "Last value: " << lastValue;

  cout << endl << "Test HashMap library" << endl;

  HashMap<int, string> hashMap;
  hashMap.put(1, "Demis");
  hashMap.put(2, "Abebe");
  auto hashedValue = hashMap.get(2);
  cout << "Value: " << hashedValue << endl;

  auto keys = hashMap.keySet();
  cout << "{ " << endl;
  for (long i = 0; i < keys.getSize(); i++) {
    auto key = keys.get(i);
    cout << "Key: " << key << ", Value: " << hashMap.get(key) << endl;
  }
  cout << "}" << endl;

  return 0;
}