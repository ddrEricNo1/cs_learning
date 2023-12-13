#include <iostream>

/*
[capture](parameters)->return_type{
	// 函数体
}
capture: 用于在lambda内部访问外部变量
return_type: 返回类型，可以省略，根据返回语句的表达式自动判断
*/

int main() {
	auto isLessThan2 = [](int i) {return i < 2;};
	std::cout << isLessThan2(1) << std::endl;
	return 0;
}

