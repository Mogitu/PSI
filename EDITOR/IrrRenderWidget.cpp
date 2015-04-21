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
}

IrrRenderWidget::~IrrRenderWidget()
{
    device->drop();
}

//setup the widget
void IrrRenderWidget::init()
{
    if (device != 0)
    {
        //create a new particle manager and setup the camera
        smgr = device->getSceneManager();
        particleSettings = new ParticleSettings(device);
        //smgr->addCameraSceneNode(0, core::vector3df(0, -50, -100), core::vector3df(0, 5, 0));
        camera  = new PreviewCamera(smgr);
        //this will hand control over to the game/render loop
        startTimer(0);
    }
}

void IrrRenderWidget::timerEvent(QTimerEvent* event)
{
    if(device != 0)
    {
        //render as usual with irrlicht
        device->getTimer()->tick();

        SColor color (0,0,0,0);

        device->getVideoDriver()->beginScene(true, true, color);

        device->getSceneManager()->drawAll();

        device->getVideoDriver()->endScene();
    }
}

//Handles resizing events
//TODO: make it work....
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
