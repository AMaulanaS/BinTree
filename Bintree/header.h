#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL

typedef int infotype;
typedef struct Node *address;
typedef struct Node {
    infotype Info;
    address Left;
    address Right;
}Node;

typedef address BinTree;

typedef struct ElmtNode *addresList;
typedef struct ElmtNode {
    infotype Info;
    addresList Next;
}ElmtNode;

typedef addresList ListOfNode;

#define Info(P) (P)->Info
#define Left(P) (P)->Left
#define Right(P) (P)->Right

#define InfoList(P) (P)->Info
#define NextList(P) (P)->Next

BinTree Alokasi(infotype X);
void Dealokasi(BinTree *P);

/* ***Selektor*** */
infotype GetAkar(BinTree P);
BinTree GetLeft(BinTree P);
BinTree GetRight(BinTree P);

/* ***Konstruktor*** */
BinTree Tree(infotype Akar, BinTree L, BinTree R);
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P);
void BuildTree(BinTree *P);

/* ***Predikat-Predikat penting*** */
boolean IsTreeEmpty(BinTree P);
boolean IsOneElmt(BinTree P);
boolean IsUnerLeft(BinTree P);
boolean IsUnerRight(BinTree P);
boolean IsBiner(BinTree P);

/* ***Traversal*** */
void PrintPreOrder(BinTree P);
void PrintInOrder(BinTree P);
void PrintPostOrder(BinTree P);
void PrintTree(BinTree P, int h);

/* ***Searching*** */
boolean Search(BinTree P, infotype X);

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P);
int NbDaun(BinTree P);
boolean IsSkewLeft(BinTree P);
boolean IsSkewRight(BinTree P);
int maks(int a,int b);
int Tinggi1(BinTree P);
int Tinggi (BinTree R);
int Level(BinTree P, infotype X);

/* *** Operasi Lain *** */
void AddDaunTerkiri(BinTree *P, infotype X);
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri);
void DelDaunTerkiri(BinTree *P, infotype *X);
void DelDaun(BinTree *P, infotype X);
ListOfNode MakeListDaun(BinTree P);
addresList AlokListNode(infotype X);
void DealokListNode(addresList *P);
ListOfNode MakeListPreOrder(BinTree P);
ListOfNode MakeListLevel(BinTree P, int N);
ListOfNode Concat1(ListOfNode L1, ListOfNode L2);
void PrintInfo(ListOfNode L);

/* *** Balanced Tree *** */
BinTree BuildBalanceTree(int n);

/* *** Binary Search Tree *** */
boolean BSearch(BinTree P, infotype X);
BinTree InsSearch(BinTree P, infotype X);
void DelBTree(BinTree *P, infotype X);


#endif // HEADER_H_INCLUDED
