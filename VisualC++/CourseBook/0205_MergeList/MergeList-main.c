#include <stdio.h>
#include "MergeList.h"                    //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkList La, Lb, Lc;
    
    int m = 5;
    
    printf("��Ϊʾ����La�����趨Ϊ %d ��Lb�����趨Ϊ %d ������La��Lb...\n", m, m);
    
    CreateList_Head("TestData_Head.txt", &La, m);
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail("TestData_Tail.txt", &Lb, m);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    printf("�鲢La��LbΪLc = ");
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

