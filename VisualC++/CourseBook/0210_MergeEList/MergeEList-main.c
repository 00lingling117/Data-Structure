#include <stdio.h>
#include "MergeEList.h"                    //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}

/*
 * �Ƚ�
 *
 * �Ƚ�e1��e2�Ĵ�С������ֵ�������£�
 *  < 0��e1 < e2
 *  = 0��e1 = e2
 *  > 0��e1 > e2
 */
int Cmp(ElemType e1, ElemType e2) {
    return e1 - e2;
}

/*
 * β�巨��������
 *
 *����ע��
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * ���ѡ���˴�Ԥ����ļ�fp�ж�ȡ�������ݡ�
 */
void CreateList_Tail(char path[], ELinkList* L) {
    FILE* fp;
    int i, n;
    ElemType e;
    
    fp = fopen(path, "r");
    if(fp == NULL) {
        printf("�ļ���ʧ��...\n");
        exit(ERROR);
    }
    
    // ��ȡָ��������Ԫ�ص�����
    ReadData(fp, "%d", &n);
    
    InitList(L);
    
    for(i = 1; i <= n; i++) {
        ReadData(fp, "%d", &e);
        ListInsert(L, i, e);
    }
    
    fclose(fp);
}


int main(int argc, char** argv) {
    ELinkList La, Lb, Lc;
    
    printf("����La��Lb�Դ�����...\n");
    
    CreateList_Tail("TestData_La.txt", &La);
    printf("La= ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail("TestData_Lb.txt", &Lb);
    printf("Lb= ");
    ListTraverse(Lb, PrintElem);
    
    MergeEList(&La, &Lb, &Lc, Cmp);
    printf("�ϲ�La��LbΪ Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}
