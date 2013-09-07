/*
 * Man.h
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#ifndef MAN_H_
#define MAN_H_

#include "People.h"
#include <string>

using namespace std;

namespace eoe {
//class People;

class Man: public People{
public:
	Man(string name,int age);
	virtual void sayHi();
	virtual void sayHello();
	virtual ~Man();
};

} /* namespace eoe */
#endif /* MAN_H_ */
