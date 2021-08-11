#include "HuffmanTree.hpp"
#include <iostream>

int main(){
    HuffmanTree h;
    std::string code, serial;
    code = h.compress("if a machine is expected to be infallible it cannot also be intelligent");
    serial = h.serializeTree();
    std::cout << code << std::endl;
    std::cout << serial << std::endl;
    std::cout << h.decompress(code, serial) << std::endl;
}