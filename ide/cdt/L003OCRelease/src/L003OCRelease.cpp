//============================================================================
// Name        : L003OCRelease.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Object.h"

using namespace std;

int main() {

	Object* obj = new Object();
	obj->release();


	return 0;
}
