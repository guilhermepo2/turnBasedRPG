#pragma once
#include "lib/BaseType.hpp"
#include "core/MoveCategory.hpp"
#include "core/MoveContest.hpp"
#include "core/MoveTypes.hpp"

class Move {
    public:
    uint16 m_id; // 1 - 728
    uint8 m_pp; // 0 - 40
    uint8 m_power; // 0 - 255
    uint8 m_accuracy; // 0 - 100
    uint8 m_generation; // 0 - 8
    eMoveCategory m_moveCategory;
    eMoveType m_moveType;
    eMoveContest m_moveContest;
    // these can be mapped to enum or ints actually
};