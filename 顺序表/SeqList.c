#define _CRT_SECURE_NO_DEPRECATE 1
#include "SeqList.h"
#include "stdio.h"
#include "assert.h"
#include "string.h"


//��ʼ��
void InitSeqList(pSeqList ps)
{
	assert(ps);
	ps->sz = 0;

}


//��ӡ
void PrintSeqList(pSeqList ps)
{
	assert(ps);

	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}

	printf("\n");
}


//��
//β��
void PushBack(pSeqList ps, DataType d)
{
	assert(ps);

	//˳�������
	if (ps->sz == MAX)
	{
		printf("˳�������\n");
		return;
	}

	//˳���û��
	ps->data[ps->sz] = d;
	ps->sz++;

}


//ͷ��
void PushFront(pSeqList ps, DataType d)
{
	assert(ps);

	//˳�������
	if (ps->sz == MAX)
	{
		printf("˳�������\n");
		return;
	}

	//˳���û��
	for (int i = ps->sz-1; i >= 0;i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	
	ps->data[0] = d;
	ps->sz++;
}


//ָ��λ�ò���
void Insert(pSeqList ps, int pos, DataType d)
{
	assert(ps);
	assert(ps->sz < MAX);
	assert(pos >= 0 && pos <= ps->sz);

	for (int i = ps->sz - 1; i >= pos;i--)
	{
		ps->data[i + 1] = ps->data[i];
	}

	ps->data[pos] = d;
	ps->sz++;
}

//ɾ
//βɾ
void PopBack(pSeqList ps)
{
	assert(ps);
	assert(ps->sz > 0);

	ps->sz--;
}


//ͷɾ
void PopFront(pSeqList ps)
{
	assert(ps);
	assert(ps->sz > 0);

	for (int i = 0; i < ps->sz-1;i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}


//ɾ��ָ��λ��Ԫ��
void Erase(pSeqList ps, int pos)
{
	assert(ps);
	assert(ps->sz > 0);
	assert(pos >= 0 && pos < ps->sz);

	for (int i = pos; i < ps->sz - 1;i++)
	{
		ps->data[i] = ps->data[i + 1];
	}

	ps->sz--;
}


//��
int  Find(pSeqList ps, DataType d)
{
	assert(ps);

	for (int i = 0; i < ps->sz;i++)
	{
		if (ps->data[i]==d)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ָ��Ԫ��
void Remove(pSeqList ps, DataType d)
{
	assert(ps);

	int pos = Find(ps, d);
	if (pos == -1)
	{
		return;
	}
	Erase(ps, pos);
}


//ɾ�����е�ָ��Ԫ��
void RemoveAll(pSeqList ps, DataType d)
{
	
	assert(ps);
#if 0

	//���������飬�Ѳ�����d������copy��extra
	DataType *extra = (DataType *)malloc(sizeof(DataType)*ps->sz);
	int i = 0; int j = 0;
	for (int i = 0; i < ps->sz;i++)
	{
		if (ps->data[i]!=d)
		{
			extra[j++] = ps->data[i];
		}
	}
	//��extra������copy����
	for (int k = 0; k < j;k++)
	{
		ps->data[k] = extra[k];
	}
	ps->sz = j;
	free(extra);
#endif
	int i = 0; int j = 0;
	for (; i < ps->sz;i++)
	{
		if (ps->data[i]!=d)
		{
			ps->data[j++] = ps->data[i];
		}
	}
	ps->sz = j;
}


//���˳���
void Empty(pSeqList ps)
{
	assert(ps);
	ps->sz = 0;
}


//����˳���Ĵ�С
int Size(pSeqList ps)
{
	assert(ps);
	return ps->sz;
}


void Swap(DataType * x, DataType* y)
{
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}


//ð������
void BubbleSort(pSeqList ps)
{
	int i, j;
	int  flag = 1;
	for (i = 0; i < ps->sz - 1; i++) 
	{
		flag = 1;	// ��������
		for (j = 0; j < ps->sz - 1 - i; j++) 
		{
			if (ps->data[j] > ps->data[j + 1]) 
			{
				Swap(ps->data+j, ps->data+j + 1);
				flag = 0;
			}
		}

		// һ��ð�ݹ����У�һ�ν�����û�У������Ѿ�������
		if (1==flag) 
		{
			break;
		}
	}
}


//���ֲ���
int BinarySearch(pSeqList ps, DataType d)
{
	assert(ps);
	int left = 0;
	int right = ps->sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left)/2;
		if (d<ps->data[mid])
		{
			right = mid - 1;
		}
		else if (d>ps->data[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


//���ֲ��ҵĵݹ�д��
int BinarySearch_R(pSeqList ps, int left, int right, DataType d)
{
	int mid = left + (right - left) / 2;
	if (left>right)
	{
		return -1;
	}
	if (ps->data[mid]==d)
	{
		return mid;
	}
	else if (d<ps->data[mid])
	{
		return BinarySearch_R(ps, left, mid - 1, d);
	}
	else
	{
		return BinarySearch_R(ps, mid+1, right, d);
	}
}


//ѡ������
void SelectSort(pSeqList ps)
{
	int minSpace = 0;
	int maxSpace = ps->sz - 1;
	while (minSpace<maxSpace)
	{
		int minPos = minSpace;
		int maxPos = minSpace;
		for (int i = minSpace; i <= maxSpace;i++)
		{
			if (ps->data[i]<ps->data[minPos])
			{
				minPos = i;
			}
			if (ps->data[i]>ps->data[maxPos])
			{
				maxPos = i;
			}
		}
		Swap(ps->data+minPos, ps->data+minSpace);
		if (maxPos==minSpace)
		{
			maxPos = minPos;
		}
		Swap(ps->data+maxPos, ps->data+maxSpace);
		minSpace++;
		maxSpace--;
	}
}
