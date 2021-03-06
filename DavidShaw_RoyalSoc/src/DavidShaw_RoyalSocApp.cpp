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
	void keyDown(KeyEvent event );	
	void mouseUp( MouseEvent event );	
	void update();
	void draw();
	float x1,x2,y1,y2;
	int blkCount;
	Node* sentinel;
	Node* grabbedSquare;
	bool grabFlag;
};

void DavidShaw_RoyalSocApp::setup()

{
	sentinel = new Node();
	blkCount = 250;
	grabFlag = false;
}

void DavidShaw_RoyalSocApp::keyDown(KeyEvent event) {
	if(event.getCode() == event.KEY_r) {
		Node* cur = sentinel;
		do {
			Node* temp = cur->next_;
			cur->next_ = cur->prev_;
			cur->prev_ = temp;
			cur = cur->prev_;
		}while(cur!=sentinel);
		/*
		Node* cur1 = sentinel->next_;
		Node* cur2 = sentinel->prev_;
		while((cur1!=cur2)&&(cur1->prev_!=cur2)&&(cur2->next_!=cur1)&&(cur2->next_!=cur2)) {
			Node* temp1 = new Node(cur1);
			Node* temp2 = new Node(cur2);
			cur1->next_->prev_=cur2;
			cur2->prev_->next_=cur1;
			cur1->prev_->next_=cur2;
			cur2->next_->prev_=cur1;
			cur1->next_=cur2->next_;
			cur1->prev_=cur2->prev_;
			cur2->next_=temp1->next_;
			cur2->prev_=temp1->prev_;

			cur1=temp1->next_;
			cur2=temp2->prev_;
			delete temp1;
			delete temp2;
		}*/
	}
}

void DavidShaw_RoyalSocApp::mouseDown( MouseEvent event )
{
	if(event.isLeft()) {
		

		x1 = (float(event.getX()));
		y1 = (float(event.getY()));
		Node* cur = sentinel->prev_;
		while(cur!=sentinel) {
			grabFlag = cur->isInside(x1,y1);
			if(grabFlag) {
				grabbedSquare=cur;
			}
			cur = cur->prev_;
		}

	}
	if(grabFlag){
		grabbedSquare->prev_->next_=grabbedSquare->next_;
		grabbedSquare->next_->prev_=grabbedSquare->prev_;
		grabbedSquare->next_=sentinel->next_;
		grabbedSquare->next_->prev_=grabbedSquare;
		grabbedSquare->prev_=sentinel;
		sentinel->next_=grabbedSquare;
	}
}

void DavidShaw_RoyalSocApp::mouseUp( MouseEvent event ) 
{
	if(event.isLeft()) {

		x2 = (float(event.getX()));
		y2 = (float(event.getY()));
	}

	if(!grabFlag){
		new Node(x1,y1,x2,y2,sentinel);
	}
	grabFlag = false;
	grabbedSquare = NULL;
}


//starts at the end of the list, and works backwards drawing stuff.
void DavidShaw_RoyalSocApp::update()
{
	Node* cur = sentinel->prev_;
	while(cur!=sentinel) {
		gl::color(Color8u(blkCount,blkCount,blkCount));
		gl::drawSolidRect(*(cur->rect_),false);
		cur = cur->prev_;
		blkCount -= 10;
	}
}

void DavidShaw_RoyalSocApp::draw()
{
	
}

CINDER_APP_BASIC( DavidShaw_RoyalSocApp, RendererGl )
