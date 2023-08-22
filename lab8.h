
/*
In this lab, you will cover creating and maintaining a Priority Queue ADT. You are only given a partial definition of the PQ implementation, and you must derive the remainder of the implementation from the given complexity requirements. Note that you may need to define extra helper functions or struct types to complete this lab, and that these extra definitions must go in your \textbf{lab8.c} file.

In this lab you are given the following struct definitions:

// This is a partial definition, you must complete it in your lab8.c file
typedef struct Info Info;

typedef struct {
    Info *info;
} PQueue;
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Info Info;

typedef struct {
    Info *info;
} PQueue;

//-1
// O(1)
int pqGetErrorCode(PQueue q);

//-2
// O(1)
PQueue pqInit();

//-3
// O(n)
int pqInsert(void *data, int priority, PQueue q);

//-4
// O(1)
void * pqRemoveMax(PQueue q);

//-5
// O(1)
void * pqPeek(PQueue q);

//-6
// O(1)
int pqGetSize(PQueue q);

//-7
// O(n)
void pqFree(PQueue q);
