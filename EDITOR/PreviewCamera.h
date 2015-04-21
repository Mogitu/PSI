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
 private:
   irr::scene::ISceneManager *smgr;
   irr::scene::ICameraSceneNode *cameraNode;
};

#endif // PREVIEWCAMERA

