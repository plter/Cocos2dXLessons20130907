/*
 * Class.cpp
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#include "Class.h"

namespace eoe {

Class::Class() {
	teacher = (People*)new Man("ChenLaoshi",27);
}

Class::~Class() {
	delete teacher;
}

} /* namespace eoe */
