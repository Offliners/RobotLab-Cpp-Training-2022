#ifndef _FUNC_H_
#define _FUNC_H_

class McDonalds
{
    public:
        McDonalds(int, int);
        
        ~McDonalds();

    private:
        bool is_closed_ = false;
};

class LinkedList
{
    public:
        void PrintList();
        void Push_front(int x);
        void Push_back(int x);
        void Delete(int x);
        void Clear();
        void Reverse();
    
    private:
        ListNode *first = 0;
};

class ListNode
{
    friend class LinkedList;
    public:
        ListNode(int);

    private:
        int data = 0;
        ListNode *next = 0;
};

#endif