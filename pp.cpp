#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    //Variables
    std::ifstream inFile(argv[1], std::ifstream::binary);
    uint8_t number;
    char* buffer = (char*)(&number);
    std::vector<uint8_t> after_filter;
    int counter = 0;
    
    //Goes through each hex value
    while(inFile.read(buffer, sizeof(number))) {
        if(counter < 3) {
            if(number == 0x0A) {
                counter += 1;
            }
        }
        else {
            after_filter.push_back(number);
        }
    }
    inFile.close();
    
    std::ofstream outFile(argv[1], std::ofstream::binary);
    
    for (unsigned i=0; i < after_filter.size(); i++) {
        outFile << after_filter[i];
    }
    
    outFile.close();
    
    return 0;
}
