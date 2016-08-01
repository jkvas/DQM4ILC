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

#ifndef HitMap_H
#define HitMap_H

#include "dqm4hep/DQMAnalysisModule.h"

namespace dqm4hep
{

class DQMMonitorElement;

/** HitMap class
 */ 
class HitMap : public DQMAnalysisModule
{
public:
	HitMap();
	~HitMap();

	StatusCode initModule();
	StatusCode readSettings(const TiXmlHandle xmlHandle);
	StatusCode processEvent(DQMEvent *pEvent);
	StatusCode startOfCycle();
	StatusCode endOfCycle();
	StatusCode startOfRun(DQMRun *pRun);
	StatusCode endOfRun(DQMRun *pRun);
	StatusCode endModule();

        StatusCode buildGeometryMap(const TiXmlHandle xmlHandle);
        int electronicsToIJK(int Chip, int Channel);
        int IJKToElectronics(int I, int J, int K);

 protected:

	// MIP hitmaps
        DQMMonitorElementPtr                        m_pMIP_300_l01;
	DQMMonitorElementPtr                        m_pMIP_300_l02;
        DQMMonitorElementPtr                        m_pMIP_300_l03;
        DQMMonitorElementPtr                        m_pMIP_300_l04;
        DQMMonitorElementPtr                        m_pMIP_300_l05;
        DQMMonitorElementPtr                        m_pMIP_300_l06;
        DQMMonitorElementPtr                        m_pMIP_300_l07;
        DQMMonitorElementPtr                        m_pMIP_300_l08;
        DQMMonitorElementPtr                        m_pMIP_300_l09;
        DQMMonitorElementPtr                        m_pMIP_300_l10;
        DQMMonitorElementPtr                        m_pMIP_300_l11;
        DQMMonitorElementPtr                        m_pMIP_300_l12;
        DQMMonitorElementPtr                        m_pMIP_300_l13;
        DQMMonitorElementPtr                        m_pMIP_300_l14;
        DQMMonitorElementPtr                        m_pMIP_300_l15;

	// Ped hitmaps
        DQMMonitorElementPtr                        m_pPed_300_l01;
	DQMMonitorElementPtr                        m_pPed_300_l02;
        DQMMonitorElementPtr                        m_pPed_300_l03;
        DQMMonitorElementPtr                        m_pPed_300_l04;
        DQMMonitorElementPtr                        m_pPed_300_l05;
        DQMMonitorElementPtr                        m_pPed_300_l06;
        DQMMonitorElementPtr                        m_pPed_300_l07;
        DQMMonitorElementPtr                        m_pPed_300_l08;
        DQMMonitorElementPtr                        m_pPed_300_l09;
        DQMMonitorElementPtr                        m_pPed_300_l10;
        DQMMonitorElementPtr                        m_pPed_300_l11;
        DQMMonitorElementPtr                        m_pPed_300_l12;
        DQMMonitorElementPtr                        m_pPed_300_l13;
        DQMMonitorElementPtr                        m_pPed_300_l14;
        DQMMonitorElementPtr                        m_pPed_300_l15;

        bool                                        m_dumpEvent;

        std::string                                 m_geometryFile;
        std::map<int, int>                          ijkmap;
        std::map<int, int>                          chpchnmap;

}; 

} 

#endif  //  HitMap_H