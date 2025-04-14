#include <string>

using std::string;

class SimilarityChecker {
public:
	int lengthSimilarity(string& first, string& second) {
		if (false == isUpper(first) || false == isUpper(second))
			return 0;
		if (first.length() >= second.length() * 2 || second.length() >= first.length() * 2)
			return 0;
		if (first.length() == second.length())
			return 60;

		return getPartialScore(first, second);
	}

	bool isUpper(string& str) {
		for (auto letter : str)
			if (letter < 'A' || letter > 'Z') return false;
		return true;
	}

	int getPartialScore(std::string& first, std::string& second)
	{
		int firstLength = first.length(), secondLength = second.length();
		int lengthDiff = firstLength - secondLength;
		int shorterLength = secondLength;

		if (firstLength < secondLength) {
			lengthDiff = secondLength - firstLength;
			shorterLength = firstLength;
		}

		int partialScore = 60 - (60 * lengthDiff) / shorterLength;

		return partialScore;
	}

	int existenceSimilarity(string& first, string& second) {
		return 40;
	}
};