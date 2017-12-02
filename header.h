#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <conio.h>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
using namespace std;

struct dataTrain{
    int index;
    int like;
    int provoke;
    int comment;
    int emotion;
    int hoax;
};

struct dataTest{
    int index;
    int like;
    int provoke;
    int comment;
    int emotion;
    int hoax;
};

struct nearest{
    int index;
    double val;
};

const int k = 5; // k value
typedef dataTrain infotype;
typedef dataTest infotype2;
typedef nearest infotype3;

typedef struct elm *adr;
typedef struct elm2 *adr2;
typedef struct elm3 *adr3;

struct elm {
    infotype info;
    adr next;
    adr prev;
};

struct elm2 {
    infotype2 info;
    adr2 next;
    adr2 prev;
};

struct elm3 {
    infotype3 info;
    adr3 next;
    adr3 prev;
};

struct List {
    adr first;
    adr last;
};

struct List2 {
    adr2 first;
    adr2 last;
};

struct List3 {
    adr3 first;
    adr3 last;
};

void createList(List &L);
void createList2(List2 &L);
void createList3(List3 &L);
adr allocate(infotype x);
adr2 allocate2(infotype2 x);
adr3 allocate3(infotype3 x);
void inLa(List &L, adr P);
void inLa2(List2 &L, adr2 P);
void inFi3(List3 &L, adr3 P);
void inAf3(List3 &L, adr3 P, adr3 Q);
void inLa3(List3 &L, adr3 P);
void delLa3(List3 &L);
void clean(List &L);
void clean2(List2 &L);
void clean3(List3 &L);
void showList(List L);
void showList2(List2 L);
void showList3(List3 L);

void scanDataTrain (List &L, ifstream &file); // Fill list with data training
void scanDataTest (List2 &L, ifstream &file); // Fill list with data test
int hoaxGetter (List L, int index); // return hoax degree
int classification(int arr[]); // Classify the hoax value
void calcDistance(List x, List2 y, List3 &z, int k); // Euclidean Distance
int counterList(List3 L); // Count list size

#endif // HEADER_H_INCLUDED
