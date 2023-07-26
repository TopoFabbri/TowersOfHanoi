#include "Zone.h"

Zone::Zone(Tower* tower, Rectangle newRec, Cursor* newCursor)
{
	towerAttached = tower;
	mouseInZone = false;
	rec = newRec;
	cursor = newCursor;
}

void Zone::update()
{
	mouseInZone = CheckCollisionPointRec(cursor->getPos(), rec);

	if (cursor->getClick() && mouseInZone)
	{
		if (cursor->getHasDisk())
			towerAttached->addDisc(cursor->dropDisc());
		else
			cursor->grabDisc(towerAttached->takeDisk());
	}
}