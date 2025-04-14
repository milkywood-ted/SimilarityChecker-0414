#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using std::string;

TEST(SimilarityLengthTS, TC1) {
	SimilarityChecker app;
	string first = "ASD", second = "DSA";

	int expected = 60;
	EXPECT_EQ(expected, app.lengthSimilarity(first, second));
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}