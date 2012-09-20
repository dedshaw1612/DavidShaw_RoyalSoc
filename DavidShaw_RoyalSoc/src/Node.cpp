#pragma once
//#include "cinder/gl/gl.h"
//#include "cinder/app/AppBasic.h"
//#include "cinder/Rand.h";
//#include "cinder/Rect.h"
#include "Node.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Node::Node(float x1 ,float y1, float x2, float y2,Node* sentinel) {
	this->rect_->x1=x1;
	this->rect_->x2=x2;
	this->rect_->y1=y1;
	this->rect_->y2=y2;
	this->next_=sentinel->next_;
	this->prev_=sentinel;
	sentinel->next_->prev_=this;
	sentinel->next_=this;
	
}

Node::Node() {
	this->prev_ = this;
	this->next_ = this;
}


//void insertAfter(Node* after_Me, Node* new_Item){
//	new_Item->next_ = after_Me->next_;
//	new_Item->prev_ = after_Me;
//	after_Me->next_->prev_ = new_Item;
//	after_Me->next_ = new_Item;
//
//}