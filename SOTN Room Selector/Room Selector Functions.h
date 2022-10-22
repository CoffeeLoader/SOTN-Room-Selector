#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>
#include "MyMemory.h"
MyMemory m;

using std::cout;
using std::cin;

void ClearScreenAndIntro()
{
	system("cls");
	cout << " ////////////////////////////////////////////////////////////////////////////////////////////////////////////////// " << "\n"
		 << " //      ////     ////     ////  ///  //////      ////     //// ////////     /////   ////     ////     ////      // " << "\n"
		 << " // //// //// /// //// /// //// / / / ////// ///////// //////// //////// //////// /// ///// ////// /// //// //// // " << "\n"
		 << " // //   //// /// //// /// //// /   / //////      ////    ///// ////////    ///// ///////// ////// /// //// //   // " << "\n"
		 << " // /// ///// /// //// /// //// // // /////////// //// //////// //////// //////// /// ///// ////// /// //// /// /// " << "\n"
		 << " // //// ////     ////     //// ///// //////      ////     ////     ////     /////   ////// //////     //// //// // " << "\n"
		 << " ////////////////////////////////////////////////////////////////////////////////////////////////////////////////// " << "\n"
		 << "\n";
}

//
//
//

int Value = 0;
int AddressA = 0x00A8F5D4;
int AddressB = 0x00AEA7B8;
int AddressC = 0x00AEA340;

void ScanProcess()
{
	ClearScreenAndIntro();
	if (Value == 0)
	{
		m.OpenTheProcess("EPSX", NULL, NULL);
	}

	if (m.ProcessID != 0)
	{
		cout << "The emulator was found. \n";
		return;
	}
	else
	{
		cout << "Emulator not found. \n";
	}

	cout << "Want to search again? Yes or No: ";
	std::string Temp; cin >> Temp;

	if (Temp == "Yes" || Temp == "yes")
	{
		ScanProcess();
	}

}

//
//
//

void RoomSelector()
{
	if (m.ProcessID == 0)
	{
		return;
	}

	cout << "\n" << "Select Room: ";
	int Room;

	cin >> Room;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
	}

	if (Room == -1)
	{
		ClearScreenAndIntro();
		m.OpenTheProcess("EPSX", NULL, NULL);
		RoomSelector();
	}
	else
	{
		m.Write2Byte(AddressA, 4);
		m.Write2Byte(AddressB, Room);
		m.Write2Byte(AddressC, Room);
		RoomSelector();
	}

}