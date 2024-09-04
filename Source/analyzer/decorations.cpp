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
	glSeedTbl[4] = *Config.target;
	return level != 4;
}

bool ScannerDecorations::levelMatches(std::optional<uint32_t> levelSeed)
{
	if (levelSeed == std::nullopt)
		return false;

	for (int y = 1; y < DMAXY - 3; y++) {
		for (int x = 3; x < DMAXX - 4; x++) {
			if (dungeon[x][y] == 65) {
				bool hasCross = dungeon[x - 3][y + 3] == 107;
				bool hasRubble = dungeon[x + 4][y - 1] == 122;

				if (hasCross && hasRubble)
					std::cout << "(Level Seed,Decoration Seed): (" << *Config.target << "," << sgGameInitInfo.dwSeed << ")" << std::endl;

				return hasCross && hasRubble;
			}
		}
	}

	if (Config.verbose)
		std::cerr << "Couldn't find stairs (" << sgGameInitInfo.dwSeed << ")" << std::endl;

	return false;
}
