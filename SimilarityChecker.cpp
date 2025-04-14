#include <string>

using std::string;

class SimilarityChecker {
public:
	int lengthSimilarity(string& first, string& second) {
		if (first.length() >= second.length() * 2 || second.length() >= first.length() * 2)
			return 0;
		if (first.length() == second.length())
			return 60;

		int partialScore = 0;

		int lengthDiff = 0, shorterLength = 0;
		if (first.length() >= second.length()) {
			lengthDiff = first.length() - second.length();
			shorterLength = second.length();
		}
		else {
			lengthDiff = second.length() - first.length();
			shorterLength = first.length();
		}

		partialScore = 60 - (60 *lengthDiff)/shorterLength;

		return partialScore;
	}
};