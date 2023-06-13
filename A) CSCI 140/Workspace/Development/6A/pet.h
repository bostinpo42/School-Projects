#include <string>
#include <iostream>

#ifndef PET_H
#define PET_H

class Pet {
    friend std::ostream& operator<<(std::ostream&, const Pet&);
public:
    Pet(const std::string&, const std::string&); // set type and breed
    Pet(const std::string&, const std::string&, const std::string&); // set type, breed, and name

    virtual std::string speak() const = 0; // setting this virtual function to zero means that there cannot be 
                                           // a base case for the function, it can only be derived in other classes. Pet is now an abstract class. 
                                           // We can no longer make a Pet object, we can only make its derived classes Dog and Cat

    void operator=(const Pet&);

    std::string getType() const;
    std::string getName() const;
    std::string getBreed() const;

    void setType(const std::string&);
    void setBreed(const std::string&);
    void setName(const std::string&);
    
private:
    std::string type;
    std::string breed;
    std::string name;
};


#endif