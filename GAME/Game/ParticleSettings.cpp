#include "ParticleSettings.h"
#include <iostream>

using namespace std;

ParticleSettings::ParticleSettings(IrrlichtDevice *device, stringw file) :device(device), settingsFile(file)
{	
	IFileSystem* fs = device->getFileSystem();
	IXMLReader* xml = fs->createXMLReader(settingsFile);
	while (xml && xml->read())
	{
		switch (xml->getNodeType())
		{
			case EXN_ELEMENT:
			{
				stringc nodeName = xml->getNodeName();

				if (nodeName.equals_ignore_case("commonSettings"))
				{
					imagepath.append(xml->getAttributeValue(L"imagePath"));

					scale.X = xml->getAttributeValueAsFloat(L"scaleX");
					scale.Y = xml->getAttributeValueAsFloat(L"scaleY");
					scale.Z = xml->getAttributeValueAsFloat(L"scaleZ");

					minStartSize = xml->getAttributeValueAsInt(L"minStartSize");
					
					maxStartSize = xml->getAttributeValueAsInt(L"maxStartSize");
					
					type.append(xml->getAttributeValue(L"type"));
					
					duration = xml->getAttributeValueAsInt(L"duration");
					
					direction.X = xml->getAttributeValueAsFloat(L"directionX");
					direction.Y = xml->getAttributeValueAsFloat(L"directionY");
					direction.Z = xml->getAttributeValueAsFloat(L"directionZ");			

					minRate = xml->getAttributeValueAsInt(L"minRate");
					maxRate = xml->getAttributeValueAsInt(L"maxRate");

					minTime = xml->getAttributeValueAsFloat(L"minTime");
					maxTime = xml->getAttributeValueAsFloat(L"maxTime");

					minColor.setRed(xml->getAttributeValueAsInt(L"minColorR"));
					minColor.setGreen(xml->getAttributeValueAsInt(L"minColorG"));
					minColor.setBlue(xml->getAttributeValueAsInt(L"minColorB"));

					maxColor.setRed(xml->getAttributeValueAsInt(L"maxColorR"));
					maxColor.setGreen(xml->getAttributeValueAsInt(L"maxColorG"));
					maxColor.setBlue(xml->getAttributeValueAsInt(L"maxColorB"));
				}
				else if (nodeName.equals_ignore_case("sphereSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{					
					sphereRadius = xml->getAttributeValueAsFloat(L"radius");										
				}
				else if (nodeName.equals_ignore_case("boxSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{
					boxSize.MinEdge.X= xml->getAttributeValueAsFloat(L"minX");
					boxSize.MinEdge.Y = xml->getAttributeValueAsFloat(L"minY");
					boxSize.MinEdge.Z = xml->getAttributeValueAsFloat(L"minZ");

					boxSize.MaxEdge.X = xml->getAttributeValueAsFloat(L"maxX");
					boxSize.MaxEdge.Y = xml->getAttributeValueAsFloat(L"maxY");
					boxSize.MaxEdge.Z = xml->getAttributeValueAsFloat(L"maxZ");

				}
			}
		break;
		}
	}	
	delete xml;
}

ParticleSettings::~ParticleSettings()
{

}
