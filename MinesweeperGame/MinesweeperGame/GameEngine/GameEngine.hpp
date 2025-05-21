#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

class Graphics {
private:
	float screenHeight;
	float screenWidth;
public:
	//Constructor
	Graphics(float screenHeight, float screenWidth);
	//Set'er & Get'er functions
	float getScreenHeight() const;
	float setScreenHeight(float newScreenHeight);
	float getScreenWidth() const;
	float setScreenWidth(float newScreenWidth);
	//Defining Objects and Sprites functions (to draw)
	sf::Texture newTexture(std::string imageDir);
	sf::Sprite newSprite(sf::Texture texture);
	sf::CircleShape newCircle(float radius, sf::Color color);
	sf::RectangleShape newRect(float height, float width, sf::Color color);
	sf::ConvexShape newConvex(std::vector<sf::Vector2f> points, sf::Color color);
	sf::Vector2f setToCenterScreenCircle(sf::CircleShape shape);
	sf::Vector2f setToCenterScreenRect(sf::RectangleShape shape);
	sf::Vector2f setToCenterScreenConvex(sf::ConvexShape shape);
	//Text Related Functions
	sf::Font newFont(std::string fontDir);
	sf::Text newText(sf::Font& font, std::string displayText, sf::Color textColor, int characterSize = 30);
};

extern Graphics gameGraphics;