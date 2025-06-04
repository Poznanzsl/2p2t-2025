#include "Grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid() {
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
	colors = GetCellsColors();
}

void Grid::Initialize() {
	for (int row = 0; row < NumRows; row++) {
		for (int col = 0; col < NumCols; col++) {
			grid[row][col] = 0;
		}
	}
}
void Grid::Print() {
	for (int row = 0; row < NumRows; row++) {
		for (int col = 0; col < NumCols; col++) {
			std::cout << grid[row][col] << " ";
		}
		std::cout << std::endl;
	}
}


void Grid::Draw() {
	int margin = 1;
	int padding = 10;
	for (int row = 0; row < NumRows; row++) {
		for (int col = 0; col < NumCols; col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * CellSize + margin + padding, row * CellSize + margin + padding, CellSize - margin, CellSize - margin, colors[cellValue]);
		}
	}
}

bool Grid::isCellEmpty(int row, int column) {
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows() {
	int completed = 0;
	for (int row = NumRows - 1; row >= 0; row--) {
		if (IsRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::isCellOutside(int row, int column) {
	if (row >= 0 && row < NumRows && column >= 0 && column < NumCols) {
		return false;
	}
	return true;
}

bool Grid::IsRowFull(int row) {
	for (int column = 0; column < NumCols; column++) {
		if (grid[row][column] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row) {
	for (int column = 0; column < NumCols; column++) {
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows) {
	for (int column = 0; column < NumCols; column++) {
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
