#include <stdio.h>
#include "Difference.h"                    //**��02 ���Ա�**//

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SLinkList space;    // ���ÿռ�
    int S;              // ��̬����
    
    printf("S = (A-B)��(B-A) = ");
    difference("TestData.txt", space, &S);
    ListTraverse(space, S, PrintElem);
    
    return 0;
}
