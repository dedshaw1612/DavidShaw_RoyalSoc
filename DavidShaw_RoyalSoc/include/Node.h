#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Rect.h"

class Node : public cinder::RectT<int> {
public:
	Node(int x1,int y1, int x2, int y2);
	Node();

	//Info on any given Node that we would want. X,Y represent top left corner of the box
	int x,y,width,height;
	//will be implemented later from mousedragging
	void moveNode(int x1,int x2,int y1,int y2);
	void insertAfter(Node* after_Me,Node* new_Item);
	//void deleteMe(Node* delete_me);
	
	//Pointers to my siblings
	Node* next_;
	Node* prev_;
	RectT<float>* rect_;

	//Return true of the (x,y) provided is inside the Node
	bool isInside(float x, float y);
	void draw(ci::Vec2i mouse_pos);
	void update(ci::Vec2f parent_position, float parent_r);
	
};

void insertAfter(Node* new_item, Node* insert_here);