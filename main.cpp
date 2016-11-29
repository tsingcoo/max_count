

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

int main() {

    std::vector<int> vec;
    std::string line;
    int num;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::map<int, int> num_cnt;

    while (iss >> num) {
        vec.push_back(num);
    }

    std::set<int> ss;

    for (int i = 0; i < vec.size(); ++i) {
        ss.insert(vec[i]);
    }

    std::vector<std::pair<int, int>> num_cnt_pair;

    for (std::set<int>::iterator it = ss.begin(); it != ss.end(); ++it) {

        int cnt = (int) std::count(vec.begin(), vec.end(), *it);
        num_cnt_pair.push_back({*it, cnt});
    }


    auto cmp = [](std::pair<int, int> const &a, std::pair<int, int> const &b) {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    };

    std::sort(num_cnt_pair.begin(), num_cnt_pair.end(), cmp);

    int res = num_cnt_pair[0].first;

    std::cout << res << std::endl;

    return 0;

}