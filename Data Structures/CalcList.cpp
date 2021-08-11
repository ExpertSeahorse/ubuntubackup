#include <sstream>
#include <iomanip>

#include <iostream>

#include "CalcList.hpp"

using namespace std;


void CalcList::newOperation(const FUNCTIONS func, const double operand){
    // Append the empty operation to the list
    CalcNode* v = new CalcNode;
    v->next = head;
    
    // Fill Node
    v->old_t = t;
    v->operand = operand;
    if (head != NULL)
        v->ct = (head->ct) + 1;
    else
        v->ct = 1;

    // Do the calculation + fill in operator
    switch(func){
        case ADDITION:
            t += operand;
            v->op = '+';
            break;
        case SUBTRACTION:
            t -= operand;
            v->op = '-';
            break;
        case MULTIPLICATION:
            t *= operand;
            v->op = '*';
            break;
        case DIVISION:
            if (operand == 0)
                throw 1;
            t /= operand;
            v->op = '/';
            break;
    }

    // Fill Node with final total + replace head
    v->t = t;
    head = v;

}

void CalcList::removeLastOperation(){
    // If at end of list, break
    if (head == NULL)
        throw 1;

    // Copy the existing head
    CalcNode* dead_head = head; 
    
    // Supplant the existing head
    head = dead_head->next;

    // Revert the total
    t = dead_head->old_t;

    // Delete the old head
    delete dead_head;
}

string CalcList::toString(unsigned short precision) const{
    ostringstream out; 
    CalcNode* node = head;

    // Thru the string...
    while (node != NULL){
        // Get the elements out of each node
        out << fixed;
        out << node->ct << ": " << setprecision(precision) << node->old_t << node->op << node->operand << "=" << node->t << endl;

        // Get the next node
        node = node->next;
    }

    return out.str();
}

CalcList::CalcList(){
    // Basic initialization
    t = 0.0;
    head = NULL;
}

CalcList::~CalcList(){
    // Remove Nodes until there is only the NULL tail
    while(head != NULL)
        removeLastOperation();
}


bool SLinkedList::is_palindrome(){
    // set "end" to be the tail
    Node *end = head;
    while (end->next != NULL)
        ;

    Node *oldend = end;

    // set "start" to be the head
    Node *start = head;

    while (end != start){
        // check values if not palindrome
        if (start->value != end->value)
            break;
        
        // set new start
        start = start->next;

        // set new end
        end = head;
        while (end->next != oldend)
            end = end->next;
        oldend = end;
    }

    // Not a palindrome
    return false;
}

int CalcList::node_ct(Node* current){
    if (current->next == nullptr)
        return 1;
    else
        return 1 + node_ct(current->next);
}