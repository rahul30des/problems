#include <bitset>
#include <iostream>

using namespace std;

int main() {
    // Initialize a bitset with 8 bits.
    bitset<8> b;

    // Set the 3rd and 5th bits.
    b.set(2);
    b.set(4);
    cout<<"Set the third[2] and the fifth bit[4]"<<endl;

    // Check if the 3rd bit is set.
    bool isBitSet = b.test(2);
    cout << "Is the 3rd bit set? " << boolalpha << isBitSet << std::endl;

    // Display the entire bitset.
    cout << "Bitset: " << b << std::endl;

    // Reset the 5th bit.
    b.reset(4);

    cout << "Bitset after reset of 5th bit: " << b << std::endl;

    return 0;
}
