#pragma once 

#define MAX 10

typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList, *pSeqList;


//初始化顺序表
void InitSeqList(pSeqList ps);

//添加
//尾插、头插
void PushBack(pSeqList ps, DataType d);
void PushFront(pSeqList ps, DataType d);

//删除
//尾删、头删
void PopFront(pSeqList ps);
void PopBack(pSeqList ps);

//打印
void PrintSeqList(pSeqList ps);

//查找
int  Find(pSeqList ps, DataType d);

//指定位置插入
void Insert(pSeqList ps, int pos, DataType d);

//删除指定位置元素
void Erase(pSeqList ps, int pos);

//删除指定元素
void Remove(pSeqList ps, DataType d);

//删除所有的指定元素
void RemoveAll(pSeqList ps, DataType d);

//清空顺序表
void Empty(pSeqList ps);

//返回顺序表的大小
int Size(pSeqList ps);

//冒泡排序
void BubbleSort(pSeqList ps);

//二分查找
int BinarySearch(pSeqList ps, DataType d);

//二分查找的递归写法
int BinarySearch_R(pSeqList ps,int left,int right,DataType d);

//选择排序
void SelectSort(pSeqList ps);






