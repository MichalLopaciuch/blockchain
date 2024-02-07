#include <iostream>

#include "block.h"
#include "blockchain.h"

int main() {
    std::cout << "BLOCKCHAIN" << std::endl;

    auto blockchain = Blockchain();

    blockchain.add_block(Block{1001, "DATA: 1"});
    blockchain.add_block(Block{1002, "DATA: 2"});
    blockchain.add_block(Block{1003, "DATA: 3"});
    blockchain.add_block(Block{1003, "DATA: 3"});

    for (auto block : blockchain.get_chain()) {
        std::cout << block.to_string() << std::endl;
    }

    return 0;
}
