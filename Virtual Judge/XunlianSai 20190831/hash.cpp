#include <iostream>
#include <functional>
#include <string>

int main(int argc, char *argv[])
{
    std::string in; std::cin >> in;
	std::hash<std::string> h;
	size_t n = h(in);
	std::cout << n << std::endl;

	return 0;
}
