/*===============
 * ��̬����ȥ��
 *
 * �����㷨: 2.17
 ================*/

#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <stdio.h>
#include "Status.h"           //**��01 ����**//
#include "SLinkList.h"        //**��02 ���Ա�**//

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
void difference(char path[], SLinkList space, int* S);

#endif
