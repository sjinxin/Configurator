/*
 * LogicalOutputPort.h
 *
 *  Created on: Sep 26, 2016
 *      Author: songjinxin
 */

#ifndef LOGICALOUTPUTPORT_H_
#define LOGICALOUTPUTPORT_H_
#include <list>
#include "OutputPort.h"
class LogicalInputPort;
class LogicalOutputPort :public OutputPort{
    std::list<LogicalInputPort*> destination_input;
public:
    LogicalOutputPort(const std::string& name,int width,FUInstance* p);
	virtual ~LogicalOutputPort();
    int calcCost(Port* phyOut);
};

#endif /* LOGICALOUTPUTPORT_H_ */
