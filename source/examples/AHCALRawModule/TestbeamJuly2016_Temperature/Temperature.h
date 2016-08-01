 /// \file AHCALRawModuleGlobal.h
/*
 *
 *-------------------------------------------------------------
 * AHCALRawModuleChannel.cc source template automatically modified from 
 * CaloHitModule  generated by a class generator
 * by A. Irles, DESY, 23 March 2016
 *--------------------------------------------------------------
 *
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

#ifndef Temperature_H
#define Temperature_H

#include "dqm4hep/DQMAnalysisModule.h"

namespace dqm4hep
{

class DQMMonitorElement;

/** Temperature class
 */ 
class Temperature : public DQMAnalysisModule
{
public:
	Temperature();
	~Temperature();

	StatusCode initModule();
	StatusCode readSettings(const TiXmlHandle xmlHandle);
	StatusCode processEvent(DQMEvent *pEvent);
	StatusCode startOfCycle();
	StatusCode endOfCycle();
	StatusCode startOfRun(DQMRun *pRun);
	StatusCode endOfRun(DQMRun *pRun);
	StatusCode endModule();

protected:

	// Temperature
        DQMMonitorElementPtr                        m_pTempAverage_1;
        DQMMonitorElementPtr                        m_pTempAverage_2;
        DQMMonitorElementPtr                        m_pTempAverage_3;
        DQMMonitorElementPtr                        m_pTempAverage_4;
        DQMMonitorElementPtr                        m_pTempAverage_5;
        DQMMonitorElementPtr                        m_pTempAverage_6;
        DQMMonitorElementPtr                        m_pTempAverage_7;
        DQMMonitorElementPtr                        m_pTempAverage_8;
        DQMMonitorElementPtr                        m_pTempAverage_9;
        DQMMonitorElementPtr                        m_pTempAverage_10;
        DQMMonitorElementPtr                        m_pTempAverage_11;
        DQMMonitorElementPtr                        m_pTempAverage_12;
        DQMMonitorElementPtr                        m_pTempAverage_13;
        DQMMonitorElementPtr                        m_pTempAverage_14;
        DQMMonitorElementPtr                        m_pTempAverage_15;

        DQMMonitorElementPtr                        m_pTempDIF_1;
        DQMMonitorElementPtr                        m_pTempDIF_2;
        DQMMonitorElementPtr                        m_pTempDIF_3;
        DQMMonitorElementPtr                        m_pTempDIF_4;
        DQMMonitorElementPtr                        m_pTempDIF_5;
        DQMMonitorElementPtr                        m_pTempDIF_6;
        DQMMonitorElementPtr                        m_pTempDIF_7;
        DQMMonitorElementPtr                        m_pTempDIF_8;
        DQMMonitorElementPtr                        m_pTempDIF_9;
        DQMMonitorElementPtr                        m_pTempDIF_10;
        DQMMonitorElementPtr                        m_pTempDIF_11;
        DQMMonitorElementPtr                        m_pTempDIF_12;
        DQMMonitorElementPtr                        m_pTempDIF_13;
        DQMMonitorElementPtr                        m_pTempDIF_14;
        DQMMonitorElementPtr                        m_pTempDIF_15;

        DQMMonitorElementPtr                        m_pTempPWR_1;
        DQMMonitorElementPtr                        m_pTempPWR_2;
        DQMMonitorElementPtr                        m_pTempPWR_3;
        DQMMonitorElementPtr                        m_pTempPWR_4;
        DQMMonitorElementPtr                        m_pTempPWR_5;
        DQMMonitorElementPtr                        m_pTempPWR_6;
        DQMMonitorElementPtr                        m_pTempPWR_7;
        DQMMonitorElementPtr                        m_pTempPWR_8;
        DQMMonitorElementPtr                        m_pTempPWR_9;
        DQMMonitorElementPtr                        m_pTempPWR_10;
        DQMMonitorElementPtr                        m_pTempPWR_11;
        DQMMonitorElementPtr                        m_pTempPWR_12;
        DQMMonitorElementPtr                        m_pTempPWR_13;
        DQMMonitorElementPtr                        m_pTempPWR_14;
        DQMMonitorElementPtr                        m_pTempPWR_15;

	bool                                        m_dumpEvent;

}; 

} 

#endif  //  Temperature_H