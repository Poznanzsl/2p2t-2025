#pragma once
#include <vector>
#include <raylib.h>


class Grid {
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool isCellEmpty(int row, int column);
	int grid[20][10];
	int ClearFullRows();
	bool isCellOutside(int row, int column);
private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	int NumCols;
	int NumRows;
	int CellSize;
	std::vector<Color> colors;
};
