#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint32_t a = 5;
    bitset<32> b(a);
    cout << b << endl;
    return 0;
}