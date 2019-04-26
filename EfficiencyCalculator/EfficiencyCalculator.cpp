// EfficiencyCalculator.cpp
//

#include "pch.h"
#include <time.h>
#include <stdlib.h>
#include <windows.h>  
#include <iostream>
#ifndef __MyTimer_H__  
#define __MyTimer_H__  
#define random(a,b) ((rand() % (b-a+1))+ a
class accurateTimer
{
private:
	int _freq;
	LARGE_INTEGER _begin;
	LARGE_INTEGER _end;
public:
	long costTime;
public:
	accurateTimer()
	{
		LARGE_INTEGER tmp;
		QueryPerformanceFrequency(&tmp);//QueryPerformanceFrequency()作用：返回硬件支持的高精度计数器的频率。  

		_freq = tmp.QuadPart;
		costTime = 0;
	}

	void Start()            // 开始计时  
	{
		QueryPerformanceCounter(&_begin);//获得初始值  
	}

	void End()                // 结束计时  
	{
		QueryPerformanceCounter(&_end);//获得终止值  
		costTime = (long)((_end.QuadPart - _begin.QuadPart) * 1000000 / _freq);
	}

	void Reset()            // 计时清0  
	{
		costTime = 0;
	}
	//Refer:https://blog.csdn.net/AP1005834/article/details/53419647
};
#endif  
int main()
{
	/*
	Goal:
		Analysis the time 100000 sentences executed.
		Now included:
			a+b
				(0~100)
				(10,000~100,000)
				(10,000,000~100,000,000)
			a*b
				(0~100)
				(10,000~100,000)
				(10,000,000~100,000,000)
			a^b
				(0~100)
				(10,000~100,000)
			a^b.0
		random settings:
		integer random between a,b
			(rand() % (b - a + 1)) + a;
	*/
	accurateTimer timer;
	unsigned int t = 0;
	srand((unsigned)time(NULL));
	/*
	a+b:
	test for 25 times
		1)create random values
		2)trying to calc
	*/
	const int test_time = 25;
	long long int_1[10000];
	long long c = 0;
	long long DeviationTime = 0;
	float float_1[100000];

	long long sum_time = 0;
	long float average_time = 0;
#pragma region operator+ 0,100
	std::cout << "Current operation : operator+ 0,100-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(0, 100));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a + b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}

	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region operator+ 10,000 ~ 100,000
	/*
	a+b:
	test for 25 times
		1)create random values
		2)trying to calc
*/
	std::cout << "Current operation : operator+ 10,000 ~ 100,000-----------" << std::endl;
	//int int_1[10000];
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(10000, 100000));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a + b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region operator+ 10,000,000 ~ 100,000,000
	/*
	a+b:
	test for 25 times
		1)create random values
		2)trying to calc
*/
	std::cout << "Current operation : operator+ 10,000,000 ~ 100,000,000-----------" << std::endl;
	//int int_1[10000];
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(10000000, 100000000));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a + b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");

#pragma endregion

#pragma region operator* 0,100
	std::cout << "Current operation : operator* 0,100-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(0, 100));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a * b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region operator* 10,000 ~ 100,000
	std::cout << "Current operation : operator* 10,000 ~ 100,000-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(10000, 100000));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a * b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region operator* 10,000,000 ~ 100,000,000
	std::cout << "Current operation : operator* 10,000,000 ~ 100,000,000-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(10000000, 100000000));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = a * b;
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion

#pragma region function Integer power (0,100) ^ %
	std::cout << "Current operation : ipow(0,100) ^ %-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(0, 100));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = pow(a, b);
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region function Integer power (10,000 ~ 100,000) ^ %
	std::cout << "Current operation : ipow(10,000 ~ 100,000) ^ %-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			int_1[i] = random(10000, 100000));
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = pow(a, b);
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion

#pragma region function Real power (0,100) ^ %
	std::cout << "Current operation : rpow(0,100) ^ %-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			float_1[i] = (float)(rand() / (float)RAND_MAX) * 100;
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = pow(a, b);
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion
#pragma region function Real power (10,000 ~ 100,000) ^ %
	std::cout << "Current operation : rpow(10,000 ~ 100,000) ^ %-----------" << std::endl;
	c = 0;
	DeviationTime = 0;
	sum_time = 0;
	average_time = 0;
	for (int x = 0; x < test_time; x++)
	{
		for (int i = 0; i < 10000; i++)
		{
			float_1[i] = (float)(rand() / (float)RAND_MAX) * 100 + 10000;
		}
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = 0;
		}
		timer.End();
		DeviationTime = timer.costTime;
		timer.Start();
		for (int i = 0; i < 10000; i++)
		{
			int a = int_1[rand() % 10000];
			int b = int_1[rand() % 10000];
			c = pow(a, b);
		}
		timer.End();
		if (timer.costTime - DeviationTime < 0)
		{
			x--;
		}
		else
		{
			sum_time = sum_time + timer.costTime - DeviationTime;
		}
	}
	average_time = (float)sum_time / (float)test_time; std::cout << "Average time : \t" << average_time << "\t μs" << std::endl; system("pause");
#pragma endregion

	return 0;
}
