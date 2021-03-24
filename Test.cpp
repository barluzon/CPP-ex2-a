#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Test empty board")
{
    Board board;
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == string(""));
    CHECK(board.read(1, 1, Direction::Vertical, 0) == string(""));
    CHECK(board.read(2, 2, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(3, 3, Direction::Vertical, 5) == string("_____"));
}


TEST_CASE("Test Horizontal")
{
    Board board;
    board.post(1, 2, Direction::Horizontal, "Checking");
    CHECK(board.read(1, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(1, 0, Direction::Horizontal, 3) == string("__C"));
    CHECK(board.read(1, 2, Direction::Horizontal, 4) == string("Chec"));
    CHECK(board.read(1, 6, Direction::Horizontal, 4) == string("king"));
    CHECK(board.read(1, 6, Direction::Horizontal, 5) == string("king_"));
    CHECK(board.read(1, 1, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(1, 2, Direction::Vertical, 2) == string("C_"));
    CHECK(board.read(0, 3, Direction::Vertical, 3) == string("_h_"));
    CHECK(board.read(1, 4, Direction::Vertical, 2) == string("e_"));
}

TEST_CASE("Test Vertical")
{
    Board board;
    board.post(1, 1, Direction::Vertical, " CPlusPlus");
    CHECK(board.read(1, 0, Direction::Horizontal, 2) == string("_C"));
    CHECK(board.read(2, 0, Direction::Horizontal, 3) == string("_P_"));
    CHECK(board.read(3, 1, Direction::Horizontal, 3) == string("l__"));
    CHECK(board.read(4, 0, Direction::Horizontal, 4) == string("_u__"));
    CHECK(board.read(4, 0, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(4, 1, Direction::Vertical, 3) == string("usP"));
    CHECK(board.read(4, 1, Direction::Vertical, 6) == string("usPlus"));
    CHECK(board.read(6, 1, Direction::Vertical, 5) == string("Plus_"));
}


TEST_CASE("Test - general")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "I");
    board.post(1, 1, Direction::Vertical, "t");
    board.post(2, 2, Direction::Horizontal, "'");
    board.post(3, 3, Direction::Vertical, "s");

    board.post(4, 4, Direction::Horizontal, "work");
    board.post(5, 4, Direction::Horizontal, "ing");
    board.post(6,4,Direction::Vertical,"ng");


    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("I_"));
    CHECK(board.read(1, 0, Direction::Horizontal, 2) == string("_t"));
    CHECK(board.read(0, 2, Direction::Vertical, 3) == string("__'"));
    CHECK(board.read(3, 2, Direction::Horizontal, 3) == string("_s_"));

    CHECK(board.read(4, 3, Direction::Horizontal, 6) == string("_work_"));
    CHECK(board.read(3, 4, Direction::Vertical, 3) == string("_wi"));
    CHECK(board.read(3, 5, Direction::Vertical, 4) == string("_on_"));
    CHECK(board.read(4, 4, Direction::Vertical, 5) == string("wing_"));
}