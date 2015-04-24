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
    params.WindowId = (void*)irrRenderTarget->winId();
    params.WindowSize.Width = irrRenderTarget->size().width();
    params.WindowSize.Height = irrRenderTarget->size().height();
    params.WithAlphaChannel = false;
    params.ZBufferBits = 16;

    device = createDeviceEx(params);
   // this->setMouseTracking(true);
   // this->grabMouse();

    //this->grabKeyboard();
   // this->setEnabled(true);

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
/*
void IrrRenderWidget::mousePressEvent(QMouseEvent *event){
    irr::SEvent irrEvent;

       irrEvent.EventType = irr::EET_MOUSE_INPUT_EVENT;

       switch ( event->button() )
       {
       case Qt::LeftButton:
           //irrEvent.MouseInput.Event = pressedDown? irr::EMIE_LMOUSE_PRESSED_DOWN:irr::EMIE_LMOUSE_LEFT_UP;
           break;

       case Qt::MidButton:
          // irrEvent.MouseInput.Event = pressedDown? irr::EMIE_MMOUSE_PRESSED_DOWN:irr::EMIE_MMOUSE_LEFT_UP;
           break;

       case Qt::RightButton:
         //  irrEvent.MouseInput.Event = pressedDown? irr::EMIE_RMOUSE_PRESSED_DOWN:irr::EMIE_RMOUSE_LEFT_UP;
           break;

       default:
           return; // Cannot handle this mouse event
       }

       irrEvent.MouseInput.X = event->x();
       irrEvent.MouseInput.Y = event->y();
       irrEvent.MouseInput.Wheel = 0.0f; // Zero is better than undefined

       device->postEventFromUser( irrEvent );
}

void IrrRenderWidget::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"fdsfdsfds";
    camera->getNode()->setPosition(vector3df(0,1000,0));
}

void IrrRenderWidget::keyPressEvent(QKeyEvent *event)
{

    IParticleSystemSceneNode *node = particleSettings->getParticleNode();
    vector3df forward = node->getRotation().rotationToDirection();
    vector3df up(0,1,0);
    vector3df right(forward.crossProduct(up).normalize());
    vector3df oldRot = node->getRotation();
    vector3df newRot;
    switch(event->key())
    {
     case KEY_KEY_W:
          node->setPosition(node->getPosition()+node->getRotation().rotationToDirection()*2);
        break;
     case KEY_KEY_S:
          node->setPosition(node->getPosition()+node->getRotation().rotationToDirection()*-2);
        break;
     case KEY_KEY_D:
        node->setPosition(node->getPosition()+right*2);
        break;
    case KEY_KEY_A:
       node->setPosition(node->getPosition()+right*-2);
       break;
    case KEY_KEY_Q:
       oldRot.X+=1;
       node->setRotation(oldRot);
       break;
    }

    event->accept();
}
*/
