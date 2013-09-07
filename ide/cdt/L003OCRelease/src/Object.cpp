/*
 * Object.cpp
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#include "Object.h"
#include <stdio.h>

Object::Object() {
	_retainCount=1;

	printf("create object\n");
}

void Object::retain() {
	_retainCount++;
}

void Object::release() {
	_retainCount--;

	if (_retainCount<=0) {
		delete this;
	}
}

int Object::retainCount() {
	return _retainCount;
}

Object::~Object() {
	printf("delete object\n");
}

