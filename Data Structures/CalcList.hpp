#include "CalcListInterface.hpp"

class CalcNode{
    private:
        double old_t;
        char op;
        double operand;
        double t;
        int ct;

        CalcNode* next;

    friend class CalcList;
};

class CalcList : public CalcListInterface{
    private:
        double t;
        CalcNode* head;
    public:
        // Calculator Methods
        double total() const { return t; }
        void newOperation(const FUNCTIONS, const double);
        void removeLastOperation();
        std::string toString(unsigned short) const;

        // Class methods
        CalcList();
        ~CalcList();

        bool is_palindrome();
        int node_ct(CalcNode*);
};
