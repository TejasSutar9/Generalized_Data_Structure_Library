#include "../include/gdsl.h"

int main()
{
    SinglyLLL<int> sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.InsertAtPos(75,4);

    sobj.Display();

    return 0;
}

//   | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL

//   | 11 | -> | 21 | -> | 51 | -> | 75 | -> | 101 | -> | 111 | -> NULL
