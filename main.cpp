#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using std::string;

TEST(SimilarityLengthTS, TC1) {
	SimilarityChecker app;
	string first = "ASD", second = "DSA";

	int expected = 60;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityLengthTS, TC1_1) {
	SimilarityChecker app;
	string first = "ASd", second = "DSa";

	int expected = 0;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityLengthTS, TC2) {
	SimilarityChecker app;
	string first = "A", second = "BBB";

	int expected = 0;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

TEST(SimilarityLengthTS, TC3) {
	SimilarityChecker app;
	string first = "AAABB", second = "BAA";

	int expected = 20; // 60 - (gap * 60)/shorterLength 
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}