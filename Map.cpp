
#include "Map.h"

Map::Map()
{}
//constructor

bool Map::empty() const {
    if(arraySize == 0)
        return true;
    return false;
}

int Map::size() const {
    return arraySize;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    if(arraySize >= 200)
        return false;
    else if(arraySize == 0) { //if array size is 0, set the first element to parameters
        m_map[0].m_key = key;
        m_map[0].m_value = value;
        arraySize++;
        return true;
    }
    else { //otherwise, set the "arraySize"th element to the parameters
        for(int i = 0; i < arraySize; i++) {
            if(m_map[i].m_key == key)
                return false; //key already in the array
        }
        m_map[arraySize].m_key = key;
        m_map[arraySize].m_value = value;
        arraySize++;
        return true;
    }
}

bool Map::update(const KeyType& key, const ValueType& value) {
    for(int i = 0; i < arraySize; i++) {
        if(m_map[i].m_key == key) {
            m_map[i].m_value = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    if(arraySize >= 200)
        return false;
    else if(arraySize == 0) { //if array size is 0, set the first element to parameters
        m_map[0].m_key = key;
        m_map[0].m_value = value;
        arraySize++;
        return true;
    }
    else { //otherwise, set the "arraySize"th element to the parameters
        for(int i = 0; i < arraySize; i++) {
            if(m_map[i].m_key == key) {
                m_map[i].m_value = value; //key already in the array, update
                return true;
            }
        }
        m_map[arraySize].m_key = key;
        m_map[arraySize].m_value = value;
        arraySize++;
        return true;
    }
}

bool Map::erase(const KeyType& key) {
    for(int i = 0; i < arraySize; i++) {
        if (m_map[i].m_key == key) {
            for(int j = i; j < arraySize; j++) {
                //move all values after the key to the left, replacing key
                m_map[j].m_key = m_map[j+1].m_key;
                m_map[j].m_value = m_map[j+1].m_value;
            }
            arraySize--;
            return true;
        }
    }
    return false;
}

bool Map::contains(const KeyType& key) const {
    for(int i = 0; i < arraySize; i++)
        if(m_map[i].m_key == key)
            return true;
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const {
    for(int i = 0; i < arraySize; i++) {
        if(m_map[i].m_key == key) {
            value = m_map[i].m_value;
            return true;
        }
    }
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    if(0 <= i < arraySize) {
        key = m_map[i].m_key;
        value = m_map[i].m_value;
        return true;
    }
    return false;
 //   if(0 <= i < arraySize) {
 //       if(getArr[i] != i) {
 //           key = m_map[i].m_key;
 //          value = m_map[i].m_value;
 //           getArr[i] = i;
 //           getArrKey[i] = m_map[i].m_key;
 //           return true;
 //       }
 //       else if(getArr[i] == i) {
 //           key = getArrKey[i];
 //           value = m_map[i].m_value;
 //           return true;
 //       }
 //       else
 //           return false;
 //   }
 //   return false;
}

void Map::swap(Map& other) {
    for(int i = 0; i < arraySize; i++) {
        KeyType k = m_map[i].m_key; //temporary variables
        ValueType v = m_map[i].m_value;
        other.m_map[i].m_key = m_map[i].m_key;
        other.m_map[i].m_value = m_map[i].m_value;
        m_map[i].m_key = k;
        m_map[i].m_value = v;
    }
}

