// This header file maintains the data table for wall kick translations

#pragma once

#include <utility>


// Non-T_TYPE wall kicks
const std::pair<int, int> ZERO_CLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> ZERO_CLOCKWISE_2 = std::pair<int, int>(-1, 1);
const std::pair<int, int> ZERO_CLOCKWISE_3 = std::pair<int, int>(0, -2);
const std::pair<int, int> ZERO_CLOCKWISE_4 = std::pair<int, int>(-1, -2);

const std::pair<int, int> ONE_CLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> ONE_CLOCKWISE_2 = std::pair<int, int>(1, -1);
const std::pair<int, int> ONE_CLOCKWISE_3 = std::pair<int, int>(0, 2);
const std::pair<int, int> ONE_CLOCKWISE_4 = std::pair<int, int>(1, 2);

const std::pair<int, int> TWO_CLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> TWO_CLOCKWISE_2 = std::pair<int, int>(1, 1);
const std::pair<int, int> TWO_CLOCKWISE_3 = std::pair<int, int>(0, -2);
const std::pair<int, int> TWO_CLOCKWISE_4 = std::pair<int, int>(1, -2);

const std::pair<int, int> THREE_CLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> THREE_CLOCKWISE_2 = std::pair<int, int>(-1, -1);
const std::pair<int, int> THREE_CLOCKWISE_3 = std::pair<int, int>(0, 2);
const std::pair<int, int> THREE_CLOCKWISE_4 = std::pair<int, int>(-1, 2);

const std::pair<int, int> ZERO_COUNTERCLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> ZERO_COUNTERCLOCKWISE_2 = std::pair<int, int>(1, 1);
const std::pair<int, int> ZERO_COUNTERCLOCKWISE_3 = std::pair<int, int>(0, -2);
const std::pair<int, int> ZERO_COUNTERCLOCKWISE_4 = std::pair<int, int>(1, -2);

const std::pair<int, int> ONE_COUNTERCLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> ONE_COUNTERCLOCKWISE_2 = std::pair<int, int>(1, -1);
const std::pair<int, int> ONE_COUNTERCLOCKWISE_3 = std::pair<int, int>(0, 2);
const std::pair<int, int> ONE_COUNTERCLOCKWISE_4 = std::pair<int, int>(1, 2);

const std::pair<int, int> TWO_COUNTERCLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> TWO_COUNTERCLOCKWISE_2 = std::pair<int, int>(-1, 1);
const std::pair<int, int> TWO_COUNTERCLOCKWISE_3 = std::pair<int, int>(0, -2);
const std::pair<int, int> TWO_COUNTERCLOCKWISE_4 = std::pair<int, int>(-1, -2);

const std::pair<int, int> THREE_COUNTERCLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> THREE_COUNTERCLOCKWISE_2 = std::pair<int, int>(-1, -1);
const std::pair<int, int> THREE_COUNTERCLOCKWISE_3 = std::pair<int, int>(0, 2);
const std::pair<int, int> THREE_COUNTERCLOCKWISE_4 = std::pair<int, int>(-1, 2);


// I_TYPE wall kicks
const std::pair<int, int> I_ZERO_CLOCKWISE_1 = std::pair<int, int>(-2, 0);
const std::pair<int, int> I_ZERO_CLOCKWISE_2 = std::pair<int, int>(1, 0);
const std::pair<int, int> I_ZERO_CLOCKWISE_3 = std::pair<int, int>(-2, -1);
const std::pair<int, int> I_ZERO_CLOCKWISE_4 = std::pair<int, int>(1, 2);

const std::pair<int, int> I_ONE_CLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> I_ONE_CLOCKWISE_2 = std::pair<int, int>(2, 0);
const std::pair<int, int> I_ONE_CLOCKWISE_3 = std::pair<int, int>(-1, 2);
const std::pair<int, int> I_ONE_CLOCKWISE_4 = std::pair<int, int>(2, -1);

const std::pair<int, int> I_TWO_CLOCKWISE_1 = std::pair<int, int>(2, 0);
const std::pair<int, int> I_TWO_CLOCKWISE_2 = std::pair<int, int>(-1, 0);
const std::pair<int, int> I_TWO_CLOCKWISE_3 = std::pair<int, int>(2, 1);
const std::pair<int, int> I_TWO_CLOCKWISE_4 = std::pair<int, int>(-2, -2);

const std::pair<int, int> I_THREE_CLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> I_THREE_CLOCKWISE_2 = std::pair<int, int>(-2, 0);
const std::pair<int, int> I_THREE_CLOCKWISE_3 = std::pair<int, int>(1, -2);
const std::pair<int, int> I_THREE_CLOCKWISE_4 = std::pair<int, int>(-2, 1);

const std::pair<int, int> I_ZERO_COUNTERCLOCKWISE_1 = std::pair<int, int>(-1, 0);
const std::pair<int, int> I_ZERO_COUNTERCLOCKWISE_2 = std::pair<int, int>(2, 0);
const std::pair<int, int> I_ZERO_COUNTERCLOCKWISE_3 = std::pair<int, int>(-1, 2);
const std::pair<int, int> I_ZERO_COUNTERCLOCKWISE_4 = std::pair<int, int>(2, -1);

const std::pair<int, int> I_ONE_COUNTERCLOCKWISE_1 = std::pair<int, int>(2, 0);
const std::pair<int, int> I_ONE_COUNTERCLOCKWISE_2 = std::pair<int, int>(-1, 0);
const std::pair<int, int> I_ONE_COUNTERCLOCKWISE_3 = std::pair<int, int>(2, 1);
const std::pair<int, int> I_ONE_COUNTERCLOCKWISE_4 = std::pair<int, int>(-1, -2);

const std::pair<int, int> I_TWO_COUNTERCLOCKWISE_1 = std::pair<int, int>(1, 0);
const std::pair<int, int> I_TWO_COUNTERCLOCKWISE_2 = std::pair<int, int>(-2, 0);
const std::pair<int, int> I_TWO_COUNTERCLOCKWISE_3 = std::pair<int, int>(1, -2);
const std::pair<int, int> I_TWO_COUNTERCLOCKWISE_4 = std::pair<int, int>(-2, 1);

const std::pair<int, int> I_THREE_COUNTERCLOCKWISE_1 = std::pair<int, int>(-2, 0);
const std::pair<int, int> I_THREE_COUNTERCLOCKWISE_2 = std::pair<int, int>(1, 0);
const std::pair<int, int> I_THREE_COUNTERCLOCKWISE_3 = std::pair<int, int>(-2, -1);
const std::pair<int, int> I_THREE_COUNTERCLOCKWISE_4 = std::pair<int, int>(1, 2);