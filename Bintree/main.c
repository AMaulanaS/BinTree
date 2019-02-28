#include "header.h"

int main()
{
    BinTree T = Nil;
   // BinTree T2 = Nil;

    printf("***Pohon Biner***\n\n");
    T=Tree(10,Nil,Nil);
    InsertNode(&T,45);
    InsertNode(&T,15);
    InsertNode(&T,59);
    InsertNode(&T,50);
    InsertNode(&T,57);
    InsertNode(&T,75);
    printf("\nTree T:\n\n");
    printf("PrintPreOrder : ");PrintPreOrder(T);
    printf("\nPrintInOrder : ");PrintInOrder(T);
    printf("\nPrintPostOrder : ");PrintPostOrder(T);

    printf("\n\nAkar pohon biner T: %d\n", GetAkar(T));
    printf("T merupakan pohon biner? %d\n", IsBiner(T));
    printf("T condong ke kiri? %d\n", IsSkewLeft(T));
    printf("T condong ke kanan? %d\n", IsSkewRight(T));
    printf("T satu elemen? %d\n", IsOneElmt(T));
    printf("T hanya punyai subpohon kiri? %d\n", IsUnerLeft(T));
    printf("T hanya punyai subpohon kanan? %d\n", IsUnerRight(T));

    printf("\n\nJumlah elemen %d\n", NbElmt(T));
    printf("Jumlah daun : %d\n", NbDaun(T));
    AddDaunTerkiri(&T,4);
    printf("\nSetelah ditambahkan daun Terkiri 4");
    printf("\nPohon InOrder: ");PrintInOrder(T);
    printf("\nPohon PreOrder: ");PrintPreOrder(T);
    //DelDaunTerkiri(&T,&X);
    printf("\nPohon PreOrder: ");PrintPreOrder(T);
    //printf("\nPrintTree:");
    printf("\n");
    //PrintTree(T,2);
    return 0;
}
