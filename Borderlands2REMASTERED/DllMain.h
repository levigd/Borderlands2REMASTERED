#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <cstdio>

class CPlayer
{
public:
	char pad_0000[108]; //0x0000
	float fHealth; //0x006C
};
