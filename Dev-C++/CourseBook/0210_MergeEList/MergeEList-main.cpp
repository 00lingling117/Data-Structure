#include <stdio.h>
#include <string.h>         // �ṩ strstr ԭ��
#include <stdarg.h>         // �ṩ��va_list��va_start��va_arg��va_end
#include "MergeEList.h"     //**��02 ���Ա�**//

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
 *
 *����ע��
 *
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ�����Ҫ��д�ɱ������
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ�ڿɱ��������д�ļ�����Ϣ(�ļ�������Ҫ�����Ӵ�"TestData")��
 */
void CreateList_Tail(ELinkList* L, ...) {
    int i, n;
    ElemType e;
    va_list ap;
    FILE* fp;
    char* path = NULL;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    va_start(ap, L);
    path = va_arg(ap, char*);
    va_end(ap);

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strstr(path, "TestData") == NULL;

    if(readFromConsole) {
        // ��ȡָ��������Ԫ�ص�����
        printf("������Ԫ��������");
        scanf("%d", &n);

        InitList(L);

        printf("������ %d ��Ԫ�أ�", n);
        for(i = 1; i <= n; i++) {
            scanf("%d", &e);
            ListInsert(L, i, e);
        }
    } else {
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
}


int main(int argc, char** argv) {
    ELinkList La, Lb, Lc;

    printf("����La��Lb�Դ�����...\n");

    CreateList_Tail(&La, "TestData_La.txt");
    printf("La= ");
    ListTraverse(La, PrintElem);

    CreateList_Tail(&Lb, "TestData_Lb.txt");
    printf("Lb= ");
    ListTraverse(Lb, PrintElem);

    MergeEList(&La, &Lb, &Lc, Cmp);
    printf("�ϲ�La��LbΪ Lc = ");
    ListTraverse(Lc, PrintElem);

    return 0;
}

