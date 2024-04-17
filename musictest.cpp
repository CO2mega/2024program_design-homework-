#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string relativeFolderPath = "/userlog/"; // 相对路径
    std::string fileName = "123.txt"; // 文件名
    std::string filePath = relativeFolderPath + fileName; // 构建完整的文件路径

    std::ifstream file(filePath); // 创建一个ifstream对象并尝试打开文件

    if (!file.is_open()) {
        std::cerr << "无法打开文件：" << filePath << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) { // 读取文件的每一行
        std::cout << line << std::endl; // 输出文件内容到终端
    }

    file.close(); // 关闭文件
    return 0;
}
