
//-----

std::map<int, int> ijkmap;
std::map<int, int> chpchnmap;

StatusCode AHCALRawModule::readSettings(const TiXmlHandle xmlHandle)
{
	LOG4CXX_INFO( dqmMainLogger , "Module : " << getName() << " -- readSettings()" );

	std::string m_geometryFile = "";

	RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, DQMXmlHelper::readParameterValue(xmlHandle,
			"geometryFilename", m_geometryFilename));

	TiXmlHandle m_geometryFile(m_geometryFilename);

	RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, AHCALRawModule::buildGeometryMap(m_geometryFile));

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
	      pChipXmlElement->QueryValueAttribute<unsigned int>("id",ChipID);
	      pChannelXmlElement->QueryValueAttribute<unsigned int>("id",ChannelID);
	      pChannelXmlElement->QueryValueAttribute<unsigned int>("i",I);
	      pChannelXmlElement->QueryValueAttribute<unsigned int>("j",J);
	      pChannelXmlElement->QueryValueAttribute<unsigned int>("k",K);

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





//-------------------------


  //Beginning a for loop over the layer objects.
  //We initialise these objects during the loop declaration, and out iteration step is the NextSiblingElement() function, which reads in the next object at the same level.
  for (dqm4hep::TiXmlElement *pLayerXmlElement = xmlHandle.FirstChild("layer").Element(); NULL != pLayerXmlElement; pLayerXmlElement = pLayerXmlElement->NextSiblingElement("layer"))
    {

      pLayerXmlElement->QueryValueAttribute<int>("id", &k); //Store the layer ID as it's k value.

      //Now we begin a loop over each chip in this layer, same as above.
      for (dqm4hep::TiXmlElement *pChipXmlElement = pLayerXmlElement.FirstChild("chip").Element(); NULL != pChipXmlElement; pChipXmlElement = pChipXmlElement->NextSiblingElement("chip"))
	{
	  pChannelXmlElement = pChipXmlElement.FirstChild("zerothChannel").Element();
	  pChannelXmlElement->QueryValueAttribute<unsigned int>("x",ThisZerothChannelx);    //We need to make sure the variables these are stored in are persistent and useable elsewhere.
	  pChannelXmlElement->QueryValueAttribute<unsigned int>("y",ThisZerothChannely);

	  pChannelXmlElement = pChipXmlElement.LastChild("firstChannel").Element();
	  pChannelXmlElement->QueryValueAttribute<unsigned int>("x",ThisFirstChannelx);
	  pChannelXmlElement->QueryValueAttribute<unsigned int>("y",ThisFirstChannely);
	}
    

    }

  ChpChnNum = ChipID*100+Chn;
  ijkNum = I*10000 + J*100 + K;

  //Fill the map (Chip, Chn)->(I, J, K)
  ijkmap.insert(std::make_pair(ChpChnNum, ijkNum));

  //Fill the map (I, J, K)->(Chip, Chn)
  chpchnmap.insert(std::make_pair(ijkNum, ChpChnNum));


//------------------------------------

//So we start from the 0th and 1st channels on each chip. We know our increment direction is either x or y.
//We store Channel 1 as currentChannel and the last channel in the chip (which is xChannels*yChannels-1) as endChannel.
//So then we have a while loop that takes currentChannel and currentIJK and fills it into the map, continuing until it hits the edge of the chip;
    // This should be something like currentChannel%(xChannelsPerChip-1) == 0
//Then we switch to the next strip along the axis and continue until we're at endChannel


for(int currentChannel = 2; currentChannel != endChannel; currentChannel++)
  {
   
    if {currentChannel%(xChannelsPerChip-1) == 0) {}
    
  }
