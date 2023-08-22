#ifndef _LAB_4_5_H
#define _LAB_4_5_H

// Prototypes
void ** AllocateJagged2DArray(int elementSize, int rows, int lengths[]);
void FreeJagged2DArray(void ** arrayJagged);
int GetRowCount(void ** arrayJagged);
int GetColCount(void ** arrayJagged, int row);

#endif