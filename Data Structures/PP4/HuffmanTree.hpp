#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "HeapQueue.hpp"
#include "HuffmanBase.hpp"

#include <map>
#include <vector>


class HuffmanTree : HuffmanTreeBase{
    private:
    HuffmanNode tree;
    std::map<char, size_t> freq;
    HeapQueue<HuffmanNode, HuffmanNode::Compare> hq;
    std::map<char, std::string> encodings;
    void preOrderCompress(const HuffmanNode* n, std::string code);

    public:
    //~HuffmanTree();
    std::string compress(const std::string inputStr);   
    std::string serializeTree() const;
    std::string decompress(const std::string inputCode, const std::string serializedTree);
};

#endif /* HUFFMAN_H */