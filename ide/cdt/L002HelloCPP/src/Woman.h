/*
 * Woman.h
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#ifndef WOMAN_H_
#define WOMAN_H_

#include "People.h"
#include "Object.h"

namespace eoe {

class Woman: public eoe::People, public Object {
public:
	Woman();
	virtual ~Woman();
};

} /* namespace eoe */
#endif /* WOMAN_H_ */
