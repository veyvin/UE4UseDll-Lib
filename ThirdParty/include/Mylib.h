#pragma once
#define DLL_EXPORT __declspec(dllexport)
#include <string>

extern "C" {

	float DLL_EXPORT ADDUE(int a, int b);
	float DLL_EXPORT ADDUE1(int a, int b);

}
