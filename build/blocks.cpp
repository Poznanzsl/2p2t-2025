#include "block.h"
#include "position.h"

class Lblock : public Block {
public:
	Lblock() {
		id = 1;
		Cells[0] = { Position(0,2),Position(1,0),Position(1,1),Position(1,2) };
		Cells[1] = { Position(0,1),Position(1,1),Position(2,1),Position(2,2) };
		Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,0) };
		Cells[3] = { Position(0,0),Position(0,1),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};

class Jblock : public Block {
public:
	Jblock() {
		id = 2;
		Cells[0] = { Position(0,0),Position(1,0),Position(1,1),Position(1,2) };
		Cells[1] = { Position(0,1),Position(0,2),Position(1,1),Position(2,1) };
		Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,2) };
		Cells[3] = { Position(0,0),Position(1,0),Position(2,0),Position(2,1) };
		Move(0, 3);
	}
};

class Iblock : public Block {
public:
	Iblock() {
		id = 3;
		Cells[0] = { Position(1,0),Position(1,1),Position(1,2),Position(1,3) };
		Cells[1] = { Position(0,2),Position(1,2),Position(2,2),Position(3,2) };
		Cells[2] = { Position(2,0),Position(2,1),Position(2,2),Position(2,3) };
		Cells[3] = { Position(0,1),Position(1,1),Position(2,1),Position(3,1) };
		Move(-1, 3);
	}
};

class Oblock : public Block {
public:
	Oblock() {
		id = 4;
		Cells[0] = { Position(0,0),Position(0,1),Position(1,0),Position(1,1) };
		Move(0, 4);
	}
};

class Sblock : public Block {
public:
	Sblock() {
		id = 5;
		Cells[0] = { Position(0,1),Position(0,2),Position(1,0),Position(1,1) };
		Cells[1] = { Position(0,1),Position(1,1),Position(1,2),Position(2,2) };
		Cells[2] = { Position(1,1),Position(1,2),Position(2,0),Position(2,1) };
		Cells[3] = { Position(0,0),Position(1,0),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};

class Tblock : public Block {
public:
	Tblock() {
		id = 6;
		Cells[0] = { Position(0,1),Position(1,0),Position(1,1),Position(1,2) };
		Cells[1] = { Position(0,1),Position(1,1),Position(1,2),Position(2,1) };
		Cells[2] = { Position(1,0),Position(1,1),Position(1,2),Position(2,1) };
		Cells[3] = { Position(0,1),Position(1,0),Position(1,1),Position(2,1) };
		Move(0, 3);
	}
};

class Zblock : public Block {
public:
	Zblock() {
		id = 7;
		Cells[0] = { Position(0,0),Position(0,1),Position(1,1),Position(1,2) };
		Cells[1] = { Position(0,2),Position(1,1),Position(1,2),Position(2,1) };
		Cells[2] = { Position(1,0),Position(1,1),Position(2,1),Position(2,2) };
		Cells[3] = { Position(0,1),Position(1,0),Position(1,1),Position(2,0) };
		Move(0, 3);
	}
};