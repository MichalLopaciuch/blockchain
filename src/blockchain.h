#pragma once

#include "block.h"

#include <vector>


class Blockchain {
public:
    void addBlock(const Block&) noexcept;
    std::vector<Block> get_chain() const noexcept;

    Blockchain();
    ~Blockchain() = default;
private:
    std::vector<Block> chain;

    [[nodiscard]] Block create_genesis() const noexcept;
    [[nodiscard]] Block get_latest() const noexcept;
};
