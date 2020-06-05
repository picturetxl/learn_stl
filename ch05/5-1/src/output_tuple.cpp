
//Todo: metaprogramming?
//Todo: partial specialization?

#include <iostream>
#include <tuple>
#include <string>

/**
 * ! 模板超编程 template metaprogramming
 * ! 在编译期递归迭代tuple的所有元素
 */

//* 定义一个struct<int,int,Args...>
template <int IDX,int MAX,typename...Args>
struct PRINT_TUPLE
{
    //* 输出方法
    static void print(std::ostream&strm,const std::tuple<Args...>& t)
    {
        strm<<std::get<IDX>(t)<<(IDX+1==MAX?"":",");
        PRINT_TUPLE<IDX+1,MAX,Args...>::print(strm,t);//* call itself
    }
};

//* 偏特化 partial specialization 当索引等于tuple的元素个数时,终结递归
template <int MAX,typename...Args>
struct PRINT_TUPLE<MAX,MAX,Args...>
{
    static void print(std::ostream&strm,const std::tuple<Args...>& t)
    {

    }
};

template <typename... Args>
std::ostream& operator<<(std::ostream&strm,const std::tuple<Args...>& t)
{//一个包含可变参数的tuple t
    strm<<"[";
    PRINT_TUPLE<0,sizeof...(Args),Args...>::print(strm,t);
    return strm<<"]";
}

int main(int argc, char const *argv[])
{
    std::tuple<int,float,std::string>t(77,1.1,"hell");
    std::cout<<"io:"<<t<<std::endl;//*io:[77,1.1,hell]
    return 0;
}
