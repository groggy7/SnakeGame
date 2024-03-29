#pragma once
#include "Board.h"
#include "Location.h"
#include "Snake.h"

#include <random>
class Obstacles
{
private:
	class Obstacle
	{
	public:
		void Draw(Board& brd);
		const Location& getLoc() const;
		void setLoc(const Location in_loc);
	private:
		Location loc;
		Color c = { 191, 32, 4 };
	};
public:
	Obstacles(Board& brd, Snake& snake);
	void Spawn();
	void Draw();
	bool eating(const Location next) const;
	int obsamount();
	void resetObsAmount();
private:
	int currentobstacles = 0;
	static constexpr int maxobstacles = 15;
	Obstacle obstacles[maxobstacles];
	Board& brd;
	Snake& snake;
	std::mt19937 rng;

};