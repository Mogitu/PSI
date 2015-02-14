//irrcorerenderer.cpp

#include "irrcorerenderer.h"

IrrCoreRenderer::IrrCoreRenderer(QWidget *irrRenderTarget, bool softwareRenderer)
{
    this->irrRenderTarget = irrRenderTarget;

    if(softwareRenderer)
    {
       this->rendererType = video::EDT_SOFTWARE;
    } else
    {
        this->rendererType = video::EDT_OPENGL;
    }

    //Set Parameters. Most important part here is: params.WindowId. This value sets the output destination of this Irrlicht instance.
    this->params.AntiAlias = 0;
    this->params.Bits = 32;
    this->params.DeviceType = EIDT_BEST;
    this->params.Doublebuffer = true;
    this->params.DriverType = rendererType;
    this->params.EventReceiver = 0;
    this->params.Fullscreen = false;
    this->params.HighPrecisionFPU = false;
    this->params.IgnoreInput = false;
    this->params.LoggingLevel = ELL_INFORMATION;
    this->params.Stencilbuffer = true;
    this->params.Stereobuffer = false;
    this->params.Vsync = false;
    this->params.WindowId = reinterpret_cast<void*>(this->irrRenderTarget->winId());
    this->params.WindowSize.Width = this->irrRenderTarget->size().width();
    this->params.WindowSize.Height = this->irrRenderTarget->size().height();
    this->params.WithAlphaChannel = false;
    this->params.ZBufferBits = 16;

    this->device = createDeviceEx(this->params);
}

IrrCoreRenderer::~IrrCoreRenderer()
{
    this->device->drop();
}

void IrrCoreRenderer::createParticle()
{
    particleNode = smgr->addParticleSystemSceneNode(false);

    particleEmitter = particleNode->createBoxEmitter(
                        core::aabbox3d<f32>(-7,0,-7,7,1,7),  // emitter size
                        core::vector3df(0.0f,0.06f,0.0f),    // initial direction
                        80,100,                              // emit rate
                        video::SColor(0,255,255,255),        // darkest color
                        video::SColor(0,255,255,255),        // brightest color
                        800,2000,20,                         // min and max age, angle
                        core::dimension2df(10.f,10.f),       // min size
                        core::dimension2df(20.f,20.f));      // max size

    particleNode->setEmitter(particleEmitter); // this grabs the emitter
    particleEmitter->drop(); // so we can drop it here without deleting it

    particleAffector =   particleNode->createFadeOutParticleAffector();

    particleNode->addAffector(particleAffector); // same goes for the affector
    particleAffector->drop();

    particleNode->setPosition(core::vector3df(0,0,0));
    particleNode->setScale(core::vector3df(0.5,0.5,0.5));
    particleNode->setMaterialFlag(video::EMF_LIGHTING, false);
    particleNode->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    particleNode->setMaterialTexture(0, this->device->getVideoDriver()->getTexture("fire.bmp"));
    particleNode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

void IrrCoreRenderer::deleteParticle()
{

   particleNode->clearParticles();


}

void IrrCoreRenderer::init()
{
    if (this->device != 0)
    {
        smgr = this->device->getSceneManager();
        smgr->addCameraSceneNode(0, core::vector3df(0, -50, -100), core::vector3df(0, 5, 0));
        startTimer(0);
    }
}

void IrrCoreRenderer::timerEvent(QTimerEvent* event)
{
    if(this->device != 0)
    {
        this->device->getTimer()->tick();

        video::SColor color (0,0,0,0);

        this->device->getVideoDriver()->beginScene(true, true, color);

        this->device->getSceneManager()->drawAll();

        this->device->getVideoDriver()->endScene();
    }
}

void IrrCoreRenderer::resizeIrrWidget(int x, int y, int newWidth, int newHeight)
{
    /*
    //Resize the render target widget which shows the Irrlicht output.
    this->irrRenderTarget->setGeometry(x, y, newWidth, newHeight);

    //Resize Irrlicht render output itself
    if(this->device != 0)
    {
        core::dimension2d<u32> widgetSize;
        widgetSize.Width = newWidth;
        widgetSize.Height = newHeight;

        this->device->getVideoDriver()->OnResize(widgetSize);

        scene::ICameraSceneNode *cam = this->device->getSceneManager()->getActiveCamera();
        if (cam != 0)
        {
            cam->setAspectRatio((f32)widgetSize.Width / (f32)widgetSize.Height);
        }
    }
    */
}
