/*========================
 * һԪ����ʽ(������������)
 *
 * �����㷨: 2.22��2.23
 =========================*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>         // �ṩmalloc��realloc��free��exitԭ��
#include <string.h>         // �ṩ strstr ԭ��
#include <stdarg.h>         // �ṩ��va_list��va_start��va_arg��va_end
#include "ELinkList.h"      //**��02 ���Ա�**//

/* һԪ����ʽ���Ͷ��� */
typedef ELinkList Polynomial;


/*�������������������������������������������� һԪ����ʽ���� ��������������������������������������������*/

/*
 * ���������������� �㷨2.22 ����������������
 *
 * ����
 *
 * ���������ϵ����ָ������������Ϊm��һԪ����ʽ
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
void CreatPolyn(Polynomial* P, int m, ...);

/*
 * ����
 *
 * ����һԪ����ʽ��
 */
void DestroyPolyn(Polynomial *P);

/*
 * ����
 *
 * ����һԪ����ʽ��������
 */
int PolynLength(Polynomial P);

/*
 * ���������������� �㷨2.23 ����������������
 *
 * �ӷ�
 *
 * һԪ����ʽ�ӷ�Pa=Pa+Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void AddPolyn(Polynomial *Pa, Polynomial *Pb);

/*
 * ����
 *
 * һԪ����ʽ����Pa=Pa-Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void SubtractPolyn(Polynomial *Pa, Polynomial *Pb);

/*
 * �˷�
 *
 * һԪ����ʽ�˷�Pa=Pa*Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void MultiplyPolyn(Polynomial *Pa, Polynomial *Pb);


/*�������������������������������������������� �������� ��������������������������������������������*/

/*
 * ���
 *
 * ��ӡ���һԪ����ʽ��
 */
void PrintPolyn(Polynomial P);

/*
 * �Ƚ�
 *
 * �Ƚ�c1���c2��ָ����С��
 */
int Cmp(ElemType c1, ElemType c2);

#endif
