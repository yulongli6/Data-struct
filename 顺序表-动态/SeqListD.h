#pragma once


#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef int DataType;

typedef struct SeqListD
{
	DataType* data;
	int sz;
	int capicity;
}SeqListD,*pSeqListD;




void InitSeqListD(pSeqListD ps);//

void DestroySeqListD(pSeqListD ps);//

void PushBack(pSeqListD ps, DataType d);//

void PrintSeqListD(const pSeqListD ps);//

void PopBack(pSeqListD ps);//

void PushFront(pSeqListD ps, DataType d);//

void PopFront(pSeqListD ps);//

void Insert(pSeqListD ps, int pos, DataType d);//

void Erase(pSeqListD ps, int pos);//

void Sort(pSeqListD ps);//

int BinarySearch(pSeqListD ps, DataType d);//

int Find(pSeqListD ps, DataType d);//

void Remove(pSeqListD ps, DataType d);//

void RemoveAll(pSeqListD ps, DataType d);//


