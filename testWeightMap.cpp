
#include <iostream>
using namespace std;
#include "WeightMap.h"

int main() {
    WeightMap test;
    test.enroll("marco", 105);
    cout << test.weight("marco");
    test.adjustWeight("marco", -100);
    cout << endl;
    cout << test.weight("marco");
    cout << endl;
    cout << test.size();
    cout << endl;
    test.enroll("jonathan", 210);
    test.adjustWeight("jonathan", 5);
    //test.print();
}
