#pragma once

#include <string>

class Block {
public:
    [[nodiscard]] std::string get_previous_hash() const noexcept;
    [[nodiscard]] std::string get_hash() const noexcept;
    void set_previous_hash(const std::string&) noexcept;
    void set_hash(const std::string&) noexcept;
    void set_index(int) noexcept;
    [[nodiscard]] std::string digest() const;
    [[nodiscard]] std::string to_string() const noexcept;

    Block(int, std::string);
    Block(int, int, std::string, std::string);
    ~Block() = default;
private:
    int _index;
    int _timestamp;
    std::string _data;
    std::string _previous_hash;
    std::string _hash;
    int _nonce;
};
