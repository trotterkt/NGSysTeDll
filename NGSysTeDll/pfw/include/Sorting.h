#ifndef Default_Sorting_H
#define Default_Sorting_H

#include <boost/algorithm/string.hpp>
#include "include\DataPacket.h"



class Sorting
{
public:

	bool operator()(std::pair<std::string, DataPacket> &first, std::pair<std::string, DataPacket>  &second);
};


#endif
