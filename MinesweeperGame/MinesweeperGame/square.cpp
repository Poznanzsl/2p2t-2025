#pragma once 

class square {
private:
	float height;
	float width;
public:
	square(float new_height, float new_width) {
		height = new_height;
		width = new_width;
	}
	float getHeight() {
		return height;
	}
	float getWidth() {
		return width;
	}
};