#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DavidShaw_RoyalSocApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void mouseUp( MouseEvent event );	
	void update();
	void draw();
	float x1,x2,y1,y2;
	Node* sentinel;
};

void DavidShaw_RoyalSocApp::setup()

{
	sentinel = new Node();
}

void DavidShaw_RoyalSocApp::mouseDown( MouseEvent event )
{
	if(event.isLeft()) {
		x1 = (float(event.getX()));
		y1 = (float(event.getY()));
	}
}

void DavidShaw_RoyalSocApp::mouseUp( MouseEvent event ) 
{
	if(event.isLeft()) {
		x2 = (float(event.getX()));
		y2 = (float(event.getY()));
	}

	new Node(x1,y1,x2,y2,sentinel);

}


//starts at the end of the list, and works backwards drawing stuff.
void DavidShaw_RoyalSocApp::update()
{
	Node* cur = sentinel->prev_;
	while(cur!=sentinel) {
		gl::color(Color8u(255,127,00));
		gl::drawSolidRect(*(cur->rect_),false);
		cur = cur->prev_;
	}
}

void DavidShaw_RoyalSocApp::draw()
{
	
}

CINDER_APP_BASIC( DavidShaw_RoyalSocApp, RendererGl )
