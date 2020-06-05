#include <iostream>
#include <utility>
#include <tuple>
#include <functional>   //* for ref() or cref()

/**
 * ! move and ref
 * ! tie
 */
int main(int argc, char const *argv[])
{
    //*************************Test move() and ref()***************************************
    std::string s{"hello"};
    std::string t{"world"};
    auto p = std::make_pair(std::move(s),std::move(t)); //* move semantic
    std::cout<<p.first<<","<<p.second<<std::endl;

    //* s and t ?
    std::cout<<s<<std::endl;    //* empty string
    std::cout<<t<<std::endl;    //* empty string


    int i=0;
    auto pp = std::make_pair(std::ref(i),std::ref(i));  //* reference semantic
    std::cout<<pp.first<<","<<pp.second<<std::endl;

    //* i?
    std::cout<<i<<std::endl;    //* still can use i


    //***********************Test tie*****************************************

    std::pair<char,char> mypair = std::make_pair('x','y');
    char c;
    std::tie(std::ignore,c)=mypair; //* extract second value into c ignore first value
    std::cout <<c<<std::endl;       //* y

    char d;
    std::tie(c,d)=mypair; //*
    std::cout <<c<<" "<<d<<std::endl;   //* x y



    return 0;
}
