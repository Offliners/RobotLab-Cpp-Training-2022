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

class Counter
{
    public:
        Counter();
        ~Counter();
    
    private:
};

#endif