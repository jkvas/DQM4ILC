//These are initialised here to be set later, and are our search terms.
int xPos;
int yPos;
int zPos;

int xIncrement = 1;
int yIncrement = 1;

//These are read in from the XML file.
int xChipPos;
int yChipPos;

//Looking for Chip x Channel: 224x14
int targetChip = 224;
int targetChannel = 14;

//We already know we need Chip 224, so can work out the ijk of the origin channel of 224 like this:

xPos = 1+xChipPos*xChannelsPerChip;
yPos = 1+yChipPos*yChannelsPerChip;

//At this point we're on the top-left channel of Chip 224; in global ijk this is (7,7,0). This is the origin channel, NOT Channel 0, so we do this:

xPos += zerothChannel.x;
yPos += zerothChannel.y;

//In the real world, we'd do this in one step:

xPos = 1+xChipPos*xChannelsPerChip+zerothChannel.x;
yPos = 1+yChipPos*yChannelsPerChip+zerothChannel.y;

//Now we're on Channel 0 of Chip 224; in global ijk this is (12,7,0). Now we need to 'scan' across the chip to find our correct channel. 
    //But first we need to know which direction the channels are arranged in, so we pull in data from the first channel:

if ( abs(zerothChannel.x-firstChannel.x) == 1 )
  {
    //Now we know that our one-channel steps are along the x axis
    chipSearchStep = xChannelsPerChip;
  }
else if ( abs(zerothChannel.y-firstChannel.y) == 1 ) 
  {
    //Now we know that our one-channel steps are along the y axis
    chipSearchStep = yChannelsPerChip;
  }
else
  {
    //Throw an error, since this shouldn't happen unless the channels are arranged in Z.
  }

//Now we need to know which direction our search steps need to be in, since if we're, say, at the rightmost edge of a chip and increase xPos by one, we go out of bounds.
//This means we need to search 'backwards'; our step size must be negative. We need to check whether step size is positive (initialised to 1 above) or negative (use -1).

if (zerothChannel.x == xChannelsPerChip-1)
  {
    xIncrement = -1;
  }
if (zerothChannel.y == yChannelsPerChip-1)
  {
    yIncrement = -1;
  }

while( currentChannel != targetChannel )
  {
    if ( abs(targetChannel-currentChannel) > chipSearchStep )
      {
	currentChannel = currentChannel+chipSearchStep;    // Changing our current guess of chip number for the next loop.
	xPos += xIncrement;                                // Incrementing this axis by one unit (channel).    //This must be the axis we know is NOT in one-channel steps.
      }

    //After two of these loops, we've gone from a currentChannel of 0, to 6, to 12. In global ijk we've gone from (12,7,0) to (11,7,0) to (10,7,0).
    //At this point, we're within one chip-width, so the next if loop triggers.

    else if ( abs(targetChannel-currentChannel) < chipSearchStep )
      {
	currentChannel = currentChannel+1;                 // Changing our current guess of chip number for the next loop.
	yPos += yIncrement;                                // Incrementing this axis by one unit (channel).    //This must be the axis we know IS in one-channel steps.
      }

    if (xPos < 0 || xPos > xChipsPerLayer*xChannelsPerChip || yPos < 0 || yPos > yChipsPerLayer*yChannelsPerChip )
      {
	//We've gone out of bounds; throw an exception and break the loop.
	throw 20;    //Placeholder error code.
	break;
      }

    //After two of these loops, we've gone from a currentChannel of 12, to 13, to 14. In global ijk we've gone from (10,7,0) to (10,8,0) to (10,9,0).
    //Now currentChannel and targetChannel are the same, so the loop termination condition fires and breaks the loop.

  }

// Now we're at (10,7,0) and these values are already stored in xPos, yPos and zPos. We have our ijk!

//-------------------------------------------------------------------------------------------------

//In the readSettings function of our analysis module, we can load in the XML data to define how large our histogram needs to be? Do we need to define the size of histograms at compile time?

const dqm4hep::TiXmlHandle xmlDocumentHandle(&document);
const dqm4hep::TiXmlHandle xmlHandle(xmlDocumentHandle.FirstChildElement().Element());

