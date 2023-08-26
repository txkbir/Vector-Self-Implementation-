//
//  newSequence.h
//

#ifndef NEW_SEQUENCE_H
#define NEW_SEQUENCE_H

#include <string>
const int DEFAULT_MAX_ITEMS = 160;
using ItemType = unsigned long;

class Sequence {
public:
    Sequence();
    Sequence(int size);
    Sequence(const Sequence& other);
    ~Sequence();
    Sequence& operator= (const Sequence& rhs);
    bool empty() const;
    int  size() const;
    int  insert(int pos, const ItemType& value);
    int  insert(const ItemType& value);
    bool erase(int pos);
    int  remove(const ItemType& value);  // return numItems removed
    bool get(int pos, ItemType& value) const;   // in a way, this accessor function returns 2 vars (a bool retvalue and a modified 'value')
    bool set(int pos, const ItemType& value);
    int  find(const ItemType& value) const;
    void swap(Sequence& other);
    
private:
    ItemType* m_array;
    int m_size;
    int m_MAX;
};

#endif
