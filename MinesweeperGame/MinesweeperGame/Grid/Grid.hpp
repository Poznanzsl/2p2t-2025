#pragma once
#include <SFML\Graphics.hpp>

enum class tiles {
	Blank,
	Bomb
};

class Grid {
private:
	tiles grid[20][20];
	int tilesX;
	int tilesY;
	float heightSingularTile;
	float widthSingularTile;
	float tileOutlineThickness;
public:
	Grid(int newTilesX, int newTilesY, float newHeightSingularTile, float newWidthSingularTile, float newTileOutlineThickness);
	void Draw(sf::RenderWindow& window);
};

extern Grid gameGrid;