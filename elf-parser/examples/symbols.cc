#include <iostream>
#include <inttypes.h> // PRIx64 
#include "../elf_parser.hpp"

void print_symbols(std::vector<elf_parser::symbol_t> &symbols);

int main(int argc, char* argv[]) {
    char usage_banner[] = "usage: ./sections [<executable>]\n";
    if(argc < 2) {
        std::cerr << usage_banner;
        return -1;
    }

    std::string program((std::string)argv[1]);
    elf_parser::Elf_parser elf_parser(program);

    std::vector<elf_parser::symbol_t> syms = elf_parser.get_symbols();
    print_symbols(syms);
    return 0;
}

void print_symbols(std::vector<elf_parser::symbol_t> &symbols) {
    printf("Num:    Value  Size Type    Bind   Vis      Ndx Name\n");
    for (auto &symbol : symbols) {
        printf("%-3d: %08" PRIx64 "  %-4d %-8s %-7s %-9s %-3s %s(%s)\n",
                symbol.symbol_num, 
                symbol.symbol_value,
                symbol.symbol_size, 
                symbol.symbol_type.c_str(),
                symbol.symbol_bind.c_str(),
                symbol.symbol_visibility.c_str(),
                symbol.symbol_index.c_str(),
                symbol.symbol_name.c_str(),
                symbol.symbol_section.c_str());     
    }
}