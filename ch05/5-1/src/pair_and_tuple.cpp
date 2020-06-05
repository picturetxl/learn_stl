

//TODO: solve problem : piecewise_construct and why must be two tuple

#include <iostream>
#include <string>
#include <utility> //*for pair
#include <tuple>   //*for tuple

/**
     * ! piecewise_construct
     * 1.首先C++添加元素除了insert or push_back/push_front 还提供了emplace => 这个东东提供了in place 的解决方案 => 避免了临时变量
     *   C++ 真的绝啊 性能怪兽 临时变量都不放过
     * 2.
     */

class Foo;

/**
 * ! call tuple and pair constructor
 * ! piecewise_construct
 * ! tuple 和 pair 可以互相转换 前提是只有两个元素
 */

int main(int argc, char const *argv[])
{
    std::tuple<int, float> t(2, 2.12); //* create a tuple
    std::pair<int, Foo> p1(42, t);     //* create pair though call constructor Foo(std::tuple<int,float>) of Foo

    //* 第二个参数是用来说明pair 的first value 即int
    //* 第三个参数是用来说明pair的second value 即Foo 本应该匹配的Foo(std::tuple<int,float>)这个构造函数
    //* 但是由于第一个参数分段式构造piecewise_construct 使得调用 Foo(int a,float b)这个构造函数 ==> 打回原形
    //? 为什么第二个参数必须是tuple 即为什么要使得后面两个参数都是tuple 才会导致这种行为
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t); //* 两个必须都是tuple
    std::cout << p2.first << std::endl;                                       //*42
    return 0;
}

class Foo
{
public:
    Foo(std::tuple<int, float>)
    {
        std::cout << "Foo::Foo(tuple)" << std::endl;
    }
    Foo(int a, float b)
    {
        std::cout << a << " " << b << std::endl;
        std::cout << "Foo::Foo(int float)" << std::endl;
    }
    template <typename... Args> //* 变模板参数 variadic template
    Foo(Args... args)
    {
        std::cout << "Foo::Foo(args...)" << std::endl;
    }
};