#include <iostream>
char (*pFun)(int); 
char glFun(int a){ 
    std::cout << "glFun called" << std::endl;
    return char(a);
} 
int main() 
{ 
    pFun = glFun; 
    char ch = pFun(2);
    printf("%c",ch); 
    return 0;
}