/*
 * People.h
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include <stdio.h>
#include <string>
//#include "Man.h"

using namespace std;

namespace eoe {

//class Man;

class People {
public:
	People(string name,int age,string sex);
	virtual void sayHi();
//	virtual void sayHello()=0;
	virtual void setAge(int value);
	virtual void setName(string name);
	virtual string getName();
	virtual int getAge();
//	virtual void addChild(Man* m);
	virtual void setSex(string _sex);
	virtual string getSex();
	virtual ~People();

private:
	int age;
	string name;
	string sex;
};

}  // namespace eoe

#endif /* PEOPLE_H_ */
