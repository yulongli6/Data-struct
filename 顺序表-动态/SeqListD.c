#define _CRT_SECURE_NO_DEPRECATE 1

#include "SeqListD.h"

void InitSeqListD(pSeqListD ps)
{
	assert(ps);
	ps->data= (DataType*)calloc(5, sizeof(DataType));
	ps->sz = 0;
	ps->capicity = 3;
}


void DestroySeqListD(pSeqListD ps)
{
	assert(ps);
	free(ps->data);
	ps->capicity = 0;
	ps->sz = 0;
}


void ExpandCapicity(pSeqListD ps)
{
	assert(ps != NULL);
	if (ps->sz<ps->capicity)
	{
		return;
	}
	else
	{
		DataType* tmp = NULL;
		tmp = (DataType*)realloc(ps->data, (ps->capicity + 5)*sizeof(DataType));
		if (tmp == NULL)
		{
			return;//����ʧ��
		}
		else
		{
			ps->data = tmp;
			ps->capicity += 5;
		}
	}
	
}



void PushBack(pSeqListD ps, DataType d)
{
	assert(ps!=NULL);

	ExpandCapicity(ps);
	ps->data[ps->sz++] = d;
}


void PrintSeqListD(pSeqListD ps)
{
	assert(ps);
	for (int i = 0; i < ps->sz;i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}


void PushFront(pSeqListD ps, DataType d)
{
	assert(ps);
	
	ExpandCapicity(ps);
	
	for (int i = ps->sz-1; i >= 0;i--)
	{
		ps->data[i+1]  = ps->data[i];
	}
	ps->data[0] = d;
	ps->sz++;
}


void Insert(pSeqListD ps, int pos, DataType d)
{
	assert(ps);

	ExpandCapicity(ps);

	for (int i = ps->sz - 1; i >= pos;i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	ps->data[pos] = d;
	ps->sz++;
}


void PopBack(pSeqListD ps)
{
	assert(ps);
	assert(ps->sz > 0);

	ps->sz--;
}


void PopFront(pSeqListD ps)
{
	assert(ps);
	assert(ps->sz > 0);

	for (int i = 0; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}


void Erase(pSeqListD ps, int pos)
{
	assert(ps);
	assert(ps->sz > 0);
	assert(pos >= 0 && pos < ps->sz);

	for (int i = pos; i < ps->sz - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}

	ps->sz--;
}



void Swap(DataType * x, DataType* y)
{
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void Sort(pSeqListD ps)
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
				Swap(ps->data + j, ps->data + j + 1);
				flag = 0;
			}
		}

		// һ��ð�ݹ����У�һ�ν�����û�У������Ѿ�������
		if (1 == flag)
		{
			break;
		}
	}
}


int BinarySearch(pSeqListD ps, DataType d)
{
	assert(ps);
	int left = 0;
	int right = ps->sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
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


int Find(pSeqListD ps, DataType d)
{
	assert(ps);

	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}


void Remove(pSeqListD ps, DataType d)
{
	assert(ps);

	int pos = Find(ps, d);
	if (pos == -1)
	{
		return;
	}
	Erase(ps, pos);
}


void RemoveAll(pSeqListD ps, DataType d)
{
	assert(ps);
#if 0

	//���������飬�Ѳ�����d������copy��extra
	DataType *extra = (DataType *)malloc(sizeof(DataType)*ps->sz);
	int i = 0; int j = 0;
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] != d)
		{
			extra[j++] = ps->data[i];
		}
	}
	//��extra������copy����
	for (int k = 0; k < j; k++)
	{
		ps->data[k] = extra[k];
	}
	ps->sz = j;
	free(extra);
#endif
	int i = 0; int j = 0;
	for (; i < ps->sz; i++)
	{
		if (ps->data[i] != d)
		{
			ps->data[j++] = ps->data[i];
		}
	}
	ps->sz = j;

}


