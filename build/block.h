#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
	Block();
	void Draw();
	void Move(int rows, int columns);
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();
	void DrawNextBlock();
	int id;
	int margin;
	int padding;
	std::map<int, std::vector<Position>> Cells;
private:
	int CellSize;
	int RotationState;
	std::vector<Color> colors;
	int rowOffset;
	int ColumnOffset;
};