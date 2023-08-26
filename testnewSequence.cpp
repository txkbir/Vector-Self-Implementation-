//
//  testnewSequence.cpp
//

#include "newSequence.h"
#include <iostream>
#include <cassert>

 int main() {
    ItemType item = 1;
    Sequence s(5);

    assert (s.size() == 0);
    assert (s.size() != 4);
    assert (s.size() != 6);
    s.insert(0, 1);
    assert (s.get(0, item) && item == 1);
    s.insert(1, 150);
   // assert (s.size() == 5);
    assert (s.get(1, item) && item == 150);
    s.insert(2, 3);
    assert (s.get(2, item) && item == 3);
    s.insert(15);
   // assert (s.size() == 5);
    s.insert(4, 234);
   // assert (s.size() == 5);
    std::cerr << "1 is at position " << s.find(1) << std::endl;
    std::cerr << "3 is at position " << s.find(3) << std::endl;
    std::cerr << "15 is at position " << s.find(15) << std::endl;
    std::cerr << "150 is at position " << s.find(150) << std::endl;
    std::cerr << "234 is at position " << s.find(234) << std::endl;
    std::cerr << "=====================" << std::endl;

    assert (s.insert(7) == -1);
    assert (s.insert(2342325) == -1);
    
      s = s;

    Sequence t(3);
    t.insert(3);
    t.insert(16);
    t.insert(9);
    assert (t.size() == 3);

    Sequence st(t);
    assert (st.size() == t.size());
    ItemType itm = 3;

    assert (s.get(0, itm));
    std::cerr << itm << std::endl;
    assert (s.get(1, itm) && itm == 9);
    std::cerr << itm << std::endl;
    assert (s.get(2, itm) && itm == 16);
    std::cerr << itm << std::endl;
    assert (s.size() == 3);
    std::cerr << "size of s is " << s.size() << std::endl;

    Sequence z;
    z.insert(2394042);
    z.insert(234);
    z.insert(3);
    z.insert(1);
    assert (z.size() == 4);
    t.swap(z);

    assert (z.size() == 3);
    assert (t.size() == 4);


    ItemType item2;
    assert (z.get(0, item2));
    std::cerr << item2 << std::endl;
    assert (z.get(1, item2) && item2 == 9);
    std::cerr << item2 << std::endl;
    assert (z.get(2, item2) && item2 == 16);
    std::cerr << item2 << std::endl;
    assert (z.size() == 3);
    std::cerr << "size of z is " << z.size() << std::endl;
    assert (z.insert(3) == -1);


    Sequence seq(10);
    Sequence seq2(3);
    ItemType insert = 69;
    for (int i = 0; i < 30; i += 2)
        seq.insert(insert + i);

    for (int i = 0; i < 3; i++)
        seq2.insert(insert - (2 * i));

    assert (seq.size() == 10);
    assert (seq2.size() == 3);

    seq2 = seq;
    assert (seq2.size() == 10);
    assert (seq2.get(0, insert));

    Sequence variable;
    assert (variable.size() == 0);

    Sequence std(-1);
    
    Sequence zt;
    t.swap(zt);
    t = zt;
    
    Sequence newS(4);
    ItemType newItem[4] = {3, 7, 16, 2};
    for (int i = 0; i < 4; i++)
        newS.insert(newItem[i]);

    assert (newS.get(0, item) && item == 2);
    assert (newS.get(3, item) && item == 16);

    assert (newS.size() == 4);
    
    assert (newS.insert(item) == -1);
 }

