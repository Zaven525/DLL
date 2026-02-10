#include "list.hpp"

int main()
{
    List<int> l1{};
    List<int> l2(l1);
    l2.print_list();
    return 0;
}