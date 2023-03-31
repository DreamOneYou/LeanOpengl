#include<iostream>
#include<boost/filesystem.hpp>
int main(){
    boost::filesystem::path file = "/home/yiyi/VScode/OpenglLearn/container.jpg";
    const char* file = file.c_str();
    std::cout<<"path:"<<file<<std::endl;
    system("pause");
    return EXIT_SUCCESS;
}