#pragma once

class Point
{
	float x;
	float y;
public:
	Point(float,float);
	void move(float, float);
	void display();
	~Point();
};

