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

	if (mouseInZone)
	{
		if (towerAttached->lastDisc() && !cursor->getHasDisk())
			towerAttached->lastDisc()->setSelected();
		else if (towerAttached->lastDisc())
			towerAttached->lastDisc()->quitSelected();

		if (cursor->getClick())
		{
			if (cursor->getHasDisk())
			{
				Disc* disc = cursor->dropDisc();

				if (!towerAttached->addDisc(disc))
					cursor->cancelMove(disc);
			}
			else if (towerAttached->lastDisc())
			{
				cursor->grabDisc(towerAttached->takeDisk());
			}
		}
	}
	else
	{
		if (towerAttached->lastDisc())
			towerAttached->lastDisc()->quitSelected();
	}
}