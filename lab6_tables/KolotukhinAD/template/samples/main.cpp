#include "OrderedTable.h"
#include "BinSTree.h"
#include "UnorderedTable.h"
#include "string"
#include "AVL-Tree.h"
#include "Hash-Table.h"

using namespace std;

int main()
{ 

    // HashTable<int, string> H;
    // H.Insert(8, "eight");
    // H.Insert(0, "zero");
    // H.Insert(1, "one");
    // H.Insert(33, "thirty three");
    // H.Insert(12, "twelve");
    // H.Insert(25, "twenty five");
    // H.Delete(0);
    // H.Print();
    // cout << endl << H[0];
   
    Polynomial p("10*x^2 + 7*y^3 - 222*z^890");
    cout << p;
    // BinSTree<int, string> tree;
    // AVLTree<int, string> tree;
    // tree.Insert(9, "9");
    // tree.Insert(6, "6");
    // tree.Insert(11, "11");
    // tree.Insert(4, "4");
    // tree.Insert(8, "8");
    // tree.Insert(10, "10");
    // tree.Insert(12, "12");
    // tree.Insert(2, "2");
    // tree.Insert(5, "5");
    // tree.Insert(7, "7");
    // tree.Insert(13, "13");
    // tree.Insert(1, "1");
    // tree.Insert(3, "3");
    // tree.ShiftPrint();
/*                       9
               6         |    11
          4    |    8       10 | 12
       2  | 5     7 |-      -|-  -|13
      1|3  -|-   -|-               -|-

table: 
[9]: 9
 .. [6]: 6
 ..  .. [4]: 4
 ..  ..  .. [2]: 2
 ..  ..  ..  .. [1]: 1
 ..  ..  ..  .. [3]: 3
 ..  ..  .. [5]: 5
 ..  .. [8]: 8
 ..  ..  .. [7]: 7
 .. [11]: 11
 ..  .. [10]: 10
 ..  .. [12]: 12
 ..  ..  .. [13]: 13
   */
    //______________Unordered Table [std::vector]_________________________________________
    
    // UnorderedTable<int, string> T;
    // UnorderedTableList<int, string> T;
    // UnorderedTablemay<int, string> T;
    // OrderedTable<int, string> T;
    //OrdTablemay<int, string> T;
    /*T.Insert(3, "  3 line");
    T.Insert(2, "  2 line");//
    T.Insert(1, "  1 line");
    T.Insert(11, " 6 line");//
    T.Insert(6, "  4 line");
    T.Insert(17, " 8 line");//
    T.Insert(0, "  0 line");
    T.Insert(12, " 7 line");
    T.Insert(333, "9 line");
    T.Insert(7, "  5 line");//
    
    T.Print();
    cout << endl;
    T.Delete(2);
    T.Delete(11);
    T.Delete(7);
    T.Delete(17);
    T.Print();
    cout << endl;
    cout << *(T.Find(333)) << endl;
    cout << T[3] << endl;*/
    //____________________________________________________________________________________


    //__________Unordered/Ordered Table Of Polynomials[may, List, Vector]_______________
    
    // PolynomialUTable<int> T;
    // PolynomialUTablemay<int> T;
    // PolynomialUTableList<int> T;
    // PolynomialOrdTable<int> T;
    // PolynomialOrdTablemay<int> T;
    
    // UnorderedTable<int, Polynomial> T;
    // UnorderedTableList<int, Polynomial> T;
    // UnorderedTablemay<int, Polynomial> T;

    /*
    Monom m1[] = { Monom(1,'x',1), Monom(1,'y',1), Monom(1,'z',1) };
    Polynomial p1(m1, sizeof(m1) / sizeof(Monom));
    T.Insert(1, p1);

    Monom m2[] = { Monom(-1,'x',2), Monom(2,'y',2), Monom(-10,'z',2) };
    Polynomial p2(m2, sizeof(m2) / sizeof(Monom));
    T.Insert(3, p2);
    
    Monom m3[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p3(m3, sizeof(m3) / sizeof(Monom));
    T.Insert(2, p3);

    Monom m4[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p4(m4, sizeof(m4) / sizeof(Monom));
    T.Insert(11, p4);

    Monom m5[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p5(m5, sizeof(m5) / sizeof(Monom));
    T.Insert(15, p5);

    Monom m6[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p6(m6, sizeof(m6) / sizeof(Monom));
    T.Insert(12, p6);

    Monom m7[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p7(m7, sizeof(m7) / sizeof(Monom));
    T.Insert(8, p7);
    Point p(1,1,1);
    // T.Calculate(p);

    T.Print();

    T.Delete(11);
    T.Delete(1);
    T.Delete(15);
    cout << endl;
    T.Print();
    cout << endl;
    cout << *(T.Find(3)) << endl;
    cout << endl;
    // cout << "cap = " << T.GetCapacity() << "; size = " << T.GetSize();*/
    //_____________________________________________________________________________________

    return 0;
}