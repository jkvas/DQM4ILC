  /// \file DQMLCHelper.cc
/*
 *
 * DQMLCHelper.cc source template automatically generated by a class generator
 * Creation date : ven. avr. 15 2016
 *
 * This file is part of DQM4ILC libraries.
 * 
 * DQM4ILC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * DQM4ILC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DQM4ILC.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#include "dqm4ilc/DQMLCHelper.h"

namespace dqm4ilc
{

void DQMLCHelper::copyLCParameters( const EVENT::LCParameters &inputParameters , EVENT::LCParameters &targetParameters )
{
	EVENT::StringVec intKeys, floatKeys, stringKeys;

	inputParameters.getIntKeys( intKeys );
	inputParameters.getFloatKeys( floatKeys );
	inputParameters.getStringKeys( stringKeys );

	EVENT::IntVec dummyInts;
	EVENT::FloatVec dummyFloats;
	EVENT::StringVec dummyStrings;

	for(unsigned int i=0 ; i<intKeys.size() ; i++)
		targetParameters.setValues( intKeys.at(i), inputParameters.getIntVals( intKeys.at(i) , dummyInts ) );

	for(unsigned int i=0 ; i<floatKeys.size() ; i++)
		targetParameters.setValues( floatKeys.at(i), inputParameters.getFloatVals( floatKeys.at(i) , dummyFloats ) );

	for(unsigned int i=0 ; i<stringKeys.size() ; i++)
		targetParameters.setValues( stringKeys.at(i), inputParameters.getStringVals( stringKeys.at(i) , dummyStrings ) );
}

} 
