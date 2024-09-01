#include "searchTree.cpp"
#include "pos.cpp"







int main(){

    searchTree::test();
    posistion::test();

    TEST_REPORT();
    if (total_tests - passed_tests != 0) exit(1);

    return 0;
}