#include "./headers/map.h"

std::vector<std::vector<Fields>> Map::mapToVector(std::string path) {
	Texture2D map;
	Image mapImage;

	mapImage = LoadImage(path.c_str());

	Color* pixels = LoadImageColors(mapImage);

	std::vector<std::vector<Fields>> arrMap;
	arrMap.resize(mapImage.height);

	for (int i = 0; i < mapImage.height; i++) {
		for (int j = 0; j < mapImage.width; j++) {
			if (pixels[i * mapImage.width + j].r == 255 && pixels[i * mapImage.width + j].g == 0 && pixels[i * mapImage.width + j].b == 0) {
				arrMap[i].push_back(Fields::FLOOR);
			}
			else {
				arrMap[i].push_back(Fields::EMPTY);
			}
		}
	}

	UnloadImage(mapImage);
	UnloadImageColors(pixels);

	return arrMap;
}

void Map::showMap(std::vector<std::vector<Fields>> &fieldMap) {
	for (int i = 0; i < fieldMap.size(); i++) {
		for (int j = 0; j < fieldMap[i].size(); j++) {
			switch (fieldMap[i][j]) {
			case (Fields::EMPTY):
				std::cout << 'E' << ' ';
				break;
			
			case (Fields::FLOOR):
				std::cout << '#' << ' ';
				break;
			}
		}
	}
}