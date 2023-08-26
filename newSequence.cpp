//
//  newSequence.cpp
//

#include "newSequence.h"
#include <iostream>

Sequence::Sequence()
  : m_size(0), m_MAX(DEFAULT_MAX_ITEMS) {
      m_array = new ItemType[DEFAULT_MAX_ITEMS];
}

Sequence::Sequence(int size) {
    if (size < 0) {
        std::cout << "Invalid size parameter" << std::endl;
        m_size = 0;
        m_MAX = 0;
        m_array = new ItemType[1];  // make an array just so the destructor can delete it after
    } else {
          m_size = 0;
          m_MAX = size;
          m_array = new ItemType[size];
      }
}

Sequence::Sequence(const Sequence& other) {
    if (this == &other)
        return;
    
    m_array = new ItemType[other.m_MAX];
    m_size = other.m_size;
    m_MAX = other.m_MAX;
    for (int i = 0; i < other.m_size; i++)
        m_array[i] = other.m_array[i];
}

Sequence::~Sequence() {
     if (m_array != nullptr)
        delete [] m_array;
}

Sequence& Sequence::operator= (const Sequence &rhs) {
    if (this == &rhs)
        return *this;
        
    delete [] m_array;
    m_array = new ItemType[rhs.m_MAX];
    m_size = rhs.m_size;
    m_MAX = rhs.m_MAX;
    for (int i = 0; i < rhs.m_size; i++)
        m_array[i] = rhs.m_array[i];
    return *this;
}

bool Sequence::empty() const {
    if (m_size == 0)
        return true;
    
    return false;
}

int Sequence::size() const { return m_size; }

int Sequence::insert(int pos, const ItemType& value) {
    if (m_size >= m_MAX  ||  pos < 0  ||  pos > m_size)
        return -1;
    
    if (pos < m_size)
        for (int i = m_size; i > pos; i--)
            m_array[i] = m_array[i - 1];    // shift everything after pos 1 to the right
        
    m_array[pos] = value;
    m_size++;
    return pos;
}

int Sequence::insert(const ItemType& value) {
    int p = m_size;
    if (p >= m_MAX)
        return -1;
    
    if (p == 0)
        m_array[p] = value;
    
    for (int i = 0; i < p; i++) {
        if (value <= m_array[i]) {
            for (int k = p; k > i; k--)
                m_array[k] = m_array[k - 1];    // shift everything after m_array[i] 1 to the right
            
            m_array[i] = value;
            p = i;
            break;
        }
        else
            m_array[p] = value;
    }
    m_size++;
    return p;
}

bool Sequence::erase(int pos) {
    if (m_size == 0  ||  pos < 0  ||  pos >= m_size)
        return false;

    for (int i = pos; i < m_size; i++) {
        if (i + 1 == m_MAX) break;
        m_array[i] = m_array[i + 1];
    }
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value) {
    int numRemove = 0;
    int firstOccurrence = find(value);
    if (firstOccurrence == -1)
        return 0;
    
    for (int k = m_size - 1; k >= firstOccurrence; k--) {
        if (m_array[k] == value) {
            erase(k);
            numRemove++;
        }
    }
    return numRemove;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (0 <= pos && pos < m_size) {
        value = m_array[pos];
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (0 <= pos && pos < m_size) {
        m_array[pos] = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const {
    for (int i = 0; i < m_size; i++)
        if (m_array[i] == value)
            return i;
    
    return -1;
}

void Sequence::swap(Sequence& other) {
    Sequence tempCopy = other;
    other = *this;
    *this = tempCopy;
}
