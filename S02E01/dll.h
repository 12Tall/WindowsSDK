#ifndef _DLL_H_
#define _DLL_H_

#if BUIDING_DLL
// ����������Ϊ��������,Ҳ����˵�������Ҫ��������������ĳ���֮��ĳ������
// ���� DLL ʱ��ͨ������һ���������ڵ����ĺ���ԭ�ͺ�/�����ͷ�ļ�
// ���������洢�� DLL �ĵ�������
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

// ��ʾ�ص��뺯������Ч����Ŀ����루��Ϊ������Thunk��
// https://blog.csdn.net/stone_kingnet/article/details/3862504
/**
 * \brief �ӷ�����
 * \param i 
 * \param j 
 * \return ��
 */
DLLIMPORT int add(int i, int j);

#endif