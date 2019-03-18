#ifndef _DLL_H_
#define _DLL_H_

#if BUIDING_DLL
// 将函数定义为导出函数,也就是说这个函数要被包含这个函数的程序之外的程序调用
// 生成 DLL 时，通常创建一个包含正在导出的函数原型和/或类的头文件
// 将函数名存储在 DLL 的导出表中
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

// 显示地导入函数能有效减少目标代码（因为不产生Thunk）
// https://blog.csdn.net/stone_kingnet/article/details/3862504
/**
 * \brief 加法计算
 * \param i 
 * \param j 
 * \return 和
 */
DLLIMPORT int add(int i, int j);

#endif