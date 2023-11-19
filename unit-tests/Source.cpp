#include "FileManagementTree.h"
using namespace std;

int main()
{

   FileManagementTree filetree;
   filetree.UserCommandInterface(); /*
                                        This function will create a file structure and will provide user
                                        with a command interface to perform various operations on the
                                        file structure
                                    */
   filetree.deallocateMemory();

    return 0;
}