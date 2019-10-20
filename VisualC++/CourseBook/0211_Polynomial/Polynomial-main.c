#include "Polynomial.h"         //**��02 ���Ա�**//

int main(int argc, char **argv) {
    Polynomial Pa, Pb;
    int m, n;
    
    m = 5;
    n = 6;
    
    printf("���������������� CreatPolyn \n");
    {
        printf("�� ��Ϊʾ������������Ϊ %d �Ķ���ʽPa...\n", m);
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        
        printf("�� ��Ϊʾ������������Ϊ %d �Ķ���ʽPb...\n", n);
        CreatPolyn("TestData_Pb.txt", &Pb, n);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PrintPolyn \n");
    {
        printf("�� һԪ����ʽ Pa = ");
        PrintPolyn(Pa);
        
        printf("�� һԪ����ʽ Pb = ");
        PrintPolyn(Pb);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PolynLength \n");
    {
        printf("�� La ������Ϊ %d ��Lb ������Ϊ %d\n", PolynLength(Pa), PolynLength(Pb));
    }
    PressEnterToContinue();

    
    printf("���������������� AddPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);
        
        AddPolyn(&Pa, &Pb);
        
        printf("�� Pa = Pa + Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    
    printf("���������������� SubtractPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);

        SubtractPolyn(&Pa, &Pb);

        printf("�� Pa = Pa - Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();

    
    printf("���������������� MultiplyPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);

        MultiplyPolyn(&Pa, &Pb);

        printf("�� Pa = Pa * Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    return 0;
}

