#include<cstddef>
#include<stdexcept>

#ifndef BIT_BUCKET_H
#define BIT_BUCKET_H

const static unsigned char masks[8] { 
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000
    };

template<size_t S>

class BitBucket{
public:
    void set(size_t pos) {
        if(pos >= S) throw std::range_error("Index out of range!");
        size_t bytePos{pos >> 3};
        size_t bitPos{pos - (bytePos << 3)};
        bucket[bytePos] |= masks[bitPos];
    }

    void unSet(size_t pos) {
        if(pos >= S) throw std::range_error("Index out of range!");
        size_t bytePos{pos >> 3};
        size_t bitPos{pos - (bytePos << 3)};
        bucket[bytePos] &= ~masks[bitPos];
    }

    bool at(size_t pos) {
        if(pos >= S) throw std::range_error("Index out of range!");
        size_t bytePos{pos >> 3};
        size_t bitPos{pos - (bytePos << 3)};
        return (1 << bitPos) & bucket[bytePos];
    }

    void clear() {
        size_t size{(S >> 3) + 1};
        for (size_t i = 0; i < size; ++i) {
            bucket[i] = 0;
        }
    }

private:
    unsigned char bucket[(S >> 3) + 1];
};

#endif