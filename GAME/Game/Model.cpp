#include "Model.h"

Model::Model(vector3df position) : Model(position, vector3df())
{
	
}

Model::Model(vector3df position, vector3df rotation) : Model(position, rotation, vector3df(1, 1, 1))
{

}

Model::Model(vector3df position, vector3df rotation, vector3df scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}