#include <iostream>
#include <vector>
#include <algorithm>

#include "List.h"
#include "Triangle.h"
#include "accessory.h"

using triangle_type = int;

auto main() -> int {
    std::string cmd;
    std::vector<std::string> out;
    List<Triangle<triangle_type>> list;
    help();
    while (true){
        getline(std::cin, cmd);
        std::vector<std::string> cmd_array = split(cmd,' ');
        if (cmd_array[0] == "exit"){
            break;
        }
        else if (cmd_array[0] == "help"){
            help();
        }
        else if (cmd_array[0] == "delete"){
            size_t index = string_to_int(cmd_array[1]);
            list.erase_by_index(index);
        }
        else if (cmd_array[0] == "show"){
            std::for_each(list.begin(), list.end(), [](Triangle<triangle_type>& T) { std::cout << T; });
        }
        else {
            std::vector<std::string> array = split(cmd,' ');
            std::vector<std::pair<triangle_type ,triangle_type>> numbers_double(EDGES_COUNT);
            int j = 0;
            for(size_t i = 0;i < numbers_double.size() * 2 ; i += 2){
                numbers_double[j] = {string_to_int(array[i]),string_to_int(array[i+1])};
                j++;
            }
            Triangle<triangle_type> tr(numbers_double);
            list.insert_by_index(list.length(),tr);
        }
    }
    return 0;
}
