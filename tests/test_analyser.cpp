#include "catch2/catch.hpp"

#include "instruction/instruction.h"
#include "tokenizer/tokenizer.h"
#include "analyser/analyser.h"
#include "simple_vm.hpp"

#include <sstream>
#include <vector>

const static std::map<std::string, std::vector<int>> simple_test_case_map{
        {"begin\n" "print(1+2*3-4);\n" "end", {3}},
        {"begin\n" "const a=1;\n" "var b=2;\n" "print(a+b);\n" "end",{3}}
};

TEST_CASE("Test simple print") {
    for (auto &it:simple_test_case_map){
        std::string input=it.first;
        std::stringstream ss;
        ss.str(input);
        miniplc0::Tokenizer tokenizer(ss);
        auto token_res = tokenizer.AllTokens();
        REQUIRE_FALSE(token_res.second.has_value());

        miniplc0::Analyser analyser(token_res.first);
        auto analyse_res = analyser.Analyse();
        REQUIRE_FALSE(analyse_res.second.has_value());

        auto vm = miniplc0::VM(analyse_res.first);
        auto vm_res = vm.Run();
        REQUIRE(vm_res == it.second);
    }
}