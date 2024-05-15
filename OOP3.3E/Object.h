#pragma once
class Object
{
private:
	static int i;

public:
	Object() { i++; }
	static int getI() { return i; };
};

