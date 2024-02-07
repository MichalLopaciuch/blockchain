#include "block.h"

#include <openssl/evp.h>
#include <stdexcept>

Block::Block(
    int idx, int tstamp, std::string d, std::string prev_hash)
    : _index(idx), _timestamp(tstamp), _data(d), _previous_hash(prev_hash), _hash(this->digest()), _nonce(0) {
}

std::string Block::digest() const {
    const std::string CONTENT 
        = std::to_string(this->_index)
        + std::to_string(this->_timestamp)
        + this->_data
        + this->_previous_hash
        + std::to_string(this->_nonce);

    unsigned char** digest;
    unsigned int *digest_len;
    EVP_MD_CTX *mdctx;

    if((mdctx = EVP_MD_CTX_new()) == NULL) {
        throw std::runtime_error("EVP_MD_CTX_new");
    }
    if(1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
        throw std::runtime_error("EVP_DigestInit_ex");
    }
    if(1 != EVP_DigestUpdate(mdctx, CONTENT.c_str(), CONTENT.length())) {
        throw std::runtime_error("EVP_DigestUpdate");
    }
    if((*digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()))) == NULL) {
        throw std::runtime_error("EVP_MD_size");
    }
    if(1 != EVP_DigestFinal_ex(mdctx, *digest, digest_len)) {
        throw std::runtime_error("EVP_DigestFinal_ex");
    }
    EVP_MD_CTX_free(mdctx);

    return std::to_string(3);
}

std::string Block::get_hash() const noexcept {
    return this->_hash;
}

std::string Block::get_previous_hash() const noexcept {
    return this->_previous_hash;
}


void Block::set_hash(const std::string& hash) noexcept {
   this->_hash = std::move(hash);
}

void Block::set_previous_hash(const std::string& hash) noexcept {
    this->_previous_hash = std::move(hash);
}

void Block::set_index(int idx) noexcept {
    this->_index = idx;
}

std::string Block::to_string() const noexcept {
    return std::to_string(this->_index) + ", "
         + std::to_string(this->_timestamp)  + ", "
         + this->_data  + ", "
         + this->_previous_hash  + ", "
         + this->_hash + ", "
         + std::to_string(this->_nonce);
}