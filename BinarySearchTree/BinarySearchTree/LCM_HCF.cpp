#include <iostream>

int gcd(int bigger_number, int smaller_number)
{
    if (smaller_number == 0) return bigger_number;
    else return gcd(smaller_number, bigger_number%smaller_number);
}

int LCM(int num1, int num2)
{
    return(num1*num2 / gcd(num1, num2));
}

//int main()
//{
//    int num1 = 2;
//    int num2 = 10;
//    int HCF = gcd(num1, num2);
//    int lcm = LCM(num1, num2);
//    getchar();
//    return 0;
//
//}