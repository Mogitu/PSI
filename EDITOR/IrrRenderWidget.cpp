

#include "IrrRenderWidget.h"

IrrRenderWidget::IrrRenderWidget(QWidget *irrRenderTarget, bool softwareRenderer)
{
    irrRenderTarget = irrRenderTarget;

    if(softwareRenderer)
    {
       rendererType = video::EDT_SOFTWARE;
    } else
    {
        rendererType = video::EDT_OPENGL;
    }

    //Set Parameters. Most important part here is: params.WindowId. This value sets the output destination of this Irrlicht instance.
    params.AntiAlias = 0;
    params.Bits = 32;
    params.DeviceType = EIDT_WIN32;
    params.Doublebuffer = true;
    params.DriverType = rendererType;
    params.EventReceiver = 0;
    params.Fullscreen = false;
    params.HighPrecisionFPU = false;
    params.IgnoreInput = false;
    params.LoggingLevel = ELL_INFORMATION;
    params.Stencilbuffer = true;
    params.Stereobuffer = false;
    params.Vsync = false;
    params.WindowId = reinterpret_cast<void*>(irrRenderTarget->winId());
    params.WindowSize.Width = irrRenderTarget->size().width();
    params.WindowSize.Height = irrRenderTarget->size().height();
    params.WithAlphaChannel = false;
    params.ZBufferBits = 16;

    device = createDeviceEx(params);

    minScale= 1.0;
    maxScale =1.0;

    bright = new vector3di(255.0,255.0,255.0);
    dark = new vector3di(255.0,25.05,255.0);



}

IrrRenderWidget::~IrrRenderWidget()
{
    delete bright;
    delete dark;
    particleNode->drop();
    device->drop();
}

void IrrRenderWidget::createParticle()
{

    particleNode = smgr->addParticleSystemSceneNode(false);

    particleEmitter = particleNode->createBoxEmitter(
                        aabbox3d<f32>(-7,0,-7,7,1,7),  // emitter size
                        vector3df(0.0f,0.06f,0.0f),    // initial direction
                        80,100,                              // emit rate
                        SColor(0,dark->X,dark->Y,dark->Z),        // darkest color
                        SColor(0,bright->X,bright->Y,bright->Z),        // brightest color
                        800,2000,20,                         // min and max age, angle
                       //core::dimension2df(10.f,10.f),       // min size
                        dimension2df(minScale,minScale),
                        dimension2df(maxScale, maxScale));      // max size


    particleNode->setEmitter(particleEmitter); // this grabs the emitter
    particleEmitter->drop(); // so we can drop it here without deleting it

    particleAffector =   particleNode->createFadeOutParticleAffector();

    particleNode->addAffector(particleAffector); // same goes for the affector
    particleAffector->drop();

    particleNode->setPosition(vector3df(0,0,0));
    particleNode->setScale(vector3df(0.5,0.5,0.5));
    particleNode->setMaterialFlag(EMF_LIGHTING, false);
    particleNode->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    particleNode->setMaterialTexture(0, device->getVideoDriver()->getTexture("fire.bmp"));
    particleNode->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}


void IrrRenderWidget::createEmitter()
{
    particleNode->clearParticles();
    particleEmitter = particleNode->createBoxEmitter(
                aabbox3d<f32>(-7,0,-7,7,1,7),  // emitter size
                vector3df(0.0f,0.06f,0.0f),    // initial direction
                80,100,                              // emit rate
                SColor(0,255,255,255),        // darkest color
                SColor(0,bright->X,bright->Y,bright->Z),        // brightest color
                800,2000,20,                         // min and max age, angle
               //core::dimension2df(10.f,10.f),       // min size
                dimension2df(minScale,minScale),
                dimension2df(maxScale, maxScale));      // max size

    particleNode->setEmitter(particleEmitter);
}

void IrrRenderWidget::init()
{
    if (device != 0)
    {
        smgr = device->getSceneManager();
        smgr->addCameraSceneNode(0, core::vector3df(0, -50, -100), core::vector3df(0, 5, 0));
        createParticle();
        startTimer(0);
    }
}

void IrrRenderWidget::timerEvent(QTimerEvent* event)
{
    if(device != 0)
    {
        device->getTimer()->tick();

        SColor color (0,0,0,0);

        device->getVideoDriver()->beginScene(true, true, color);

        device->getSceneManager()->drawAll();

        device->getVideoDriver()->endScene();
    }
}

void IrrRenderWidget::resizeIrrWidget(int x, int y, int newWidth, int newHeight)
{
    /*
    //Resize the render target widget which shows the Irrlicht output.
    irrRenderTarget->setGeometry(x, y, newWidth, newHeight);

    //Resize Irrlicht render output itself
    if(device != 0)
    {
        dimension2d<u32> widgetSize;
        widgetSize.Width = newWidth;
        widgetSize.Height = newHeight;

        device->getVideoDriver()->OnResize(widgetSize);

        ICameraSceneNode *cam = device->getSceneManager()->getActiveCamera();
        if (cam != 0)
        {
            cam->setAspectRatio((f32)widgetSize.Width / (f32)widgetSize.Height);
        }
    }
    */
}
