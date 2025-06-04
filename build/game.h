#pragma once
#include "Grid.h"
#include "blocks.cpp"
class Game {
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockLRight();
	void MoveBlockDown();
	void Run();
	Grid grid;
	bool GameOver;
	int score;
	void Reset();
	bool isFullScreenOn;
private:
	bool IsBlockOutside();

	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void UpdateScore(int linesCleared, int blockMovedDown);
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};