//The first object is an XML element, then we query an attribute's value, giving it a type. Then we nominate the attribute by string, and give the (pointer to) C++ variable we store this value in. 
pLayerXmlElement->QueryValueAttribute<unsigned int>("id", &chamber.m_layerId);

//

//Pull our XML file into memory
const dqm4hep::TiXmlHandle xmlHandle(xmlDocumentHandle.FirstChildElement().Element());

//For our structure, we need to do almost the exact same for our layer:
pLayerXmlElement = xmlHandle.FirstChild("layer").Element();
pLayerXmlElement->QueryValueAttribute<unsigned int>("id",ThisLayerID);

//Then for the individual chip information:
pChipXmlElement = pLayerXmlElement.FirstChild("chip").Element();
pChipXmlElement->QueryValueAttribute<unsigned int>("id",ThisChipID);
pChipXmlElement->QueryValueAttribute<unsigned int>("x0",ThisChipx0);
pChipXmlElement->QueryValueAttribute<unsigned int>("y0",ThisChipy0);
pChipXmlElement->QueryValueAttribute<unsigned int>("z0",ThisChipz0);

//Then for the zeroth and first channel of the chip:
pChannelXmlElement = pChipXmlElement.FirstChild("zerothChannel").Element();
pChannelXmlElement->QueryValueAttribute<unsigned int>("x",ThisZerothChannelx);
pChannelXmlElement->QueryValueAttribute<unsigned int>("y",ThisZerothChannely);

pChannelXmlElement = pChipXmlElement.LastChild("firstChannel").Element();
pChannelXmlElement->QueryValueAttribute<unsigned int>("x",ThisFirstChannelx);
pChannelXmlElement->QueryValueAttribute<unsigned int>("y",ThisFirstChannely);

    //These are actually being used as iterators; we go from the FirstChild.Element(), then to NextSiblingElement to iterate over the XML objects.


//-------------------------------------------------------------------------------------------------

dqm4hep::StatusCode SDHCALElectronicsMapping::readSettings(const dqm4hep::TiXmlHandle xmlHandle)
{
	if(m_isInitialized)
		return dqm4hep::STATUS_CODE_ALREADY_INITIALIZED;

	bool readFromDB = false;
	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"ReadFromDB", readFromDB));

	std::string geometryFileName = "sdhcalGeometry.xml";
	RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"GeometryFileName", geometryFileName));

	if( readFromDB )
	{
		std::string host, user, password, database, beamTest;

		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
				"Host", host));

		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
				"User", user));

		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
				"Password", password));

		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
				"Database", database));

		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
				"BeamTest", beamTest));

		GeometryDBInterface interface;
		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, interface.connect( host , user , password , database ));
		RETURN_RESULT_IF(dqm4hep::STATUS_CODE_SUCCESS, !=, interface.dumpGeometry( geometryFileName , beamTest ));
	}

	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"CellReferencePosition", m_cellReferencePosition));

	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"CellSize0", m_cellSize0));

	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"CellSize1", m_cellSize1));

	dqm4hep::UIntVector layerMask;
	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValues(xmlHandle,
			"LayerMask", layerMask));

	dqm4hep::UIntVector difMask;
	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValues(xmlHandle,
			"DifMask", difMask));

	m_rotateAxes = true;
	RETURN_RESULT_IF_AND_IF(dqm4hep::STATUS_CODE_SUCCESS, dqm4hep::STATUS_CODE_NOT_FOUND, !=, dqm4hep::DQMXmlHelper::readParameterValue(xmlHandle,
			"RotateAxes", m_rotateAxes));

	GeometryXmlIO reader;
	RETURN_RESULT_IF( dqm4hep::STATUS_CODE_SUCCESS, !=, reader.load( geometryFileName , m_geometry, layerMask , difMask ) );

	for(Geometry::iterator iter = m_geometry.begin(), endIter = m_geometry.end() ;
			endIter != iter ; ++iter)
	{
		for(DifMapping::iterator difIter = iter->second.m_difList.begin(), difEndIter = iter->second.m_difList.end() ;
				difEndIter != difIter ; ++difIter)
		{
			m_difMapping[ difIter->first ] = difIter->second;
		}
	}

	m_isInitialized = true;

	return dqm4hep::STATUS_CODE_SUCCESS;
}
