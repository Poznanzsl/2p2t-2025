#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

#include "GameEngine.hpp"

//SET AND GET FUNCTIONS FOR GAMEENGINE VAR's
Graphics::Graphics(float newScreenHeight, float newScreenWidth) {
		screenHeight = newScreenHeight;
		screenWidth = newScreenWidth;
}

float Graphics::getScreenHeight() const {
	return screenHeight;
}

float Graphics::setScreenHeight(float newScreenHeight) {
	screenHeight = newScreenHeight;
}

float Graphics::getScreenWidth() const {
	return screenWidth;
}

float Graphics::setScreenWidth(float newScreenWidth) {
	screenWidth = newScreenWidth;
}

sf::Texture Graphics::newTexture(std::string imageDir) {
	sf::Texture newTexture;
	if (!newTexture.loadFromFile(imageDir)) {
		std::cout << "Error: Texture has not been loaded!";
		return sf::Texture();
	}
	return newTexture;
}

//Textures and Images (Sprite Drawing!)
sf::Sprite Graphics::newSprite(sf::Texture texture) {
	sf::Sprite newSprite;
	sf::FloatRect bounds = newSprite.getLocalBounds();
	newSprite.setTexture(texture);
	newSprite.setOrigin(0.5f * bounds.height, 0.5f * bounds.width);
	return newSprite;
}

//INITIALIZE SHAPES (it places the origin at the center of each shape, and fills it with chosen color) :)
sf::CircleShape Graphics::newCircle(float radius,sf::Color color) {
	sf::CircleShape shape(radius);
	shape.setFillColor(color);
	shape.setOrigin(shape.getRadius(),shape.getRadius());
	return shape;
}
sf::RectangleShape Graphics::newRect(float height, float width, sf::Color color) {
	sf::RectangleShape shape(sf::Vector2f(height, width));
	shape.setFillColor(color);
	shape.setOrigin(0.5f * height, 0.5f * width);
	return shape;
	}
//points have to be in a convex order!!!
sf::ConvexShape Graphics::newConvex(std::vector<sf::Vector2f> points, sf::Color color) {
	sf::ConvexShape shape;
	shape.setFillColor(color);
	shape.setPointCount(points.size());
	int i = 0;
	float maxX = points[0].x;
	float minX = points[0].x;
	float maxY = points[0].y;
	float minY = points[0].y;
	float height = 0;
	float width = 0;

	for (sf::Vector2f point : points) {
		shape.setPoint(i, point);
		i++;
		if (point.x > maxX) {
			maxX = point.x;
		}
		if (point.x < minX) {
			minX = point.x;
		}
		if (point.y > maxY) {
			maxY = point.y;
		}
		if (point.y < minY) {
			minY = point.y;
		}
	}

	height = maxY - minY;
	width = maxX - minX;
	shape.setOrigin(0.5f * height, 0.5f * width);
	return shape;
	}

//CENTERED ON SCREEN
sf::Vector2f Graphics::setToCenterScreenCircle(sf::CircleShape shape) {		// Center a circle on screen
	float y = (0.5f * screenHeight);
	float x = (0.5f * screenWidth);
	sf::Vector2f CircleSize(x, y);
	return CircleSize;
}
sf::Vector2f Graphics::setToCenterScreenRect(sf::RectangleShape shape) {		// Center a circle on screen
	float y = (0.5f * screenHeight);
	float x = (0.5f * screenWidth);
	sf::Vector2f CircleSize(x, y);
	return CircleSize;
}
sf::Vector2f Graphics::setToCenterScreenConvex(sf::ConvexShape shape) {		// Center a circle on screen
	float y = (0.5f * screenHeight);
	float x = (0.5f * screenWidth);
	sf::Vector2f CircleSize(x, y);
	return CircleSize;
}
//TEXT RELATED FUNCTIONS
sf::Font Graphics::newFont(std::string fontDir) {
	sf::Font newFont;
	if (!newFont.loadFromFile(fontDir))
	{
		std::cout << "ERROR: Font has not loaded!" << std::endl;
		return sf::Font();
	}
	newFont.setSmooth(true);
	return newFont;
}
sf::Text Graphics::newText(sf::Font& font, std::string displayText, sf::Color textColor, int characterSize) {
	sf::Text newText(displayText, font,characterSize);
	sf::FloatRect bounds = newText.getLocalBounds();
	newText.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
	newText.setFillColor(textColor);
	return newText;
}
