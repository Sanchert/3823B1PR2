#include "OrderedTable.h"
#include "BinSTree.h"
#include "UnorderedTable.h"
#include "string"

using namespace std;

int main()
{
    /*
    BinSTree<int, string> tree;
    tree.Insert(4, "top lv1");
    tree.Insert(2, "L lv2");
    tree.Insert(6, "R lv2");    
    tree.Insert(1, "LL lv3");
    tree.Insert(3, "LR lv3");
    tree.Insert(5, "RL lv3");
    tree.Insert(7, "RR lv3");
    tree.Delete(6);
    tree.Print();
    */

    /*    4
        2 | 6
       1|3|5|7
    */
    //______________Unordered Table [std::vector]_________________________________________
    /*
    Unorderedtable<int, string> T;
    T.Insert(1, "first line");
    T.Insert(2, "second line");
    T.Insert(3, "third line");

    T.Print();
    T.Delete(2);
    T.Print();
    cout << endl;
    cout << *(T.Find(3)) << endl;
    */
    //____________________________________________________________________________________

    //______________Unordered Table [List]________________________________________________
    /*
    UnorderedTableList<int, string> T;
    T.Insert(3, "3 line");
    T.Insert(2, "2 line");
    T.Insert(1, "1 line");
    
    T.Insert(11, "6 line");
    T.Insert(6, "4 line");
    T.Insert(17, "8 line");
    T.Insert(0, "0 line");
    T.Insert(12, "7 line");
    T.Insert(333, "9 line");
    T.Insert(7, "5 line");

    T.Delete(7);
    cout << T.GetSize() << endl;
    T.Print();
    T.Delete(2);
    T.Print();
    cout << endl;
    cout << *(T.Find(3)) << endl;
    */
    //____________________________________________________________________________________

    //______________Unordered Table [Array]_______________________________________________
    /*
    UnorderedTableArray<int, string> T;
    T.Insert(1, "first line");
    T.Insert(2, "second line");
    T.Insert(3, "third line");
    T.Print();
    cout << "size = " << T.GetSize() << "; capacity =  " << T.GetCapacity() << endl;
    cout << "T[0] = " << T[0] << endl;
    cout << "T.2 = " << *T.Find(2) << endl;

    T.Delete(2);
    T.Insert(100, "output");
    T.Print();
    return 0;
    */
    //____________________________________________________________________________________


    //__________Unordered/Ordered Table Of Polynomials[Array, List, Vector]_______________
    
    // PolynomialUTable<int> T;
    // PolynomialUTableArray<int> T;
    // PolynomialUTableList<int> T;
    PolynomialOrdTable<int> T;
    Monom m1[] = { Monom(1,'x',2), Monom(3,'y',4), Monom(5,'z',6) };
    Polynomial p1(m1, sizeof(m1) / sizeof(Monom));
    T.Insert(2, p1);

    Monom m2[] = { Monom(-1,'x',2), Monom(2,'y',2), Monom(-10,'z',2) };
    Polynomial p2(m2, sizeof(m2) / sizeof(Monom));
    T.Insert(1, p2);
    
    Monom m3[] = { Monom(-13,'x',1), Monom(-2,'y',3), Monom(7,'z',5) };
    Polynomial p3(m3, sizeof(m3) / sizeof(Monom));
    T.Insert(3, p3);

    Point p(1,1,1);
    T.Calculate(p);

    T.Print();

    T.Delete(2);
    cout << endl;
    T.Print();
    cout << endl;
    cout << *(T.Find(3)) << endl;
    //_____________________________________________________________________________________


}