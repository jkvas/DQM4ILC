  /// \file AHCALRawModule.cc
/*
 *-------------------------------------------------------------
 * AHCALRawModule.cc source template automatically modified from 
 * CaloHitModule  generated by a class generator
 * by A. Irles, DESY, 23 March 2016
 *--------------------------------------------------------------
 * This file is part of DQM4HEP libraries.
 * 
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#include "AHCALRawModule.h"
// to handle and acces to the elements in the LCIO generic Object

// -- std headers
#include <ctime>
#include <cstdlib>
#include <limits>

//#ifndef USELCIO
//#define USELCIO
#include "EVENT/LCGenericObject.h"
#include "EVENT/LCCollection.h"
#include "EVENT/LCEvent.h"
#include "EVENT/LCIO.h"
#include "UTIL/CellIDDecoder.h"
#include "UTIL/LCTOOLS.h"
//#endif

// -- dqm4hep headers
#include "dqm4hep/DQMMonitorElement.h"
#include "dqm4hep/DQMCoreTool.h"
#include "dqm4hep/DQMRun.h"
#include "dqm4hep/DQMXmlHelper.h"
#include "dqm4hep/DQMEvent.h"
#include "dqm4hep/DQMQualityTest.h"
#include "dqm4hep/DQMModuleApi.h"
#include "dqm4hep/DQMPlugin.h"

// -- root headers
#include "TRandom.h"


//using namespace lcio;

namespace dqm4hep
{
// module plugin declaration
DQM_PLUGIN_DECL( AHCALRawModule , "AHCALRawModule" )

//-------------------------------------------------------------------------------------------------

AHCALRawModule::AHCALRawModule() :
	DQMAnalysisModule()
{
	setDetectorName("NO DETECTOR");
	setVersion(1, 0, 0);
}

//-------------------------------------------------------------------------------------------------

AHCALRawModule::~AHCALRawModule()
{
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::readSettings(const TiXmlHandle xmlHandle)
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- readSettings()" );

	m_pADC_hitbit0 = NULL;
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, DQMXmlHelper::bookMonitorElement(this, xmlHandle,
										   "ADC_hb0", m_pADC_hitbit0));

	m_pADC_hitbit1 = NULL;
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, DQMXmlHelper::bookMonitorElement(this, xmlHandle,
										   "ADC_hb1", m_pADC_hitbit1));

	m_pNHitElement = NULL;
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, DQMXmlHelper::bookMonitorElement(this, xmlHandle,
			"NHit", m_pNHitElement));


	m_dumpEvent = false;
	RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, DQMXmlHelper::readParameterValue(xmlHandle,
			"DumpEvent", m_dumpEvent));

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::initModule()
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- init()" );

	// print directory structure of monitor element storage in console
	DQMModuleApi::cd(this);
	DQMModuleApi::ls(this, true);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::endModule()
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- end()" );
	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::processEvent(DQMEvent *pEvent)
{

	//int CycleNrIndex = 1;
	//int BxIDIndex = 2;
	//int EvtNrIndex = 3;
	//int ChipIDIndex = 4;
	//int NChannelsIndex = 5;
	//int TDCFirstChannelIndex = 6;
	//int TDCLastChannelIndex = TDCFirstChannelIndex+pAHCALRaw->getIntVal(NChannelsIndex)-1;
	//int ADCFirstChannelIndex = TDCLastChannelIndex+pAHCALRaw->getIntVal(NChannelsIndex);
	//int ADCLastChannelIndex = ADCFirstChannelIndex+pAHCALRaw->getIntVal(NChannelsIndex)-1;

	// Accessing true ADC and TDC:
	//
	// tdc[i] = tdc14bit[i]%4096
	// adc[i] = adc14bit[i]%4096
	// 
	// Hitbit and gainbit: 
	// 
	// hitbit_adc[i] = (adc14bit[i]& 0x1000)/4096
	// gainbit_adc[i] = (adc14bit[i]& 0x1000)/4096
	// 
	// hitbit_tdc[i] = (tdc14bit[i]& 0x1000)/4096
	// gainbit_tdc[i] = (tdc14bit[i]& 0x1000)/4096

	EVENT::LCEvent *pLCEvent = pEvent->getEvent<EVENT::LCEvent>();

	if(!pLCEvent)
		return STATUS_CODE_FAILURE;

	if(m_dumpEvent)
		UTIL::LCTOOLS::dumpEvent(pLCEvent);

	const std::vector<std::string> *pCollectionNames = pLCEvent->getCollectionNames();

	int totalNHit = 0;

	//	m_pLastXZProfileElement->reset();
	//	m_pLastYZProfileElement->reset();
	//	m_pLastXYProfileElement->reset();

	for(std::vector<std::string>::const_iterator colIter = pCollectionNames->begin(), colEndIter = pCollectionNames->end() ;
			colEndIter != colIter ; ++colIter)
	{

	  const std::string &collectionName(*colIter);

	  	  EVENT::LCCollection *pLCCollection = pLCEvent->getCollection(collectionName);

if(collectionName=="EUDAQDataScCAL")
	{
		if(pLCCollection->getTypeName() == EVENT::LCIO::LCGENERICOBJECT)
		{

			const int nElements = pLCCollection->getNumberOfElements();
			totalNHit += nElements;
			//std::cout << "Number of elements in collection: " << pLCCollection->getNumberOfElements() << std::endl;

			for(int e=0 ; e<nElements ; e++)
			{
			  const EVENT::LCGenericObject *const pAHCALRaw = dynamic_cast<const EVENT::LCGenericObject *const>(pLCCollection->getElementAt(e));
			   if(NULL == pAHCALRaw)
					continue;

			   //std::cout << "This event number: " << pAHCALRaw->getIntVal(0) << std::endl;
			   //std::cout << "This event's HitBit: " << pAHCALRaw->getIntVal(8) << std::endl;
			   //std::cout << "This event's TDC: " << pAHCALRaw->getIntVal(6) << std::endl;

			   if(pAHCALRaw->getIntVal(8)==0) m_pADC_hitbit0->get<TH1I>()->Fill(pAHCALRaw->getIntVal(6));
			   if(pAHCALRaw->getIntVal(8)==1) m_pADC_hitbit1->get<TH1I>()->Fill(pAHCALRaw->getIntVal(6));
			//m_pTimeElement->get<TH1F>()->Fill(pAHCALRaw->getTime());
			}
		}
	}


	m_pNHitElement->get<TH1I>()->Fill(totalNHit);
	//std::cout << "This event's totalNHit: " << totalNHit << std::endl;

	return STATUS_CODE_SUCCESS;
	//std::cout << "Finished processEvent function." << std::endl;
}
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::startOfCycle()
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- startOfCycle()" );
	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::endOfCycle()
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- endOfCycle()" );

	// run all quality tests on all monitor elements
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, DQMModuleApi::runQualityTests(this));

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::startOfRun(DQMRun *pRun)
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- startOfRun()" );
	LOG4CXX_INFO( dqmMainLogger , "Run no " << pRun->getRunNumber() );
	//	time_t startTime = pRun->getStartTime();
	time_t startTime = std::chrono::system_clock::to_time_t(pRun->getStartTime());

	std::string timeStr;
	DQMCoreTool::timeToHMS(startTime, timeStr);

	LOG4CXX_INFO( dqmMainLogger , "Start time " << timeStr );
	LOG4CXX_INFO( dqmMainLogger , "Detector is " << pRun->getDetectorName() );
	LOG4CXX_INFO( dqmMainLogger , "Description " << pRun->getDescription() );

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode AHCALRawModule::endOfRun(DQMRun *pRun)
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- endOfRun()" );
	LOG4CXX_INFO( dqmMainLogger , "Run no " << pRun->getRunNumber() );

	//	time_t endTime = pRun->getEndTime();
	time_t endTime = std::chrono::system_clock::to_time_t(pRun->getEndTime());
	std::string timeStr;
	DQMCoreTool::timeToHMS(endTime, timeStr);

	LOG4CXX_INFO( dqmMainLogger , "End time " << timeStr );

	return STATUS_CODE_SUCCESS;
}

} 
