#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using std::string;
using namespace ::testing;

class StringSimilarityFixture : public Test {
public:
	StringSimilarityFixture(const string first, const string second) : first_{ first }, second_{ second } {}

	int testSimilarityLength() {

	}
private:
	string first_, second_;
};
TEST(SimilarityLengthTS, TC_Max1) {
	SimilarityChecker app;
	string first = "ASD", second = "DSA";

	int expected = ::SimilarityChecker::LEN_MAXSCORE;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityLengthTS, TC_Zero1) {
	SimilarityChecker app;
	string first = "A", second = "BBB";

	int expected = ::SimilarityChecker::LEN_TWICE_DIFF_SCORE;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityLengthTS, TC_Partial1) {
	SimilarityChecker app;
	string first = "AAABB", second = "BAA";

	int expected = 20; // 60 - (gap * 60)/shorterLength 
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityExistenceTS, TC_Max1) {
	SimilarityChecker app;
	string first = "ASD", second = "DSA";

	int expected = ::SimilarityChecker::EXISTENCE_MAXSCORE;
	EXPECT_EQ(expected, app.existenceSimilarity(first, second));
}

TEST(SimilarityExistenceTS, TC_Max2) {
	SimilarityChecker app;
	string first = "AAABB", second = "BA";

	int expected = 40;
	EXPECT_EQ(expected, app.existenceSimilarity(first, second));
}

TEST(SimilarityExistenceTS, TC_Zero1) {
	SimilarityChecker app;
	string first = "ASd", second = "DSa";

	int expected = ::SimilarityChecker::EXISTENCE_NONE_UPPER_SCORE;
	EXPECT_EQ(expected, app.existenceSimilarity(first, second));
}

TEST(SimilarityExistenceTS, TC_Partial1) {
	SimilarityChecker app;
	string first = "AA", second = "AAE";

	int expected = 20;
	EXPECT_EQ(expected, app.existenceSimilarity(first, second));
}

int main(void) {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}