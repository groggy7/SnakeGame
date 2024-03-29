#include "Snake.h"

Snake::Snake(const Location loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(Location& delta_loc)
{
	for (int i = currentsegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < currentsegments; i++)
	{
		segments[i].Draw(brd);
	}
}

void Snake::Grow()
{
	++currentsegments;
	const Color colors[4] =
	{
		{ 57, 184, 91 },
		{ 42, 156, 72 },
		{ 24, 120, 49 },
		{ 41, 255, 152 }
	};
	Color bodycolor = colors[(currentsegments - 1) % 4];
	segments[currentsegments - 1].InitBody(bodycolor);
}

Location Snake::getNextHeadLoc(const Location& delta_loc) const
{
	Location l(segments[0].getLoc());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTile(const Location& next) const
{
	for(int i = 1; i < currentsegments; i++)
	{
		if (segments[i].getLoc() == next)
		{
			return true;
		}
	}
	return false;
}

void Snake::resetSnake(const Location loc)
{
	currentsegments = 1;
	segments[0].InitHead(loc);
}


void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::InitHead(const Location in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color colorcode)
{
	c = colorcode;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) <= 1);
	loc.Add(delta_loc);
}

Location Snake::Segment::getLoc() const
{
	return loc;
}
