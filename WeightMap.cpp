
#include <iostream>
#include "WeightMap.h"

WeightMap::WeightMap()
{}

bool WeightMap::enroll(KeyType name, ValueType startWeight) {
    if(!m_map.contains(name) && startWeight >= 0) {
        m_map.insert(name, startWeight);
        return true;
    }
    return false;
}

ValueType WeightMap::weight(KeyType name) const {
    if(m_map.contains(name)) {
        ValueType v;
        m_map.get(name, v);
        return v;
    }
    else
        return -1;
}

bool WeightMap::adjustWeight(KeyType name, ValueType amt) {
    if(!m_map.contains(name) || ((weight(name) + amt) < 0))
        return false;
    else {
        m_map.update(name, weight(name) + amt);
        return true;
    }
}

int WeightMap::size() const {
    return m_map.size();
}

void WeightMap::print() const {
    KeyType k;
    ValueType v;
    for(int i = 0; i < size(); i++) {
        m_map.get(i, k, v);
        std::cout << k <<  " " << v << std::endl;
    }
}