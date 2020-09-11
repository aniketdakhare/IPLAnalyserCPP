#pragma once
#include <list>
#include <string>
#include "IPLMostRunsAdapter.h"
#include "IPLMostWicketsAdapter.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\Enums\PlayerType.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\IPLPlayerDetails.h"


class IPLAdapterFactory
{
    public:
        list<IPLPlayerDetails> getIPLData(std::string fileName, PlayerType playerType)
        {
            if (playerType == BATSMAN)
                return (new IPLMostRunsAdapter)->loadIPLData(fileName);
            return (new IPLMostWicketsAdapter)->loadIPLData(fileName);
        }
};