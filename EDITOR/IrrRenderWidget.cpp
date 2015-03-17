

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

void IrrRenderWidget::exportToFile()
{
    IFileSystem *fs = device->getFileSystem();
    IXMLWriter *xml = fs->createXMLWriter("test.xml");

    stringw name="ddddd";
    stringw type;
    xml->writeXMLHeader();
    xml->writeElement(L"commonSettings",false, L"imagePath",name.c_str());
    xml->writeElement(L"commonSettings",false, L"ddddd",name.c_str());

                      /*
                                               L"\nscaleX", 1,L"scaleY",1,L"scaleZ",1,
                                               L"\nminStartSize",1,L"maxStartSize",1,
                                               L"\ntype",type.c_str(),
                                               L"\nduration",1,
                                               L"\ndirectionX",0,L"directionY",0,L"directionZ",0,
                                               L"\nminRate",100,L"maxRate",200,
                                               L"\nminTame",0.5,L"maxTime",0.9,
                                               L"\nminColorR",255,L"minColorG",255,L"minColorB",255,
                                               L"\nmaxColorR",255,L"maxColorG",255,L"maxColorB",255,L"",1);
                                        */

    xml->writeLineBreak();


}



void IrrRenderWidget::init()
{
    if (device != 0)
    {
        smgr = device->getSceneManager();
        particleManager = new ParticleManager(device);
        smgr->addCameraSceneNode(0, core::vector3df(0, -50, -100), core::vector3df(0, 5, 0));
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
