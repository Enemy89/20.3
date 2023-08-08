#include <iostream>
#include <fstream>

int main() {
    std::cout << "What kind of fish?" << std::endl;
    std::string type_user, type_standard;
    int count=0;
    std::cin >> type_user;

    std::ifstream river("..\\river.txt");
    std::ofstream basket("..\\basket.txt", std::ios::app);

    if (river.is_open() == 0 || basket.is_open() == 0) {
        std::cout << "Path no valid!";
        return 0;
    }

    while (!river.eof()) {
        river>>type_standard;
        if(type_standard==type_user) {
            basket<<type_standard<<std::endl;
            count++;
        }
    }
    river.close();
    basket.close();

    std::cout<<count<<" fish were caught";
}