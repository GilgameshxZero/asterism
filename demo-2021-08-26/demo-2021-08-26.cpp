#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>

class WallTimeGuard {
	private:
	std::chrono::steady_clock::time_point executionBegin;

	public:
	WallTimeGuard() : executionBegin(std::chrono::steady_clock::now()) {}
	~WallTimeGuard() {
		std::cout << "\n\n-------- Wall time: "
							<< std::chrono::duration_cast<std::chrono::milliseconds>(
									 std::chrono::steady_clock::now() - this->executionBegin)
									 .count()
							<< "ms. --------" << std::endl;
	}
};
WallTimeGuard wallTimeGuard;

int main(int argc, const char *argv[]) {
	using namespace std::literals;

	int x[40000];
	for (int xIdx = 0; xIdx < 40000; xIdx++) {
		x[xIdx] = rand() % 1000;
	}
	std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << std::endl;

	// sum[0] is the sum of the first zero numbers in x
	// sum[1] is the sum of the first one numbers in x
	// sum[2] is the sum of the first two numbers in x
	// ...

	int sum[40000];
	sum[0] = 0;
	// Runs in 0.001s
	// O(n) algorithm
	// sum[1] = sum[0] + x[0]; // x[0]
	// sum[2] = sum[1] + x[1]; // (0 + x[0]) + x[1]
	// sum[3] = sum[2] + x[2]; // ((0 + x[0]) + x[1]) + x[2]
	for (int sumIdx = 1; sumIdx < 40000; sumIdx++) {
		sum[sumIdx] = sum[sumIdx - 1] + x[sumIdx - 1];
	}

	// Times out! 1.7s
	// O(n^2) algorithm
	// for (int sumIdx = 0; sumIdx < 40000; sumIdx++) {
	// 	// sum[sumIdx] = 0;
	// 	sum[sumIdx] = 0;

	// 	for (int xIdx = 0; xIdx < sumIdx; xIdx++) {
	// 		sum[sumIdx] = sum[sumIdx] + x[xIdx];
	// 	}

	// 	// sum[sumIdx] = the sum of the first sumIdx numbers in array x.
	// }

	std::cout << sum[0] << ' ' << sum[1] << ' ' << sum[2] << ' ' << sum[3] << std::endl;

	return 0;
}
