#pragma once 

#define MAX 10

typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList, *pSeqList;


//��ʼ��˳���
void InitSeqList(pSeqList ps);

//���
//β�塢ͷ��
void PushBack(pSeqList ps, DataType d);
void PushFront(pSeqList ps, DataType d);

//ɾ��
//βɾ��ͷɾ
void PopFront(pSeqList ps);
void PopBack(pSeqList ps);

//��ӡ
void PrintSeqList(pSeqList ps);

//����
int  Find(pSeqList ps, DataType d);

//ָ��λ�ò���
void Insert(pSeqList ps, int pos, DataType d);

//ɾ��ָ��λ��Ԫ��
void Erase(pSeqList ps, int pos);

//ɾ��ָ��Ԫ��
void Remove(pSeqList ps, DataType d);

//ɾ�����е�ָ��Ԫ��
void RemoveAll(pSeqList ps, DataType d);

//���˳���
void Empty(pSeqList ps);

//����˳���Ĵ�С
int Size(pSeqList ps);

//ð������
void BubbleSort(pSeqList ps);

//���ֲ���
int BinarySearch(pSeqList ps, DataType d);

//���ֲ��ҵĵݹ�д��
int BinarySearch_R(pSeqList ps,int left,int right,DataType d);

//ѡ������
void SelectSort(pSeqList ps);






