#pragma once
#include <list>
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\IPLPlayerDetails.h"

class IPLAdapter
{
    public:
        virtual list<IPLPlayerDetails> loadIPLData(string fileName) = 0;
};