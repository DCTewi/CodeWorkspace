#include <cstdio>

constexpr char str[] = R"(#include <cstdio>

constexpr char str[] = R"(%s%c";

int main(int argc, char** argv) {
	std::printf(str, str, ')');
	return 0;
})";

int main(int argc, char** argv) {
	std::printf(str, str, ')');
	return 0;
}
