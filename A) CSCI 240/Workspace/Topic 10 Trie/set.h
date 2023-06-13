#ifndef SET
#define SET

template<typename T>
struct Set{
    //inserts an item into the set, returns false if it already exists
    virtual bool insert(const T&) = 0;

    virtual bool erase(const T&) = 0;

    virtual bool contains(const T&) const = 0;
};

#endif