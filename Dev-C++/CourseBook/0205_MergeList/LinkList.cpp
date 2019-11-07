/*===============================
 * ���Ա����ʽ�洢�ṹ������
 *
 * �����㷨: 2.8��2.9��2.10��2.11
 ================================*/

#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    
    // ȷ���������
    if(L == NULL || L->next == NULL) {
        return;
    }
    
    p = L->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}

/*
 * ���������������� �㷨2.11 ����������������
 *
 * ͷ�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ�����Ҫ��д�ɱ������
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ�ڿɱ��������д�ļ�����Ϣ(�ļ�������Ҫ�����Ӵ�"TestData")��
 */
Status CreateList_Head(LinkList* L, int n, ...) {
    int i;
    LinkList p;
    va_list ap;
    FILE* fp;
    char* path = NULL;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    va_start(ap, n);
    path = va_arg(ap, char*);
    va_end(ap);

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strstr(path, "TestData") == NULL;

    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        printf("������%d������Ԫ�أ�", n);

        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            scanf("%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }

        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }

        fclose(fp);
    }

    return OK;
}

/*
 * β�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ�����Ҫ��д�ɱ������
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ�ڿɱ��������д�ļ�����Ϣ(�ļ�������Ҫ�����Ӵ�"TestData")��
 */
Status CreateList_Tail(LinkList* L, int n, ...) {
    int i;
    LinkList p, q;
    va_list ap;
    FILE* fp;
    char* path = NULL;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    va_start(ap, n);
    path = va_arg(ap, char*);
    va_end(ap);

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strstr(path, "TestData") == NULL;

    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        printf("������%d������Ԫ�أ�", n);

        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            scanf("%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }

        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;

        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));

            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));

            q->next = p;
            q = q->next;
        }

        q->next = NULL;

        fclose(fp);
    }

    return OK;
}

