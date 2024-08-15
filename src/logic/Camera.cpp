#include "Camera.hpp"

namespace Logic {
EntityDataMap Camera::getFullMap() { // GOD THIS IS SO UGLY I HATE IT, WHY IS THERE SO MUCH NESTING IM SORRY
    EntityDataMap fullMap;
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            if (auto tile = _level->getTile(i, j).lock()) {
                if (tile->isOccupied()) {
                    fullMap[i][j].type = tile->getEntityType();
                    if (tile->getEntityType() == EntityType::PACMAN) {
                        fullMap[i][j].name = CharacterName::Pacman; // I didnt know about the pointer cast, until now,
                                                                    // too lazy to change the code now
                        fullMap[i][j].direction =
                            std::static_pointer_cast<Pacman>(tile->getEntity().lock())->getDirection();
                    } else if (tile->getEntityType() == EntityType::GHOST) { // Here i didnt know, so i added the _name
                                                                             // variable to the Entity class lol
                        fullMap[i][j].name =
                            std::static_pointer_cast<Ghost>(tile->getEntity().lock())->getCharacterName();
                    }
                } else {
                    fullMap[i][j].type = EntityType::Empty;
                    fullMap[i][j].name = CharacterName::None;
                }
                fullMap[i][j].row = i;
                fullMap[i][j].col = j;
            }
        }
    }
    return fullMap;
}

OutputData Camera::getOutputData() {
    OutputData outputData;
    outputData.score = _level->getScore();
    outputData.lives = _level->getLives();
    return outputData;
}

} // Logic