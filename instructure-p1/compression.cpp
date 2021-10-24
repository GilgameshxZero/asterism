#include <iostream>

std::string compress(std::string const &original) {
	std::string compressed;

	for (int i = 0; i < original.length();) {
		int counter = 0;
		char first = original[i];
		// while (original[i] == first) {
		// 	i++;
		// 	counter++;
		// }
		for (; original[i] == first; i++) {
			counter++;
		}

		compressed.push_back(first);
		compressed += std::to_string(counter);
	}

	if (compressed.length() < original.length()) {
		return compressed;
	}
	return original;
}

int main() {
	std::cout << compress("aabcccccaaa");
	return 0;
}
