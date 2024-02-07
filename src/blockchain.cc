#include "blockchain.h"


Blockchain::Blockchain() {
    this->chain.push_back(this->create_genesis());
}

Block Blockchain::create_genesis() const noexcept {
    return Block{0, 10000, "Genesis", "0"};
}

Block Blockchain::get_latest() const noexcept {
    return this->chain.back();
}

void Blockchain::addBlock(const Block& new_block) noexcept {
    auto block = std::move(new_block);
    block.set_index(this->chain.size());
    block.set_previous_hash(this->get_latest().get_hash());
    block.set_hash(new_block.digest());
    this->chain.push_back(block);
}

std::vector<Block> Blockchain::get_chain() const noexcept {
    return this->chain;
}
