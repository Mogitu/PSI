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
			
			if (nodeName.equals_ignore_case("minStartSize"))
			{
				xml->read();
				minStartSize = xml->getAttributeValueAsInt(L"value");
			}
			else if (nodeName.equals_ignore_case("maxStartSize"))
			{
				xml->read();
				maxStartSize = xml->getAttributeValueAsInt(L"value");
			}	
			else if (nodeName.equals_ignore_case("duration"))
			{
				xml->read();
				duration = xml->getAttributeValueAsInt(L"value") * 1000;//multiplier transforms ms to s;
			}
		}
		break;
		}
	}
	cout << endl;
	delete xml;
}

ParticleSettings::~ParticleSettings()
{

}
