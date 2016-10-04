/*
 * FUInstance.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: songjinxin
 */

#include <FUInstance.h>
#include "OutputPort.h"
#include "InputPort.h"

FUInstance::FUInstance(const FUInstance& obj)
:name(obj.name),
 type(obj.type),
 description(obj.description),
 inports(obj.inports),
 outports(obj.outports){}

//FUInstance& FUInstance::operator=(const FUInstance& obj){
////	FUInstance tmp(obj);
////	*this = std::move(tmp);
//	return *this;
//}


FUInstance::FUInstance(const std::string& name, const std::string& type, FUDescription* desc)
:name(name),
 type(type),
 description(desc),
 inports(),
 outports()
{
	// TODO Auto-generated constructor stub
}

FUInstance::~FUInstance() {
	// TODO Auto-generated destructor stub
}

InputPort* FUInstance::getInputPort(const std::string& i){
	return inports.at(i);
}

OutputPort* FUInstance::getOutputPort(const std::string& o){
	return outports.at(o);
}

void FUInstance::connect(const std::string& o, FUInstance* dst,const std::string& i){
	outports.at(o)->connect(dst->getInputPort(i));
}

int FUInstance::size(){
	int sz = 0;
	for(auto i: inports){
		sz += i.second->size();
	}
	for(auto o: outports){
		sz += o.second->size();
	}
	return sz;
}
