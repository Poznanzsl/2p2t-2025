#include "game.h"
#include <random>
#include <iostream>

Game::Game() {
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	GameOver = false;
	score = 0;
	isFullScreenOn = false;
}

double lastUpdateTime = 0;

Font font = LoadFontEx("monogram.ttf", 64, 0, 0);

bool EventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

Block Game::GetRandomBlock() {
	srand(time(NULL));
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}


std::vector<Block> Game::GetAllBlocks() {
	return { Iblock(), Jblock(), Oblock(), Sblock(), Tblock(), Zblock() };
}
void Game::Draw() {
	grid.Draw();
	currentBlock.Draw();
}

void Game::HandleInput() {
	int keyPressed = GetKeyPressed();
	if (GameOver && keyPressed != 0) {
		GameOver = false;
		Reset();
	}
	switch (keyPressed) {
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockLRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}
void Game::MoveBlockLeft() {
	if (!GameOver) {
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, 1);
		}
	}
}
void Game::MoveBlockLRight() {
	if (!GameOver) {
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, -1);
		}
	}
}
void Game::MoveBlockDown() {
	if (!GameOver) {
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

void Game::Run() {
	HandleInput();
	if (EventTriggered(0.2)) {
		MoveBlockDown();
	}
	BeginDrawing();
	ClearBackground(background);
	DrawTextEx(font, "score", { 355,15 }, 38, 2, white);
	DrawTextEx(font, "Next", { 365,175 }, 38, 2, white);
	if (GameOver) {
		DrawTextEx(font, "Game Over", { 320,450 }, 38, 2, red);
		DrawTextEx(font, "Press any key", { 320,480 }, 20, 2, red);
		DrawTextEx(font, "to restart", { 320,500 }, 20, 2, red);
	}

	DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, darkGrey);

	char scoreText[10];
	sprintf(scoreText, "%d", score);
	Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

	DrawTextEx(font, scoreText, { 320 + (120 - textSize.x) / 2, 65 }, 38, 2, white);
	DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, darkGrey);
	nextBlock.DrawNextBlock();
	Draw();

	EndDrawing();
}

bool Game::IsBlockOutside() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.isCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::Reset() {
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::RotateBlock() {
	if (!GameOver) {
		currentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false) {
		GameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.isCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}
	return true;
}

void Game::UpdateScore(int linesCleared, int blockMovedDown) {
	switch (linesCleared) {
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	case 4:
		score += 1000;
		break;
	}
	score += blockMovedDown;
}
