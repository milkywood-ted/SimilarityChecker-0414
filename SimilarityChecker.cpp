#include <string>

using std::string;

class SimilarityChecker {
public:
	int lengthSimilarity(string& first, string& second) {
		if (first.length() >= second.length() * 2 || second.length() >= first.length() * 2)
			return 0;
		if (first.length() == second.length())
			return 60;

		return getPartialScore(first, second);
	}


	int existenceSimilarity(string& first, string& second) {
		if (false == isUpper(first) || false == isUpper(second))
			return 0;
		if (existSameLetters(first, second))
			return 40;

		//partialScore = samecnt * 40 / totalcnt
		int sameCnt = 0, totalCnt = 0;
		bool alphabetsFirst[26] = { 0 }, alphabetsSecond[26] = { 0 };
		for (auto letter : first) {
			alphabetsFirst[letter - 'A'] = true;
		}
		for (auto letter : second) {
			alphabetsSecond[letter - 'A'] = true;
		}

		for (int i = 0; i < 26; ++i) {
			if (alphabetsFirst[i] && alphabetsSecond[i]) sameCnt++;
			if (alphabetsFirst[i] || alphabetsSecond[i]) totalCnt++;
		}

		return sameCnt * 40 / totalCnt;
	}

private:

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

	bool existSameLetters(string& first, string& second) {
		bool alphabets[26] = { false };

		for (auto letter : first) {
			alphabets[letter - 'A'] = true;
		}
		for (auto letter : second) {
			if (alphabets[letter - 'A'] == false)
				return false;
		}

		return true;
	}
};