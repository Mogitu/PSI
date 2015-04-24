
//irrcorerenderer.h

#ifndef IRRRENDERWIDGET_H
#define IRRRENDERWIDGET_H

#include <QObject>
#include <QWidget>
#include "irrlicht.h"
#include "ParticleSettings.h"
#include "PreviewCamera.h"
#include <QMouseEvent>
#include <QDebug>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;

class IrrRenderWidget : public QWidget
{
    Q_OBJECT

public:
    IrrRenderWidget(QWidget *irrRenderTarget, bool softwareRenderer);
    ~IrrRenderWidget();
    void init();
    void resizeIrrWidget(int x, int y, int newWidth, int newHeight);   
    ParticleSettings* particleSettings;
    PreviewCamera *camera;

    bool mouseDown;
    QPoint pos;

private:
    QWidget *irrRenderTarget;
    E_DRIVER_TYPE rendererType;
    ISceneManager* smgr;


protected:
    SIrrlichtCreationParameters params;
    IrrlichtDevice* device;
    virtual void timerEvent(QTimerEvent* event);
  //  virtual void mousePressEvent(QMouseEvent* event);
//    virtual void wheelEvent(QWheelEvent* event);
   // virtual void keyPressEvent( QKeyEvent* event );
};

#endif
