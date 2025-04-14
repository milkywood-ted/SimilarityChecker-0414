#include <string>

using std::string;

class SimilarityChecker {
public:
	static const int LEN_MAXSCORE = 60;
	static const int LEN_TWICE_DIFF_SCORE = 0;
	static const int EXISTENCE_MAXSCORE = 40;
	static const int EXISTENCE_NONE_UPPER_SCORE = 0;

	int lengthSimilarity(const string& first, const string& second) {
		if (first.length() >= second.length() * 2 || second.length() >= first.length() * 2)
			return LEN_TWICE_DIFF_SCORE;
		if (first.length() == second.length())
			return LEN_MAXSCORE;

		return getPartialScoreLength(first, second);
	}

	int existenceSimilarity(const string& first, const string& second) {
		if (false == isUpper(first) || false == isUpper(second))
			return EXISTENCE_NONE_UPPER_SCORE;

		updateAlphabets(first, second);
		if (existSameLetters())
			return EXISTENCE_MAXSCORE;

		return getPartialScoreExistence();
	}

private:
	bool alphabetsFirst[26] = { 0 }, alphabetsSecond[26] = { 0 };

	void updateAlphabets(const string& first, const string &second) {
		for (auto letter : first) {
			alphabetsFirst[letter - 'A'] = true;
		}
		for (auto letter : second) {
			alphabetsSecond[letter - 'A'] = true;
		}
	}

	bool isUpper(const string& str) const {
		for (auto letter : str)
			if (letter < 'A' || letter > 'Z') return false;
		return true;
	}

	int getPartialScoreLength(const std::string& first, const std::string& second) const {
		int firstLength = first.length(), secondLength = second.length();
		int lengthDiff = firstLength - secondLength;
		int shorterLength = secondLength;

		if (firstLength < secondLength) {
			lengthDiff = secondLength - firstLength;
			shorterLength = firstLength;
		}

		return 60 - (60 * lengthDiff) / shorterLength;
	}

	bool existSameLetters() const {
		for (int i = 0; i < 26; ++i) {
			if (alphabetsFirst[i] ^ alphabetsSecond[i])
				return false;
		}

		return true;
	}

	int getPartialScoreExistence() const {
		int sameCnt = 0, totalCnt = 0;

		for (int i = 0; i < 26; ++i) {
			if (alphabetsFirst[i] && alphabetsSecond[i]) sameCnt++;
			if (alphabetsFirst[i] || alphabetsSecond[i]) totalCnt++;
		}

		return sameCnt * 40 / totalCnt;
	}
};