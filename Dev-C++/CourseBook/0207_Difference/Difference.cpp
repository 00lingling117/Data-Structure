/*===============
 * ��̬����ȥ��
 *
 * �����㷨: 2.17
 ================*/

#include "Difference.h"

/*
 * ���������������� �㷨2.17 ����������������
 *
 * S = (A-B)��(B-A)
 *
 * �Լ���A�ͼ���B����(A-B)��(B-A)���㣬���������뾲̬����S
 *
 *����ע��
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * ���ѡ���˴�Ԥ����ļ�path�ж�ȡ�������ݡ�
 */
void difference(char path[], SLinkList space, int* S) {
    FILE* fp;
    int m, n;       // ����A�ͼ���B��Ԫ������
    int j;          // ѭ��������
    int R;          // ָ��̬�������һ�����
    int i, k, p;
    int b;          // ��ʱ�洢�Ӽ���B�ж���������
    
    // ��ʼ�����ÿռ�
    InitSpace(space);
    
    // ��ȡ��̬����ͷ���
    *S = Malloc(space);
    
    // ��Rִ�о�̬�������Ľ��
    R = *S;
    
    // ���ļ���׼����ȡ��������
    fp = fopen(path, "r");
    if(fp == NULL) {
        exit(ERROR);
    }
    
    // ��ȡ����A�ͼ���B��Ԫ�ظ���
    ReadData(fp, "%d%d", &m, &n);
    
    // ¼�뼯��A������
    for(j = 1; j <= m; ++j) {
        // ������
        i = Malloc(space);
        
        // ���뼯��A��Ԫ��ֵ
        ReadData(fp, "%d", &space[i].data);
        
        // ���½����뵽��β
        space[R].cur = i;
        R = i;
    }
    
    // β����ָ���ÿ�
    space[R].cur = 0;
    
    // ¼�뼯��B������
    for(j = 1; j <= n; ++j) {
        // ���뼯��B��Ԫ��ֵ
        ReadData(fp, "%d", &b);
        
        p = *S;             // ָ��̬����ͷ��㣬��������ָ��k��ǰһ��λ��
        k = space[*S].cur;  // ָ��̬�����е��׸�Ԫ��
        
        // �ڵ�ǰ��̬�����в����Ƿ����bԪ��
        while(k != space[R].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }
        
        // �����Ԫ�ز����ڣ�����뾲̬����
        if(k == space[R].cur) {
            i = Malloc(space);
            space[i].data = b;
            space[i].cur = space[R].cur;
            space[R].cur = i;
            
            // �����Ԫ���Ѵ��ڣ�����Ҫ�Ƴ�
        } else {
            space[p].cur = space[k].cur;
            Free(space, k);
            if(R == k) {
                R = p;
            }
        }
    }
    
    fclose(fp);
}