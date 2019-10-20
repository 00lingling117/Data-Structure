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
 *����ע��
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * ���ѡ���˴�Ԥ����ļ�path�ж�ȡ�������ݡ�
 * ��̲��е��㷨���õ���ͷ�巨�����Դ˴���ʵ�ּ��˺�׺_Head��
 */
Status CreateList_Head(char path[], LinkList* L, int n) {
    FILE* fp;
    int i;
    LinkList p;
    ElemType e;
    
    // ����ͷ���
    *L = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    
    // ���ļ���׼����ȡ��������
    fp = fopen(path, "r");
    if(fp == NULL) {
        return ERROR;
    }
    
    for(i = 1; i <= n; ++i) {
        // ����ɹ���ȡ����������
        if(ReadData(fp, "%d", &e) == 1) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));
            if(p == NULL) {
                fclose(fp);
                exit(OVERFLOW);
            }
            
            // ������ݣ������뵽������
            p->data = e;
            p->next = (*L)->next;
            (*L)->next = p;
        } else {
            fclose(fp);
            return ERROR;
        }
    }
    
    fclose(fp);
    
    return OK;
}

/*
 * β�巨��������
 *
 *����ע��
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * ���ѡ���˴�Ԥ����ļ�path�ж�ȡ�������ݡ�
 */
Status CreateList_Tail(char path[], LinkList* L, int n) {
    FILE* fp;
    int i;
    LinkList p, q;
    ElemType e;
    
    // ����ͷ���
    *L = (LinkList) malloc(sizeof(LNode));
    if(*L==NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    
    // ���ļ���׼����ȡ��������
    fp = fopen(path, "r");
    if(fp == NULL) {
        return ERROR;
    }
    
    for(i = 1, q = *L; i <= n; ++i) {
        // ����ɹ���ȡ����������
        if(ReadData(fp, "%d", &e) == 1) {
            p = (LinkList) malloc(sizeof(LNode));
            if(p==NULL) {
                fclose(fp);
                exit(OVERFLOW);
            }
            
            // ������ݣ������뵽������
            p->data = e;
            q->next = p;
            q = q->next;
        } else {
            fclose(fp);
            return ERROR;
        }
    }
    
    q->next = NULL;
    
    fclose(fp);
    
    return OK;
}
