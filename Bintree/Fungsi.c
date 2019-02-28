#include "header.h"

BinTree Alokasi(infotype X) {
    BinTree P;

    P = (BinTree)malloc(sizeof(Node));
    if(P!=Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

void Dealokasi(BinTree *P) {
    free(*P);
}

infotype GetAkar(BinTree P) {
    return (Info(P));
}

BinTree GetLeft(BinTree P) {
    return (Left(P));
}

BinTree GetRight(BinTree P) {
    return Right(P);
}

BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    BinTree P;

    P = Alokasi(Akar);
    if(P!=Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Alokasi(Akar);
    if((*P)!=Nil) {
        Info(*P) = Akar;
        Left(*P) = L;
        Right(*P) = R;
    }
}

void InsertNode(BinTree *T,infotype X){
// 1. If the tree is empty, return a new, single node
    BinTree P=*T;
    if (IsTreeEmpty(P)) {
        (*T)=Alokasi(X);
    }
    else {
    // 2. Otherwise, recur down the tree
        if (X <= Info(P))
            InsertNode(&(P->Left), X);
        else
            InsertNode(&(P->Right), X);
    }
}

boolean IsTreeEmpty(BinTree P) {
    return (P==Nil);
}

boolean IsOneElmt(BinTree P) {
    return (!(IsTreeEmpty(P)) && (Left(P)==Nil && Right(P)==Nil));
}

boolean IsUnerLeft(BinTree P) {
    return (Right(P)==Nil && Left(P)!=Nil);
}

boolean IsUnerRight(BinTree P) {
    return (Right(P)!=Nil && Left(P)==Nil);
}

boolean IsBiner(BinTree P) {
    return (Right(P)!=Nil && Left(P)!=Nil);
}

void PrintPreOrder(BinTree P) {
    if(IsTreeEmpty(P))
        return;
    else {
        printf("%d ", Info(P));
        PrintPreOrder(Left(P));
        PrintPreOrder(Right(P));
    }
}

void PrintInOrder(BinTree P) {
    if(IsTreeEmpty(P))
        return;
    else {
        PrintInOrder(Left(P));
        printf("%d ", Info(P));
        PrintInOrder(Right(P));
    }
}

void PrintPostOrder(BinTree P) {
    if(IsTreeEmpty(P))
        return;
    else {
        PrintPostOrder(Left(P));
        PrintPostOrder(Right(P));
        printf("%d ", Info(P));
    }
}

void PrintTree(BinTree P, int h) {
    int i;

    if(IsTreeEmpty(P)) {
        return;
    } else {
        printf("%d", Info(P));
        printf("\n");
        if(!IsTreeEmpty(Left(P))) {
            for(i=0;i<h;i++) {
                printf(" ");
                return (PrintTree(Left(P),h+1));
            }
        }
        if(!IsTreeEmpty(Right(P))) {
            for(i=0;i<h;i++) {
                printf(" ");
                return (PrintTree(Right(P),h+1));
            }
        }
    }
}

boolean Search(BinTree P, infotype X) {
    if(IsTreeEmpty(P))
        return false;
    else {
        if(Info(P)==X)
            return true;
        else
            return (Search(Left(P),X)) || Search(Right(P),X);
    }
}

int NbElmt(BinTree P) {
    if(IsTreeEmpty(P))
        return 0;
    else
        return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
}

int NbDaun(BinTree P) {
    if(IsOneElmt(P))
        return 1;
    else {
        if(IsUnerLeft(P))
            return (NbDaun(Left(P)));
        else if(IsUnerRight(P))
            return (NbDaun((Right(P))));
        else
            return (NbDaun(Left(P)) + NbDaun(Right(P)));
    }
}

boolean IsSkewLeft(BinTree P) {
    if(IsTreeEmpty(P))
        return true;
    else {
        if(!(IsTreeEmpty(Right(P))))
            return false;
        else
            return (IsSkewLeft(Left(P)));
    }
}

boolean IsSkewRight(BinTree P) {
    if(IsTreeEmpty(P))
        return true;
    else {
        if(!(IsTreeEmpty(Left(P))))
            return false;
        else
            return (IsSkewRight(Right(P)));
    }
}
/* fungsi max*/
int maks(int a,int b)
{
    return (a>=b)?a:b;
}

int Tinggi1(BinTree P) //taddress root
{
   if (P==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = Tinggi1(Left(P));//root->left);
     int rheight = Tinggi1(Right(P));//root->right);

     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}

int Tinggi (BinTree R)
/* Pohon Biner mungkin kosong. Mengirim depth yaitu tinggi dari pohon */
/* Basis: Pohon kosong: tingginya nol */
/* Rekurens: 1 + maksimum (Tinggi(AnakKiri), Tinggi(AnakKanan)) */
{
    if (R == Nil) /* Basis 0 */
        return 0;
    else /* Rekurens */{
        return (1 + maks(Tinggi(Left(R)),Tinggi(Right(R))));
    }
}

int Level(BinTree P, infotype X) {
    if(IsOneElmt(P))
        return 1;
    else if(Info(P)==X)
        return 1;
    else {
        if(IsUnerLeft(P))
            return (1 + Level(Left(P),X));
        else if(IsUnerRight(P))
            return (1 + Level(Right(P),X));
        else {
            if(Search(Left(P),X)==1)
                return (1 + Level(Left(P),X));
            else
                return (1 + Level(Right(P),X));
        }
    }
}

void AddDaunTerkiri(BinTree *P, infotype X) {
    address N;

    if(IsTreeEmpty(*P)) {
        N = Alokasi(X);
        if(N!=Nil) {
            *P = N;
        }
    } else {
        return (AddDaunTerkiri(&(Left(*P)),X));
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
    address N;

    if(IsOneElmt(*P)) {
        if(Info(*P)==X) {
            N = Alokasi(Y);
            if(N!=Nil) {
                if(Kiri==true) {
                    Left(*P) = N;
                } else {
                    Right(*P) = N;
                }
            }
        }
    } else {
        if(IsUnerLeft(*P)) {
            return (AddDaun(&(Left(*P)),X,Y,Kiri));
        } else if(IsUnerRight(*P)) {
            return (AddDaun(&(Right(*P)),X,Y,Kiri));
        } else {
            return (AddDaun(&(Left(*P)),X,Y,Kiri));
            return (AddDaun(&(Right(*P)),X,Y,Kiri));
        }
    }
}

void DelDaunTerkiri(BinTree *P, infotype *X) {
    if(IsTreeEmpty(*P)) {
        return;
    }

    if(IsOneElmt(*P)) {
        *X = Info(*P);
        Dealokasi(&(*P));
        *P = Nil;
    } else {
        DelDaunTerkiri(&(Left(*P)),X);
    }
}

void DelDaun(BinTree *P, infotype X) {
    infotype *Y;

    if(IsTreeEmpty(*P)) {
        return;
    } else if(IsOneElmt(*P)) {
        if(Info(*P)==X) {
            *P = Nil;
        } else {
            return;
        }
    } else {
        DelDaun(&(Left(*P)),X);
        DelDaun(&(Right(*P)),X);
    }
}

addresList AlokListNode(infotype X) {
    addresList P;

    P = (addresList)malloc(sizeof(ListOfNode));
    if(P!=Nil) {
        InfoList(P) = X;
        NextList(P) = Nil;
    }
    return P;
}

void DealokListNode(addresList *P) {
    free(*P);
}

ListOfNode MakeListDaun(BinTree P) {
    addresList E;
    ListOfNode L;

    if(IsTreeEmpty(P))
        return Nil;
    else {
        if(IsOneElmt(P)) {
            E = AlokListNode(Info(P));
            if(E!=Nil) {
                return E;
            } else {
                return Nil;
            }
        } else {
            if(IsUnerLeft(P))
                return MakeListDaun(Left(P));
            else if(IsUnerRight(P))
                return MakeListDaun(Right(P));
            else {
                return Concat1(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
            }
        }
    }
}

ListOfNode MakeListPreOrder(BinTree P) {
    addresList E;
    ListOfNode L;

    if(IsTreeEmpty(P))
        return Nil;
    else {
        E = AlokListNode(Info(P));
        if(E!=Nil) {
            NextList(E) = MakeListPreOrder(Left(P));
            L = MakeListPreOrder(Right(P));
            return Concat1(E,L);
        } else {
            return Nil;
        }
    }
}

ListOfNode MakeListLevel(BinTree P, int N) {
    addresList E;
    ListOfNode L;

    if(IsTreeEmpty(P))
        return Nil;
    else {
        if(Level(P,Info(P))==N) {
            E = AlokListNode(Info(P));
            if(E!=Nil) {
                return E;
            } else {
                return Nil;
            }
        } else {
            if(IsUnerLeft(P))
                return MakeListLevel(Left(P),N-1);
            else if(IsUnerRight(P))
                return MakeListLevel(Right(P),N-1);
            else {
                return Concat1(MakeListLevel(Left(P),N-1),MakeListLevel(Right(P),N-1));
            }
        }
    }
}

ListOfNode Concat1(ListOfNode L1, ListOfNode L2) {
    addresList Last;

    if(L1!=Nil) {
        Last = L1;
        while(NextList(Last)!=Nil) {
            Last = NextList(Last);
        }
        NextList(Last) = L2;
        return L1;
    } else {
        return L2;
    }
}

void PrintInfo(ListOfNode L) {
    addresList P;

    P = (L);
    if(P==Nil) {
        printf("ListOfNode kosong\n");
    } else {
        while(P!=Nil) {
            printf("|%d| ", InfoList(P));
            P = NextList(P);
        }
    }
}

BinTree BuildBalanceTree(int n) {
    address P;
    BinTree L, R;
    infotype X;
    int nL, nR;

    if(n==0)
        return Nil;
    else {
        printf("Masukkan X: ");scanf("%d",&X);
        P = Alokasi(X);
        if(P!=Nil) {
            nL = n/2;
            nR = n - nL - 1;
            L = BuildBalanceTree(nL);
            R = BuildBalanceTree(nR);
            Left(P) = L;
            Right(P) = R;
        }
    }
    return P;
}
