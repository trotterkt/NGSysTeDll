#ifndef Default_TestEquipmentCsvBroker_H
#define Default_TestEquipmentCsvBroker_H

#include "pfw\include\PFWFileBroker.h"
#include "include\Singleton.h"
#include "include\DataPacket.h"



class TestEquipmentCsvBroker : public PFWFileBroker, public Singleton<TestEquipmentCsvBroker>
{
public:
	TestEquipmentCsvBroker();
	~TestEquipmentCsvBroker();

	void* materializeWith(std::string oid);
	ICache* materializeAll();

	void* objectWith(std::string oid);

	void translate(double subject, std::string& converted);
	void translate(DataPacket subject);

	virtual void reset();

	virtual void resetCache() {}
};

#endif
