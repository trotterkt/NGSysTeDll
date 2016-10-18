//## auto_generated
#include "pfw\include\PFWBroker.h"
 

PFWBroker::PFWBroker() 
{
}

PFWBroker::~PFWBroker() 
{
}

bool PFWBroker::isMaterialized(std::string oid) 
{
	//:TODO: Stub
	return (itsICache[0]->isMaterialized(oid));
}

//std::vector<ICache*> PFWBroker::materializeAll() 
//{
//}


