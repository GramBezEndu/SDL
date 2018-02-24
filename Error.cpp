#include "Error.h"

FILE* Error::error=fopen("error.txt", "a");

///Check if file error was opened corretly
bool Error::check_error()
{
    if (!error)
    {
        perror("error.txt");
        printf("Could not create error file!\n");
        return false;
    }
    return true;
}
