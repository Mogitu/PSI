#ifndef PREVIEWCAMERA_H
#define PREVIEWCAMERA_H

#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;

class PreviewCamera{
 public:
   PreviewCamera();
   ~PreviewCamera();
    PreviewCamera(irr::scene::ISceneManager *smgr);
    ICameraSceneNode *getNode();
    void translate(f32 amount, vector3df axis);
 private:
   irr::scene::ISceneManager *smgr;
   irr::scene::ICameraSceneNode *cameraNode;
   vector3df lookAt;
};

#endif // PREVIEWCAMERA

