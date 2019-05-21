#include "main.h"
#define V_SIZE (10)
#define RAND_ORDER (V_SIZE * 1000000) //for numbers < 1000

const String
unsorted = "ibgehacfdj",
const String expected_sorted = "abcdefghij",
const one_char_string = "aaaaaaaaaa",
const String zeros_string = "\0\0\0\0\0\0\0\0\0\0",
const String zeros_ones_string = "a\0a\0a\0a\0a\0",
const String sorted_zeros_ones_string = "a";

inline void print_vector(String & data){
	String::iterator current = data.begin();
	String::iterator end = data.end() - 1;
	if(end - current < 0) return;

	std::cout << "Vector is: ";
	while(current <= end){
		std::cout << *current << " ";
		current++;
	}
	std::cout << std::endl;
}

TEST(sort_test, sort_random_unsorted){
	String raw = unsorted;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == unsorted) << "vector not sorted!\n";
}

TEST(sort_test, sort_sorted){
	String raw = expected_sorted;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == expected_sorted) << "vector not sorted!\n";
}

TEST(sort_test, sort_ones_vector){
	String raw = one_char_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == one_char_string);
}

TEST(sort_test, sort_zeros_vector){
	String raw = zeros_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == zeros_string);
}

TEST(sort_test, sort_zeros_ones_vector){
	String raw = zeros_ones_string;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == sorted_zeros_ones_string);
}

TEST(file_test,file_write){
    String raw = unsorted;
    std::ifstream f;
    f.open("C:\\Documents\\programming\\file.cpp", std::ios::in);
    ASSERT_TRUE( f.is_open() ) << "Cat open file" ;
   
}

TEST(file_test,file_read){
    String raw =expected_sorted;
    std::ofstream f;
    f.open("C:\\Documents\\programming\\file.cpp", std::ios::out);
    ASSERT_TRUE(f.is_open()) << "Cat open file" ;
}
	   
TEST(main_test, sort_files){
	String raw = unsorted;
	std::ifstream f;
	f.open("C:\\Documents\\programming\\file.cpp", std::ios::in);
	f>>raw;
	qsort_recursive(raw);
	ASSERT_TRUE(raw == unsorted);
}
	
	

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
