#pragma once
#include <Windows.h>

class MyMemory
{
public:

	DWORD ProcessID = 0;
	HANDLE TheProcess = 0;

	void OpenTheProcess(LPCSTR ClassName, LPCSTR WindowName, DWORD ID)
	{
		if (ID == NULL)
		{
			HWND MyWindow = FindWindowA(ClassName, WindowName);
			GetWindowThreadProcessId(MyWindow, &ProcessID);
		}
		else
		{
			ProcessID = ID;
		}

		TheProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
	}

	int ReadInt(int Address)
	{
		LPVOID TempReadInt = 0;
		ReadProcessMemory(TheProcess, (LPCVOID)Address, &TempReadInt, sizeof(4), 0);
		return(int)TempReadInt;
	}

	int Read2Byte(int Address)
	{
		LPVOID TempRead2Byte = 0;
		ReadProcessMemory(TheProcess, (LPCVOID)Address, &TempRead2Byte, sizeof(2), 0);
		return(int)TempRead2Byte;
	}

	int ReadByte(int Address)
	{
		LPVOID TempReadByte = 0;
		ReadProcessMemory(TheProcess, (LPCVOID)Address, &TempReadByte, sizeof(1), 0);
		return(int)TempReadByte;
	}


	void WriteInt(int Address, int Value)
	{
		LPVOID TempWriteInt = (LPVOID)Value;
		WriteProcessMemory(TheProcess, (LPVOID)Address, &TempWriteInt, sizeof(4), 0);
		TempWriteInt = NULL;
	}

	void Write2Byte(int Address, int Value)
	{
		LPVOID TempWrite2Byte = (LPVOID)Value;
		WriteProcessMemory(TheProcess, (LPVOID)Address, &TempWrite2Byte, sizeof(2), 0);
		TempWrite2Byte = NULL;
	}

	void WriteByte(int Address, int Value)
	{
		LPVOID TempWriteByte = (LPVOID)Value;
		WriteProcessMemory(TheProcess, (LPVOID)Address, &TempWriteByte, sizeof(1), 0);
		TempWriteByte = NULL;
	}

	/*
	void WriteBytes(int Address, int ArrayOfBytes[], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			WriteByte(Address+i, ArrayOfBytes[i]);
		}
	}
	*/
};