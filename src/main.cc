#include <iostream>

#include "block.h"
#include "blockchain.h"

int main() {
    std::cout << "BLOCKCHAIN" << std::endl;

    auto blockchain = Blockchain();
    auto b = Block(2, 10001, "DATA: 1", "");
    blockchain.addBlock(b);
    // blockchain.addBlock(Block{3, 10003, "DATA: 2", ""});

    for (auto block : blockchain.get_chain()) {
        std::cout << block.to_string() << std::endl;
    }

    return 0;
}