#include "list.hpp"

int main()
{
    List<int> l1{2};

    
    l1.insert(2, 4, 1);
    l1.print_list();
    
    return 0;
}