#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Rect.h"

class Node {//: public cinder::RectT<int> {
public:
	Node(float x1,float y1, float x2, float y2,Node* sentinel);
	Node();

	//Info on any given Node that we would want. X,Y represent top left corner of the box
	//will be implemented later from mousedragging
	void moveNode(float x1,float x2,float y1,float y2);
	void insertAfter(Node* after_Me,Node* new_Item);
	//void deleteMe(Node* delete_me);
	
	//Pointers to my siblings
	Node* next_;
	Node* prev_;
	cinder::RectT<float>* rect_;

	//Return true of the (x,y) provided is inside the Node
	bool isInside(float x, float y);
	void draw(ci::Vec2i mouse_pos);
	void update(ci::Vec2f parent_position, float parent_r);
	
};

void insertAfter(Node* new_item, Node* insert_here);