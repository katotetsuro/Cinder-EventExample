#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EventExampleApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void EventExampleApp::setup()
{
}

void EventExampleApp::mouseDown( MouseEvent event )
{
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
