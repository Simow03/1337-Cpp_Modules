#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage : " << argv[0] << " <LEVEL>" << std::endl;
        return 1;
    }

    Harl harl;

    harl.complain(argv[1]);
}