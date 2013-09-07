//============================================================================
// Name        : L002HelloCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "People.h"
#include "Man.h"

using namespace std;
using namespace eoe;

int main() {

//	People * p = new People("ZhangSan",20,"male");
//	p->sayHi();
//	delete p;


	Man* m=new Man("ZhangSan",19);
	m->sayHi();


	printf("Sex:%s\n",m->getSex().c_str());

	delete m;
	return 0;
}
