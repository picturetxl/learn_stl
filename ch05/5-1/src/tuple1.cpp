
#include <iostream>
#include <complex> //*for complex
#include <tuple>
#include <string>
#include <functional> //*for ref()
int main(int argc, char const *argv[])
{
    //std::tuple<std::string, int, int, std::complex<double>> t;

    //*************************Test tuple get value and compare***************************************************
    //* t1
    std::tuple<int, float, std::string> t1(41, 6.1, "helloworld");
    std::cout << std::get<0>(t1) << std::endl; //*41
    std::cout << std::get<1>(t1) << std::endl; //*6.1
    std::cout << std::get<2>(t1) << std::endl; //*helloworld

    //* t2
    auto t2 = std::make_tuple(42, 44, "nice");
    std::get<1>(t1) = std::get<1>(t2); //*assign second valut in t2 to t1

    std::cout << std::get<0>(t1) << std::endl; //*41
    std::cout << std::get<1>(t1) << std::endl; //*44
    std::cout << std::get<2>(t1) << std::endl; //*helloworld
    if (t1 < t2)
    {            //*compare value for value
        t1 = t2; //*OK assign value for value
        std::cout <<"t1 less than t2" << std::endl;//* YES
    }

    std::cout << std::get<0>(t1) << std::endl; //*42
    std::cout << std::get<1>(t1) << std::endl; //*44
    std::cout << std::get<2>(t1) << std::endl; //*nice

    //****************************************************************

    std::string s="world";
    auto x = std::make_tuple(s);    //* copy s
    std::get<0>(x)="my value";      //* modifies x but not s

    std::cout<<"x is "<<std::get<0>(x)<<std::endl;  //* x is my value
    std::cout<<"s is "<<s<<std::endl;               //* s is world

    auto y = std::make_tuple(std::ref(s));          //* reference for s
    std::get<0>(y) = "hello";

    std::cout<<"y is "<<std::get<0>(y)<<std::endl;  //* hello
    std::cout<<"s is "<<s<<std::endl;               //* hello


    //*****************************Extract tuple value*******************************************
    std::tuple<int,float,std::string> tt(77,1.1,"hell");
    int i;
    float f;
    std::string mystring;
    //* way 1
    std::make_tuple(std::ref(i),std::ref(f),std::ref(mystring))=tt;
    std::cout<<i<<" "<<f<<" "<<mystring<<std::endl; //* 77 1.1 hell

    //* way 2
    int ii;
    float ff;
    std::string ss;
    std::tie(ii,ff,ss)=tt;
    std::cout<<ii<<" "<<ff<<" "<<ss<<std::endl;     //* 77 1.1 hell

    int iii;
    std::string sss;
    std::tie(iii,std::ignore,sss) = tt;//* ignore the second element
    std::cout<<iii<<" "<<sss<<std::endl;            //*77 hell

    return 0;
}
