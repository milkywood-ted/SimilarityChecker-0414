#include <string>

using std::string;

class SimilarityChecker {
public:
	int lengthSimilarity(string& first, string& second) {
		if (first.length() >= second.length() * 2 || second.length() >= first.length() * 2)
			return 0;
		return 60;
	}
};