#include "PreviewCamera.h"

PreviewCamera::PreviewCamera(){

}


PreviewCamera::PreviewCamera(irr::scene::ISceneManager *smgr):smgr(smgr){
    smgr->addCameraSceneNode(0, irr::core::vector3df(0, -50, -100), irr::core::vector3df(0, 5, 0));
    cameraNode = smgr->getActiveCamera();
}

PreviewCamera::~PreviewCamera(){
  cameraNode->drop();
}
