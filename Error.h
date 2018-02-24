#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <iostream>
#include <fstream>

class Error
{
    public:
        static FILE* error;
        static bool check_error();
    private:
        // Disallow creating an instance of this object
        Error();
};

#endif // ERROR_H_INCLUDED
