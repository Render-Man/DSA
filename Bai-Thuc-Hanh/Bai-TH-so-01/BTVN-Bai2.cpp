#include<iostream>


void reverse(std::string str, int i)
{
    if(i == -1)
        return;
    std::cout << str[i];
    reverse(str, i - 1);
}

int main()
{
    std::string str = "lmao babie";

    reverse(str, str.length());;
}