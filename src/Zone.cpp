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
		{
			Disc* disc = cursor->dropDisc();

			if (!towerAttached->addDisc(disc))
				cursor->grabDisc(disc);
		}
		else
		{
			cursor->grabDisc(towerAttached->takeDisk());
		}
	}
}