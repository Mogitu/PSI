#include "ParticleSettings.h"
#include <iostream>

using namespace std;

ParticleSettings::ParticleSettings(IrrlichtDevice *device, stringw file) :device(device), settingsFile(file)
{
	
	IFileSystem* fs = device->getFileSystem();
	IXMLReader* xml = fs->createXMLReader(settingsFile);
	stringc playerName = "Particle: ";
	stringc size = "Size: ";
	stringc color = "Color: ";
	stringc shape = "Shape: ";
	while (xml && xml->read())
	{
		switch (xml->getNodeType())
		{
		case EXN_ELEMENT:
		{
			stringc nodeName = xml->getNodeName();
			if (nodeName.equals_ignore_case("Particle"))
			{
				playerName.append(xml->getAttributeValue(L"name"));
				cout << playerName.c_str() << "\n";
			}
			else if (nodeName.equals_ignore_case("Size"))
			{
				xml->read();
				size.append(xml->getNodeData());
				cout << size.c_str() << "\n";
			}
			else if (nodeName.equals_ignore_case("Color"))
			{
				xml->read();
				color.append(xml->getNodeData());
				cout << color.c_str() << "\n";
			}
			else if (nodeName.equals_ignore_case("Shape"))
			{
				xml->read();
				shape.append(xml->getNodeData());
				cout << shape.c_str() << "\n";

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
