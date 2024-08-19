#include "decorations.h"

#include <iostream>

#include "../../types.h"

#include "../funkMapGen.h"
#include "../monster.h"

DungeonMode ScannerDecorations::getDungeonMode()
{
	return DungeonMode::NoContent;
}

bool ScannerDecorations::skipLevel(int level)
{
	return level != 4;
}

bool ScannerDecorations::levelMatches(std::optional<uint32_t> levelSeed)
{
	if (levelSeed == std::nullopt)
		return false;

	return dungeon[25][33] == 107
	    && dungeon[32][29] == 122;
}
