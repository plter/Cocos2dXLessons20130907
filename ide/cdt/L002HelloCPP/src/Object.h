/*
 * Object.h
 *
 *  Created on: 2013?9?7?
 *      Author: plter
 */

#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
public:
	Object();
	virtual void retain();
	virtual void release();
	virtual int retainCount();
	virtual ~Object();

private:
	int _retainCount;
};

#endif /* OBJECT_H_ */
