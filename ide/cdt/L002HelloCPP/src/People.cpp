/*
 * People.cpp
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#include "People.h"


namespace eoe{
//int People::age = 10;

People::People(string name,int age,string sex) {
	setAge(10);
	setName(name);
	setSex(sex);
}


void People::sayHi(){
	printf("[class People]%s Say Hi\n",getName().c_str());
}


People::~People() {
	// TODO Auto-generated destructor stub
}

void People::setAge(int value) {
	age = value;
}

void People::setName(string name) {
	this->name = name;
}

string People::getName() {
	return this->name;
}

int People::getAge() {
	return age;
}

void eoe::People::setSex(string _sex) {
	sex = _sex;
}

string eoe::People::getSex() {
	return sex;
}


//void eoe::People::addChild(Man* m) {
//}

}
