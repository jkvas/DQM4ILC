  /// \file AHCALRawModuleT0.h
/*
 *
 *-------------------------------------------------------------
 * AHCALRawModuleT0.cc source template automatically modified from 
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

#ifndef AHCALRAWMODULET0_H
#define AHCALRAWMODULET0_H

#include "dqm4hep/DQMAnalysisModule.h"

namespace dqm4hep
{

class DQMMonitorElement;

/** AHCALRawModuleT0 class
 */ 
class AHCALRawModuleT0 : public DQMAnalysisModule
{
public:
	AHCALRawModuleT0();
	~AHCALRawModuleT0();

	StatusCode initModule();
	StatusCode readSettings(const TiXmlHandle xmlHandle);
	StatusCode processEvent(DQMEvent *pEvent);
	StatusCode startOfCycle();
	StatusCode endOfCycle();
	StatusCode startOfRun(DQMRun *pRun);
	StatusCode endOfRun(DQMRun *pRun);
	StatusCode endModule();

protected:

        DQMMonitorElementPtr                        m_pT0Events;

        DQMMonitorElementPtr                        m_pADC_hitbit0_1;
        DQMMonitorElementPtr                        m_pADC_hitbit1_1;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_1;

        DQMMonitorElementPtr                        m_pADC_hitbit0_2;
        DQMMonitorElementPtr                        m_pADC_hitbit1_2;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_2;

        DQMMonitorElementPtr                        m_pADC_hitbit0_3;
        DQMMonitorElementPtr                        m_pADC_hitbit1_3;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_3;

        DQMMonitorElementPtr                        m_pADC_hitbit0_4;
        DQMMonitorElementPtr                        m_pADC_hitbit1_4;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_4;

        DQMMonitorElementPtr                        m_pADC_hitbit0_5;
        DQMMonitorElementPtr                        m_pADC_hitbit1_5;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_5;

        DQMMonitorElementPtr                        m_pADC_hitbit0_6;
        DQMMonitorElementPtr                        m_pADC_hitbit1_6;
        DQMMonitorElementPtr                        m_pADC_hitbit1Agree_6;

	bool                                      m_dumpEvent;

        int                                       m_ChipID1;
        int                                       m_ChipID2;
        int                                       m_ChipID3;
        int                                       m_ChipID4;
        int                                       m_ChipID5;
        int                                       m_ChipID6;

        int                                       m_ChannelNum1;
        int                                       m_ChannelNum2;
        int                                       m_ChannelNum3;
        int                                       m_ChannelNum4;
        int                                       m_ChannelNum5;
        int                                       m_ChannelNum6;


}; 

} 

#endif  //  AHCALRAWMODULET0_H