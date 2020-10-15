//
// Created by 张承元 on 2020/10/9.
//

#ifndef LINEARLIST_SEQUENCE__SQLIST_H
#define LINEARLIST_SEQUENCE__SQLIST_H

#endif //LINEARLIST_SEQUENCE__SQLIST_H


/* Linear Table On Sequence Structure */
/* Realized by zcy */
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define EXCEPTION -3

typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT  10
typedef struct {  //顺序表（顺序结构）的定义
    ElemType *elem = nullptr;
    int length = 0;
    int listsize = 0;
} SqList;

/*--------Declaration of SqList functions---------*/
status InitList(SqList &L);

status DestroyList(SqList &L);

status ClearList(SqList &L);

status ListEmpty(SqList L);

int ListLength(SqList L);

status GetElem(SqList L, int i, ElemType &e);

status LocateElem(SqList L, ElemType e);

status PriorElem(SqList L, ElemType cur, ElemType &pre_e);

status NextElem(SqList L, ElemType cur, ElemType &next_e);

status ListInsert(SqList &L, int i, ElemType e);

status ListDelete(SqList &L, int i, ElemType &e);

status ListTraverse(SqList L);

status ListQSort(SqList L);

status SaveList(SqList L, char FileName[]);

status LoadList(SqList &L, char FileName[]);

int ListBiSearch(SqList &L, ElemType e);

/*--------------------------------------------*/

void qSort(ElemType *v, int right, int left);

int partition(ElemType *v, int right, int left);

status ListQSort(SqList L);

int biSearch(ElemType v[], int low, int high, ElemType e);

status checkIncrease(const ElemType v[], int n);


/*---------Definition of SqList functions---------*/

status InitList(SqList &L) {
    if (L.elem != nullptr)return INFEASIBLE;
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) return OVERFLOW;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status ListTraverse(SqList L) {
    if (L.elem == nullptr)return INFEASIBLE;
    for (int i = 0; i < L.length; ++i) {
        printf("%d", L.elem[i]);
        if (i != L.length - 1)printf(" ");
    }
    printf("\n");
    return OK;
}

status DestroyList(SqList &L) {
    if (L.elem == nullptr)return INFEASIBLE;
    free(L.elem);
    L.elem = nullptr;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

status ClearList(SqList &L) {
    DestroyList(L);
    InitList(L);
}

status ListEmpty(SqList L) {
    if (L.elem == nullptr)return INFEASIBLE;
    if (L.length == 0)return TRUE;
    return FALSE;
}

int ListLength(SqList L) {
    if (L.elem == nullptr)return INFEASIBLE;
    return L.length;
}

status GetElem(SqList L, int i, ElemType &e) {
    if (L.elem == nullptr)return INFEASIBLE;
    if (i <= 0 || i > L.length)return ERROR;
    e = L.elem[i - 1];
    return OK;
}

status LocateElem(SqList L, ElemType e) {
    if (L.elem == nullptr)return INFEASIBLE;
    int i = 0;
    while (i < L.length && L.elem[i] != e) {
        i++;
    }
    if (i < L.length)return i + 1;//若结果合法，返回位序i
    else return ERROR;//返回-1，表示线性表中不存在满足条件的元素
}

status PriorElem(SqList L, ElemType cur, ElemType &pre_e) {
    if (L.elem == nullptr)return INFEASIBLE;
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == cur && i != 0) {
            pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

status NextElem(SqList L, ElemType cur, ElemType &next_e) {
    if (L.elem == nullptr)return INFEASIBLE;
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == cur && i != L.length - 1) {
            next_e = L.elem[i + 1];
            return OK;
        }
    }
    return ERROR;
}

status ListInsert(SqList &L, int i, ElemType e) {
    if (L.elem == nullptr)return INFEASIBLE;
    if (i < 1 || i > L.length + 1)return ERROR;
    if (L.length >= L.listsize) {
        L.elem = (ElemType *) realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!L.elem)return OVERFLOW;
        else {
            L.listsize += LIST_INCREMENT;
        }
    }
    for (int j = L.length - 1; j >= i - 1; --j) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

status ListDelete(SqList &L, int i, ElemType &e) {
    if (L.elem == nullptr)return INFEASIBLE;//线性表未初始化
    if (i < 1 || i > L.length)return ERROR;//删除位置不合法
    //将i位序后的元素依次前移
    e = L.elem[i - 1];
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;//删除成功
}

status SaveList(SqList L, char *FileName) {
    if (L.elem == nullptr)return INFEASIBLE;
    FILE *out = fopen(FileName, "w");
    for (int i = 0; i < L.length - 1; ++i) {
        fprintf(out, "%d ", L.elem[i]);
    }
    fprintf(out, "%d", L.elem[L.length - 1]);
    fclose(out);
    return OK;
}

status LoadList(SqList &L, char *FileName) {
    if (L.elem != nullptr)return INFEASIBLE;
    FILE *in = fopen(FileName, "r");
    L.length = L.listsize = 0;
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    ElemType e;
    while (fscanf(in, "%d", &e) != EOF) {
        L.elem[L.length++] = e;
        if (L.length >= L.listsize) {
            L.elem = (ElemType *) realloc(L.elem, (LIST_INCREMENT + L.listsize) * sizeof(ElemType));
            L.listsize += LIST_INCREMENT;
        }
    }
    fclose(in);
    return OK;
}

/*--------------------------------------------*/


status ListQSort(SqList L) {
    if (L.elem == nullptr)return INFEASIBLE;
    if (ListEmpty(L))return ERROR;
    qSort(L.elem, 0, L.length - 1);
    return OK;
}

int partition(ElemType *v, int right, int left) {
    int ref = v[right];
    while (right < left) {
        while (right < left && v[left] >= ref) {
            left--;
        }
        v[right] = v[left];
        while (right < left && v[right] <= ref) {
            right++;
        }
        v[left] = v[right];
    }
    v[right] = ref;
    return right;
}

void qSort(ElemType *v, int right, int left) {
    if (right < left) {
        int mid = partition(v, right, left);
        qSort(v, right, mid - 1);
        qSort(v, mid + 1, left);
    }
}

int ListBiSearch(SqList &L, ElemType e) {
    //前提：线性表已然递增排列
    //若e存在，返回其逻辑位序；否则返回-1
    if (L.elem != nullptr && checkIncrease(L.elem, L.length)){
        return biSearch(L.elem,0,L.length-1,e);
    }else{
        return EXCEPTION;//标志其他情况：不满足条件
    }
}

int biSearch(ElemType *v, int low, int high, ElemType e) {
    //若e存在，返回其逻辑位序；否则返回-1
    //[low,high]
    //v已然以递增顺序排列
    if (low > high)return -1;
    //low<=high
    int mid = low + (high - low) / 2;
    if (v[mid] == e)return mid;
    if (v[mid] > e)return biSearch(v, low, mid - 1, e);
    if (v[mid] < e)return biSearch(v, mid + 1, high, e);

    return EXCEPTION;//catch error 意外的情况
}

status checkIncrease(const ElemType *v, int n) {
    //用于判断序列v是否递增，是返回1，不是返回0
    for (int i = 1; i < n; ++i) {
        if (v[i - 1] > v[i])return FALSE;
    }
    return TRUE;
}


