/*
 * LogicalSideworks.h
 *
 *  Created on: Sep 8, 2016
 *      Author: songjinxin
 */

#ifndef LOGICALSIDEWORKS_H_
#define LOGICALSIDEWORKS_H_
#include "Sideworks.h"
#include "PhysicalSideworks.h"
class LogicalSideworks:public Sideworks {
public:
	LogicalSideworks();
	virtual ~LogicalSideworks();

	friend bool operator<(const LogicalSideworks &lhs, const LogicalSideworks &rhs) {
	    return lhs.size() < rhs.size();
	}

	void route(PhysicalSideworks &physical_sideWorks);

};

#endif /* LOGICALSIDEWORKS_H_ */
