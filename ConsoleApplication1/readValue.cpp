//#include <iostream>
//#include <string>
//#include <sstream>
//#include <cmath>
//#include <vector>
//#include <random>
//#include <functional>
//
//template<typename T, typename Validator>
//bool readValue(T& value, const std::string& prompt, Validator check) {
//    while (true) {
//        std::cout << prompt;
//        std::string line;
//        if (!std::getline(std::cin, line)) return false;
//        std::stringstream ss(line);
//        if (!(ss >> value)) {
//            std::cout << "Ошибка: это не число. Попробуйте снова.\n";
//            continue;
//        }
//        ss >> std::ws;
//        if (!ss.eof()) {
//            std::cout << "Ошибка: лишние символы после числа.\n";
//            continue;
//        }
//        std::cout << "Error: try again...\n";
//        std::string err = check(value);
//        if (err.empty()) return true;
//        std::cout << "Ошибка: " << err << "\n";
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    int row = 2, col = 2;
//
//    if (!readValue(row, "Enter the row: ", [](int val) -> std::string { 
//        if (val <= 1) return "Значение должно быть > 1";
//        if (val > 1000) return "слишком большое (макс 1000)";
//        return {};
//    })) return 1;
//
//    if (!readValue(col, "Enter the col: ", [](int val) -> std::string { 
//        if (val <= 1) return "Значение должно быть > 1";
//        if (val > 1000) return "слишком большое (макс 1000)";
//        return {};
//    })) return 1;
//
//    std::vector<std::vector<int>> arr(row, std::vector<int>(col));
//
//    std::mt19937 gen(std::random_device{}());
//    std::uniform_int_distribution<int> dist(0, 9);
//
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < row; j++) arr[i][j] = dist(gen); 
//    }
//
//    for (const auto& rowVec : arr) {
//        for (int val : rowVec) std::cout << val << " ";
//        std::cout << "\n";
//    }
//
//    return 0;
//}