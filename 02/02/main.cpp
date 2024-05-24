#include <iostream>
#include "proxy.h"

int main() {
    auto real_db = VeryHeavyDatabase();
    auto limit_db = OneShotDB(std::addressof(real_db), 2);

    std::cout << "Shot data from db:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << limit_db.GetData("Key") << std::endl;
    }

    return 0;
}