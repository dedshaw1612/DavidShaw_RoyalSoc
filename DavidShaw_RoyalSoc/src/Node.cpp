#pragma once
//#include "cinder/gl/gl.h"
//#include "cinder/app/AppBasic.h"
//#include "cinder/Rand.h";
//#include "cinder/Rect.h"
#include "Node.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Node::Node(int x1 ,int y1, int x2, int y2) {
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
}

Node::Node() {
	this->prev_ = this;
	this->next_ = this;
}


void insertAfter(Node* after_Me, Node* new_Item){
	new_Item->next_ = after_Me->next_;
	new_Item->prev_ = after_Me;
	after_Me->next_->prev_ = new_Item;
	after_Me->next_ = new_Item;

}