#pragma once
class Base
{
protected:
	bool active;

public:
	Base();
	virtual ~Base();

	virtual void start();
	virtual void update();
	virtual void draw();

	bool getActive();
};