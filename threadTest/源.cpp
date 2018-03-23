#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <time.h>
#pragma comment (lib,"Ws2_32.lib")

using namespace std;

int flag = 0;
int time = 0;

DWORD WINAPI ThreadProc(
	__in LPVOID lpParameter
)
{
	clock_t start = clock();
	clock_t end;
	int flag_last = 0;
	while (1)
	{
		if (flag != flag_last)
		{
			if (flag)
			{
				cout << "Timer Start!\n" << endl;
				start = clock();
			}
			else
			{
				cout << "Timer Stop!\n" << endl;
				end = clock();
				cout << "Running Time : " << end - start << "ms" << endl;
			}
			flag_last = flag;
		}
		//Sleep(1);
	}
}

int main()
{
	DWORD thread;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &thread);
	if (hThread == NULL)
	{
		printf("Thread Creat Failed!\n");
	}
	else
	{
		printf("Thread Creat Successful!\n");
	}

	while (1)
	{
		char c[50];
		cin >> c;

		if (c[0] == '0')
		{
			flag = 1;
		}
		else if (c[0] == '1')
		{
			flag = 0;
		}
		else
			break;
	}
	


	return 0;
}