#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/app/Event.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MyEventArgs {
public:
    explicit MyEventArgs(string name) : name(name) {}
    string name;
};

class EventExampleApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void keyDown( KeyEvent event );
    
    CallbackMgr<void (MyEventArgs*)> cb;
    void eventHandler(MyEventArgs *e);
    CallbackId callbackId;
};

void EventExampleApp::eventHandler(MyEventArgs *e) {
    console() << "eventHandler:" << e->name << endl;
}

void EventExampleApp::setup()
{
    auto func = std::bind(&EventExampleApp::eventHandler, std::ref(*this), std::placeholders::_1);
    callbackId = cb.registerCb(func);
    
    // if you want to unregister, call
    // cb.unregisterCb(callbackId);
}

int cnt = 0;
void EventExampleApp::keyDown(cinder::app::KeyEvent event)
{
    switch (event.getChar()) {
        case KeyEvent::KEY_RETURN:
        {
            MyEventArgs e("Test " + cinder::toString<int>(++cnt));
            cb.call(&e);
        }
            break;
            
        default:
            break;
    }
}

void EventExampleApp::update()
{
}

void EventExampleApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( EventExampleApp, RendererGl )
