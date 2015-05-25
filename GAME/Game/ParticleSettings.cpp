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
					
					duration = xml->getAttributeValueAsFloat(L"duration");
					
					direction.X = xml->getAttributeValueAsFloat(L"directionX");
					direction.Y = xml->getAttributeValueAsFloat(L"directionY");
					direction.Z = xml->getAttributeValueAsFloat(L"directionZ");			

					minRate = xml->getAttributeValueAsInt(L"minRate");
					maxRate = xml->getAttributeValueAsInt(L"maxRate");

					minTime = xml->getAttributeValueAsFloat(L"minTime") ;
					maxTime = xml->getAttributeValueAsFloat(L"maxTime") ;	

					minColor.setRed(xml->getAttributeValueAsInt(L"minColorR"));
					minColor.setGreen(xml->getAttributeValueAsInt(L"minColorG"));
					minColor.setBlue(xml->getAttributeValueAsInt(L"minColorB"));
					minColor.setAlpha(xml->getAttributeValueAsInt(L"minColorA"));
					maxColor.setRed(xml->getAttributeValueAsInt(L"maxColorR"));
					maxColor.setGreen(xml->getAttributeValueAsInt(L"maxColorG"));
					maxColor.setBlue(xml->getAttributeValueAsInt(L"maxColorB"));
					maxColor.setAlpha(xml->getAttributeValueAsInt(L"maxColorA"));				
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
				else if (nodeName.equals_ignore_case("cylinderSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{
					
					cylinderRadius = xml->getAttributeValueAsFloat(L"cylinderRadius");
					cylinderOutlineOnly = false;// etAttributeValueAsInt(L"cylinderOutlineOnly");					
				}
				else if (nodeName.equals_ignore_case("ringSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{
					ringRadius = xml->getAttributeValueAsFloat(L"ringRadius");
					ringThickness= xml->getAttributeValueAsFloat(L"ringThickness");
				}
				else if (nodeName.equals_ignore_case("pointSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{
					//no settings needed here as of yet....
				}
				else if (nodeName.equals_ignore_case("AffectorSettings") && xml->getAttributeValueAsInt(L"value") == 1)
				{
					//ScaleAffector
					if (xml->getAttributeValueAsInt(L"scale") == 1)
					{
						scaleAF = true;
						scale_scaleTo.Width = xml->getAttributeValueAsFloat(L"scale_scaleToWidth");
						scale_scaleTo.Height = xml->getAttributeValueAsFloat(L"scale_scaleToHeight");
					}
					//AttrectionAffector
					if (xml->getAttributeValueAsInt(L"attraction") == 1)
					{
						attraction = true;
						attraction_point.X = xml->getAttributeValueAsFloat(L"attraction_pointX");
						attraction_point.Y = xml->getAttributeValueAsFloat(L"attraction_pointY");
						attraction_point.Z = xml->getAttributeValueAsFloat(L"attraction_pointZ");
						attraction_speed = xml->getAttributeValueAsFloat(L"attraction_speed");
						attraction_attract = xml->getAttributeValueAsInt(L"attraction_attract");
						attraction_affectX = xml->getAttributeValueAsInt(L"attraction_affectX");
						attraction_affectY = xml->getAttributeValueAsInt(L"attraction_affectY");
						attraction_affectZ = xml->getAttributeValueAsInt(L"attraction_affectZ");
					}
					//FadeOutAffector
					if (xml->getAttributeValueAsInt(L"fade") == 1)
					{
						fade = true;
						fade_targetColor.setRed(xml->getAttributeValueAsInt(L"fade_targetColorR"));
						fade_targetColor.setGreen(xml->getAttributeValueAsInt(L"fade_targetColorG"));
						fade_targetColor.setBlue(xml->getAttributeValueAsInt(L"fade_targetColorB"));
						fade_targetColor.setAlpha(xml->getAttributeValueAsInt(L"fade_targetColorA"));
						fade_timeNeededToFadeOut = xml->getAttributeValueAsFloat(L"fade_timeNeededToFadeOut");
					}
					//Gravity
					if (xml->getAttributeValueAsInt(L"gravity") == 1)
					{
						gravity = true;
						gravity_gravity.X = xml->getAttributeValueAsFloat(L"gravity_gravityX");
						gravity_gravity.Y = xml->getAttributeValueAsFloat(L"gravity_gravityY");
						gravity_gravity.Z = xml->getAttributeValueAsFloat(L"gravity_gravityZ");
						gravity_timeForceLost = xml->getAttributeValueAsInt(L"fade_timeNeededToFadeOut");
					}
					//Rotation
					if (xml->getAttributeValueAsInt(L"rotation") == 1)
					{
						rotation = true;
						rotation_speed.X = xml->getAttributeValueAsFloat(L"rotation_speedX");
						rotation_speed.Y = xml->getAttributeValueAsFloat(L"rotation_speedY");
						rotation_speed.Z = xml->getAttributeValueAsFloat(L"rotation_speedZ");
						rotation_pivotPoint.X = xml->getAttributeValueAsFloat(L"rotation_pivotPointX");
						rotation_pivotPoint.Y = xml->getAttributeValueAsFloat(L"rotation_pivotPointY");
						rotation_pivotPoint.Z = xml->getAttributeValueAsFloat(L"rotation_pivotPointZ");
					}
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
