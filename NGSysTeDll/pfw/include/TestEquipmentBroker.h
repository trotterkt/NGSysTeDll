#ifndef Default_TestEquipmentBroker_H
#define Default_TestEquipmentBroker_H

#include "pfw\include\PFWFileBroker.h"
#include "include\Singleton.h"
#include "include\DataPacket.h"



class TestEquipmentBroker : public PFWFileBroker, public Singleton<TestEquipmentBroker>
{
public:
	TestEquipmentBroker();
	~TestEquipmentBroker();

	void* materializeWith(std::string oid);
    ICache* materializeAll();

	void* objectWith(std::string oid);

	void translate(int subject); 
	void translate(double subject, std::string& converted); 
	void translate(DataPacket subject);

	virtual void resetCache();

private:
	bool getNextPacket(unsigned char* packetBuffer);

};

#endif
