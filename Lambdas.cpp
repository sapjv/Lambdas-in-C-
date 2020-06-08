
#include <iostream>
#include <functional>
using namespace std;

// The basic lambda function
void emptyLambda() {
    []() -> int{
        cout<<"Hello World"<<endl;
        return 1;
    }();
}
// Lambda function with parameters
void parameterisedLambda() {
    int retLambda = [](int value)->int{
        cout<<"Hello World"<<endl;
        return value + 1;
    }(100);
    cout<<retLambda<<endl;
}
// Taking lambda into a function pointer
void functionpointerLambda() {
    std::function<int(int)> lambdaFn = [](int value)->int{
        cout<<"Hello World"<<endl;
        return value + 1;
    };
    int retLambda = lambdaFn(100);
    cout<<retLambda<<endl;
}
// lambda for function f(x) = x * x
void fxSquare() {
    std::function<int(int)> fxsquare = [](int x) ->int {
        return x * x;
    };
    int retValue = fxsquare(10);
    cout<<retValue<<endl;
}
// lambda for function f(x,y) = x2 + y2 + 2xy;
void fxplusySquare() {
    std::function<int(int, int)> fxsquare = [](int x, int y) ->int {
        int xsquare = [](int x) { return x * x; }(x);
        int ysquare = [](int y) { return y * y; }(y);
        int twoxy = [](int x, int y) { return 2 * x * y;}(x,y);
        return xsquare + ysquare + twoxy;
    };
    int retValue = fxsquare(5,3);
    cout<<retValue<<endl;
}
void fxplusySquareByCaptureList() {
    int x = 5, y = 3;
    std::function<int(void)> fxplusysquare = [x,y]() ->int {
        int xsquare = [](int x) { return x * x; }(x);
        int ysquare = [](int y) { return y * y; }(y);
        int twoxy = [](int x, int y) { return 2 * x * y;}(x,y);
        return xsquare + ysquare + twoxy;
    };
    int retValue = fxplusysquare();
    cout<<retValue<<endl;
}

template<int iValue, int jValue>
struct AbcTest {
    int i = iValue;
    int j = jValue;
    int sumFn() {
        return [this](){
            return this->i + this->j;
        }();
    }
};
void classLambda() {
    AbcTest<100,200> aTest;
    cout<<aTest.sumFn()<<endl;
}
int main() {
    emptyLambda();
    parameterisedLambda();
    functionpointerLambda();
    fxSquare();
    fxplusySquare();
    fxplusySquare();
    fxplusySquareByCaptureList();
    classLambda();
    return 1;
}
