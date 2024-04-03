#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include <array>
#include <random>
#include <stack>
#include <vector>

#include "Cell.hpp"
#include "HumanPlayer.hpp"
#include "IMoveValidator.hpp"

class Labyrinth final : public IMoveValidator {
public:
    using CellMatrix = std::vector<std::vector<Cell>>;
    using UnvisitedNeighbours = std::vector<std::pair<size_t, size_t>>;
    using DirectionsPairs = std::vector<std::pair<int, int>>;

    bool canMove(int posX, int posY, int dx, int dy) const override;

    explicit Labyrinth(size_t rooms_);

    void generateViaDFS();

    void setRandomExit();

    void setBoardToDefaults();

    bool isExitReached(HumanPlayer &human);

    size_t getRooms() const {
        return rooms;
    }

    CellMatrix getLabyrinth() const {
        return labyrinth;
    }

    size_t getMatrixSize() const {
        return matrixSize;
    }

private:
    CellMatrix labyrinth{};
    DirectionsPairs directions;
    size_t rooms{};
    size_t matrixSize{};

    UnvisitedNeighbours getUnvisitedNeighbours(const size_t &curr_x, const size_t &curr_y);

    void carvePathBetweenTrees(const size_t &curr_x, const size_t &curr_y, const size_t next_x, const size_t next_y);

    size_t generateRandom(size_t start, size_t dest);
};

#endif
