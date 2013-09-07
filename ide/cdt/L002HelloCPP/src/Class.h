/*
 * Class.h
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#ifndef CLASS_H_
#define CLASS_H_

#include "People.h"
#include "Man.h"

namespace eoe {

class People;
class Man;

class Class {
public:
	Class();
	virtual ~Class();

private:
	People* teacher;
};

} /* namespace eoe */
#endif /* CLASS_H_ */
