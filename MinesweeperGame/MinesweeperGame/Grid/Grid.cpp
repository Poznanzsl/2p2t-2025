#pragma once
#include "Grid.hpp"
#include "GameEngine.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <iomanip>

Grid::Grid(int newTilesX, int newTilesY, float newHeightSingularTile, float newWidthSingularTile, float newTileOutlineThickness) {
	srand(time(NULL));
	tilesX = newTilesX;
	tilesY = newTilesY;
	heightSingularTile = newHeightSingularTile;
	widthSingularTile = newWidthSingularTile;
	tileOutlineThickness = newTileOutlineThickness;
	for (int y = 0; y < tilesY;y++) {
		for (int x = 0; x < tilesX; x++) {
			int randomTile = rand() % 4;
			if (randomTile == 0) {
				grid[x][y] = tiles::Bomb;
			}
			else {
				grid[x][y] = tiles::Blank;
			}
		}
	}
}
void Grid::Draw(sf::RenderWindow& window) {
	float startX = 50.f;
	float startY = 50.f;
	float thickness = tileOutlineThickness;
	sf::Texture xTexture = gameGraphics.newTexture("Textures/x.png");

	for (int y = 0; y < tilesY; y++) {
		for (int x = 0; x < tilesX; x++) {
			sf::RectangleShape tile(sf::Vector2f(heightSingularTile, widthSingularTile));
			tile.setPosition(sf::Vector2f(startX + (x * widthSingularTile), startY + (y * heightSingularTile)));
			tile.setOutlineColor(sf::Color(99, 104, 121));

			//Colors Based on Tile Content
			if (grid[x][y] == tiles::Blank) {
				tile.setFillColor(sf::Color(174, 165, 180));
				sf::Sprite xIcon = gameGraphics.newSprite(xTexture);
				xIcon.setPosition(tile.getLocalBounds().width,tile.getLocalBounds().height);
				window.draw(xIcon);
			}
			else if (grid[x][y] == tiles::Bomb) {
				tile.setFillColor(sf::Color::Red);
			}

			tile.setOutlineThickness(thickness);
			window.draw(tile);
		}
	}
}

