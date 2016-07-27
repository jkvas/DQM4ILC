
std::map<int, int> ijkmap;
std::map<int, int> chpchnmap;

StatusCode AHCALRawModule::readSettings(const TiXmlHandle xmlHandle)
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- readSettings()" );

	std::string m_geometryFile = "";

	RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, DQMXmlHelper::readParameterValue(xmlHandle,
			"GeometryFilename", m_geometryFilename));

	TiXmlHandle m_geometryFile(m_geometryFilename);

	RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, AHCALRawModule::buildGeometryMap(m_geometryFile));

	return STATUS_CODE_SUCCESS;
}


StatusCode AHCALRawModule::buildGeometryMap(const TiXmlHandle xmlHandle)
{

  //Error checking to see if the file can be loaded.
  if( ! xmlHandle.LoadFile() ) return dqm4hep::STATUS_CODE_FAILURE;

  //Giving the object a new name and making it a constant.
  const dqm4hep::TiXmlHandle xmlDocumentHandle(&xmlHandle);

  //Getting the very first child of the XML file; in our case, this is the dqm4hepGeometryMap bracket.
  const dqm4hep::TiXmlHandle xmlHandle(xmlDocumentHandle.FirstChildElement("dqm4hepGeometryMap").Element());

  //Giving a unique name to the globalGeometryProperties object
  dqm4hep::TiXmlHandle pGlobalPropertiesXmlElement(xmlHandle.FirstChild("globalGeometryProperties").Element());

  //Reading the two values we care about in this object out into two C++ variables.
  pGlobalPropertiesXmlElement->QueryValueAttribute<int>("xChannelsPerChip", &_xNumChannels);
  pGlobalPropertiesXmlElement->QueryValueAttribute<int>("yChannelsPerChip", &_yNumChannels);

  //Iterate over each layer
  for (dqm4hep::TiXmlElement *pLayerXmlElement = xmlHandle.FirstChild("layer").Element(); NULL != pLayerXmlElement; pLayerXmlElement = pLayerXmlElement->NextSiblingElement("layer"))
    {

      //Iterate over each chip
      for (dqm4hep::TiXmlElement *pChipXmlElement = pLayerXmlElement.FirstChild("chip").Element(); NULL != pChipXmlElement; pChipXmlElement = pChipXmlElement->NextSiblingElement("chip"))
	{

	  //Iterate over each channel
	  for (dqm4hep::TiXmlElement *pChannelXmlElement = pChipXmlElement.FirstChild("channel").Element(); NULL != pChannelXmlElement; pChannelXmlElement = pChannelXmlElement->NextSiblingElement("channel"))
	    {
	      //Pull out all the data: chip number, channel number, ijk
	      pChipXmlElement->QueryValueAttribute<int>("id",ChipID);
	      pChannelXmlElement->QueryValueAttribute<int>("id",ChannelID);
	      pChannelXmlElement->QueryValueAttribute<int>("i",I);
	      pChannelXmlElement->QueryValueAttribute<int>("j",J);
	      pChannelXmlElement->QueryValueAttribute<int>("k",K);

	      //Formatting data to go into our map
	      ChpChnNum = ChipID*100+Chn;
	      ijkNum = I*10000 + J*100 + K;

	      //Filling the map (Chip, Chn)->(I, J, K)
	      ijkmap.insert(std::make_pair(ChpChnNum, ijkNum));

	      //Filling the map (I, J, K)->(Chip, Chn)
	      chpchnmap.insert(std::make_pair(ijkNum, ChpChnNum));
	    }
	}
    }

  return STATUS_CODE_SUCCESS;

}

int AHCALRawModule::electronicsToIJK(int Chip, int Channel)
{
  std::map<int, int>::iterator itMap;
  int index = Chip*100+Chn;
  int IJK = -1;

  if(ijkmap.find(index) != ijkmap.end())
    {
      itMap = ijkmap.find(index);
      IJK = itMap->second;
    }

  return IJK;
}

int AHCALRawModule::IJKToElectronics(int I, int J, int K)
{
  std::map<int, int>::iterator itMap;
  int index = I*10000+J*100+K;
  int ChipChn= -1;

  if(chpchnmap.find(index) != chpchnmap.end())
    {
      itMap = chpchnmap.find(index);
      ChipChn = itMap->second;
    }

  return ChipChn;
}

//--- Things that have to be declared in header file:

std::map<int, int> ijkmap;
std::map<int, int> chpchnmap;

std::string m_geometryFile;
