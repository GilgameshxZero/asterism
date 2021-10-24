#include <iostream>
#include <string>
#include <vector>

double parseReceipt(std::vector<std::string> const &receipt) {
	double total = 0;
	for (int i = 0; i < receipt.size(); i++) {
		int j = 0;
		for (; j < receipt[i].length(); j++) {
			if (receipt[i][j] == '\t') {
				break;
			}
		}

		std::string remaining;
		for (j++; j < receipt[i].length(); j++) {
			remaining.push_back(receipt[i][j]);
		}
		// remaining is "1.23" or "-.22" here.
		total += std::stod(remaining);
	}
	return total;
}

int main() {
	std::cout << parseReceipt({"Milk\t1.23", "coupon\t-.22"}) << '\n';
	std::cout << parseReceipt({"Milk\t1.23", "coupon\t-.22", "Cabbage\t1.50"}) << '\n';
	return 0;
}
