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
	void mouseDrag( MouseEvent event );	
	void update();
	void draw();
	Node* sentinel;
};

void DavidShaw_RoyalSocApp::setup()

{
	sentinel = new Node();
}

void DavidShaw_RoyalSocApp::mouseDown( MouseEvent event )
{
	if(event.isLeft()) {
		int x1 = event.getX();
		int x2 = event.getY();
	}

}

void DavidShaw_RoyalSocApp::update()
{
	Node* cur = sentinel->prev_;
	while(cur!=sentinel) {
		gl::drawSolidRect(*(cur->rect_),false);
		cur = cur->prev_;
	}
}

void DavidShaw_RoyalSocApp::draw()
{
	
}

CINDER_APP_BASIC( DavidShaw_RoyalSocApp, RendererGl )
