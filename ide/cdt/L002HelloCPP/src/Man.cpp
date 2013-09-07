/*
 * Man.cpp
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#include "Man.h"

namespace eoe {

Man::Man(string name,int age):People(name,age,"male") {
}


void Man::sayHello(){
	printf("Man sayhello");
}

void Man::sayHi(){
	printf("[class Man]%s Say Hi\n",getName().c_str());
}

Man::~Man() {
	printf("Delete Man");
}

} /* namespace eoe */
