

#include <utility> //*for pair
#include <iostream>


//实现pair的输出流
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& strm,const std::pair<T1,T2>&p)
{
    return strm <<"["<<p.first<<","<<p.second<<"]";
}

typedef std::pair<int,float> IntFloatPair;



int main(int argc, char const *argv[])
{
    IntFloatPair p{42,3.14};                    //*create
    std::cout<<std::get<0>(p)<<std::endl;       //*get first value in pair
    std::cout<<std::get<1>(p)<<std::endl;       //*get second value in pair
    std::cout<<p<<std::endl;                    //*STL没有实现输出流
    return 0;
}
