#ifndef ROBOTWORLD_H
#define ROBOTWORLD_H

#include <iostream>

class RobotWorld {
	
	friend std::ostream& operator<<(ostream& out, const RobotWorld a);
	friend std::istream& operator>>(istream& inp, const RobotWorld a);
	void moveOnto(int a, int b);
	void moveOver(int a, int b);
	void pileOnto(int a, int b);
	void pileOver(int a, int b);
	
	private:
	int n;
	
	public:
	
	RobotWorld()
	: n(1)
	{
		
	}
	
	RobotWorld (int n);
};

#endif 