#include "PreviewCamera.h"

PreviewCamera::PreviewCamera(){

}


PreviewCamera::PreviewCamera(irr::scene::ISceneManager *smgr):smgr(smgr){
    smgr->addCameraSceneNode(0, irr::core::vector3df(0, 0, -100));
    cameraNode = smgr->getActiveCamera();
    lookAt.set(cameraNode->getPosition());
    lookAt.Z+=500;
    cameraNode->setTarget(lookAt);
    //smgr->addCameraSceneNodeFPS(0, irr::core::vector3df(0, 0, -100));

}

PreviewCamera::~PreviewCamera(){
  cameraNode->drop();
}

void PreviewCamera::translate(f32 amount, vector3df axis){
    vector3df pos = cameraNode->getPosition();
    pos.X+=axis.X*amount;
    pos.Y+=axis.Y*amount;
    pos.Z+=axis.Z*amount;

    lookAt.X +=axis.X*amount;
   lookAt.Y +=axis.Y*amount;
     lookAt.Z +=axis.Z*amount;
    cameraNode->setPosition(pos);
    cameraNode->setTarget(lookAt);
}

ICameraSceneNode *PreviewCamera::getNode(){
    return cameraNode;
}

