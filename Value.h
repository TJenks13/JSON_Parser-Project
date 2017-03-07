#ifndef VALUE_H
#define VALUE_H


class Value
{
    public:
        Value();
        virtual ~Value();
        //Pure virtual function to force usage in derived functions.
        virtual int weight() const = 0;
};

#endif // VALUE_H
