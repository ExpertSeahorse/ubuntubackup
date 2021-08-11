#include <sstream>
#include <stack>

#include "HuffmanTree.hpp"

void printBT(const std::string& prefix, const HuffmanNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->getCharacter() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const HuffmanNode* node){
    printBT(" ", node, false);
}

void HuffmanTree::preOrderCompress(const HuffmanNode* n, std::string code){
    // visit node
    if (n->isLeaf()){
        //std::cout << n->getCharacter() << " = " << code << std::endl;
        encodings[n->getCharacter()] = code;
    }
    // visit children and extend encoding
    else{
        //std::cout << "Code: " << code <<std::endl;
        std::ostringstream s;
        if (n->left != nullptr){
            s << code << '0';
            preOrderCompress(n->left, s.str());
            s.str(std::string());   // Clear stream
        }
        if (n->right != nullptr){
            s << code << '1';
            preOrderCompress(n->right, s.str());
            s.str(std::string());   // Clear stream
        }
    }
}

std::string postOrderSerialize(const HuffmanNode* n){
    std::ostringstream s;

    bool left=false, right=false;
    if (n->left != nullptr)
        left=true;
        //return postOrderSerialize(n->left)
    if (n->right != nullptr)
        right=true;
        //return postOrderSerialize(n->right)
    
    
    if (n->isLeaf())
        s << 'L' << n->getCharacter();
    else if (left && right)
        s << postOrderSerialize(n->left) << postOrderSerialize(n->right) << "B";
    return s.str();
}

/*
//This doesnt work?
void destroyNode(HuffmanNode* n){
    if (n->left != nullptr)
        destroyNode(n->left);
    if (n->right != nullptr)
        destroyNode(n->right);
    delete n;
}
*/

std::string HuffmanTree::compress(const std::string inputStr){
    // Build frequency map of the string
    for(char ch : inputStr){
        if (!freq.count(ch))
            freq[ch] = 1;
        else
            freq[ch] += 1;
    }

    // move each char/freq pair into HuffNodes in the priority queue
    for(auto const& x : freq)
        hq.insert(HuffmanNode(x.first, x.second));

    // Use the priority queue to consolidate all the char/freq pairs into sorted order
    // while there is more than 1 tree in the priority queue:
    HuffmanNode temp;
    while(hq.size() != 1){
        // Get min 2 trees
        temp = hq.min();
        HuffmanNode* left = new HuffmanNode(temp);
        hq.removeMin();

        temp = hq.min();
        HuffmanNode* right = new HuffmanNode(temp);
        hq.removeMin();

        // Create new tree with prev trees as children and insert to priority queue
        size_t new_freq = left->getFrequency() + right->getFrequency();

        HuffmanNode tree = HuffmanNode('\0', new_freq, nullptr, left, right);
        left->parent = &tree;
        right->parent = &tree;

        hq.insert(tree);
    }

    tree = hq.min();
    //printBT(&tree);

    // With the finished tree, get char encodings + put into map
    preOrderCompress(&tree, "");

    // Replace all characters with their encodings
    std::ostringstream s;
    for(auto ch : inputStr){
        s << encodings[ch];
    }
    
    return s.str();
}

std::string HuffmanTree::serializeTree() const{
    return postOrderSerialize(&tree);
}

std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree){
    // Build decoding tree
    std::stack<HuffmanNode> st;
    HuffmanNode temp;
    for (size_t i=0; i<serializedTree.size(); i++){
        char pos = serializedTree.at(i);
        if (pos == 'L'){
            st.emplace(serializedTree.at(++i), 0);
        }
        else if (pos == 'B'){
            // Get top 2 trees
            temp = st.top();
            HuffmanNode* right = new HuffmanNode(temp);
            st.pop();

            temp = st.top();
            HuffmanNode* left = new HuffmanNode(temp);
            st.pop();

            // Make tree of prev trees + push to stack
            HuffmanNode tree = HuffmanNode('\0', 0, nullptr, left, right);
            left->parent = &tree;
            right->parent = &tree;
            st.push(tree);
        }
        else{
            throw 1;
        }
        
    }

    // Decode tree is built
    HuffmanNode tree = st.top();

    // Decode binary by using bits to move thru tree
    HuffmanNode current = tree;
    std::ostringstream s;
    for (char bit : inputCode){
        if (bit == '1')
            current = *current.right;
        else if (bit == '0')
            current = *current.left;
        else
            throw 2;
        
        if (current.isLeaf()){
            s << current.getCharacter();
            current = tree;
        }
    }
    return s.str();
}
/*
HuffmanTree::~HuffmanTree(){
    destroyNode(&tree);
}
*/