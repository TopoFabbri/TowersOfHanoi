#include "Stats.h"

Stats::Stats()
{
	moves = 0;
	time = 0;

	startTime = 0;
}

void Stats::update()
{
	time = static_cast<int>(GetTime()) - startTime;
}

void Stats::resetStats()
{
	moves = 0;
	time = 0;

	startTime = static_cast<int>(GetTime());
}

void Stats::setMoves(int newMoves)
{
	moves = newMoves;
}

int Stats::getTime()
{
	return time;
}

int Stats::getMoves()
{
	return moves;
}

void Stats::addPausedTime(int pausedTime)
{
	startTime += pausedTime;
}