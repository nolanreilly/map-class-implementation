#include <iostream>
#include <cassert>
using namespace std;
#include "newMap.h"

int main() {
    Map b(5);
    KeyType k[6] = {"marco", "polo", "rodriguez", "antonio", "raul", "victorino"};
    ValueType v  = 35;
    for (int n = 0; n < 5; n++)
        assert(b.insert(k[n], v));
    //assert(!b.insert(k[5], v));
    Map test;
    test.insert("hi", 2.975);
   // test.print();
    cout << endl;
    test.insert("yo", 2.876);
    //test.print();
    cout << endl;
    test.insertOrUpdate("hi", 3.45);
    //test.print();
    cout << endl;
    test.insertOrUpdate("hey", 3.45);
   // test.print();
    cout << endl;
    test.update("hey", 1.95);
   // test.print();
    cout << endl;
    test.erase("hi");
   // test.print();
    cout << endl;
    double d = 1.552;
    test.get("hey", d);
    cout << d;
    cout << "=======" << endl;
    Map other;
    other.insert("ciao", 5.45);
    other.insert("goodbye", 2.12);
  //  test.print();
    cout << endl;
  //  other.print();
    cout << endl;
    swap(test, other);
  //  test.print();
    cout << endl;
  //  other.print();
    cout << endl;
}
