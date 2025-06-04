#include "colors.h"
#include <vector>

const Color darkGrey = { 34, 39, 37, 255 };
const Color green = { 47, 230, 23, 255 };
const Color red = { 232, 18, 18, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color yellow = { 237, 234, 4, 255 };
const Color purple = { 166, 0, 247, 255 };
const Color cyan = { 21, 204, 209, 255 };
const Color blue = { 13, 64, 216, 255 };
const Color lightBlue = { 59, 85, 162, 255 };
const Color darkBlue = { 44, 44, 127, 255 };
const Color background = { 18, 17 , 19, 255 };
const Color lightgreen = { 137, 152, 120 ,255 };
const Color beige = { 228 , 230, 195, 255 };
const Color white = { 247, 247, 242, 255 };

std::vector<Color> GetCellsColors() {
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue, lightBlue, darkBlue, background, lightgreen, beige, white };

}