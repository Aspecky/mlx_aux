// filepath: /home/aspecky/Documents/Github/42cursus/mlx_aux/tests/test_main.c
#include <stdio.h>
#include "../source/Color4/Color4.h"

// Helper function to check if two colors are equal
void assert_color_equals(uint32_t actual, uint32_t expected, const char* test_name) {
	if (actual != expected) {
		printf("FAIL: %s\n", test_name);
		printf("  Expected: 0x%08X\n", expected);
		printf("  Actual:   0x%08X\n", actual);
	} else {
		printf("PASS: %s\n", test_name);
	}
}

void test_color4_from_hex() {
	// Test basic colors with '#' prefix
	assert_color_equals(color4_from_hex("#FF0000"), 0xFF0000FF, "Red with # prefix");
	assert_color_equals(color4_from_hex("#00FF00"), 0x00FF00FF, "Green with # prefix");
	assert_color_equals(color4_from_hex("#0000FF"), 0x0000FFFF, "Blue with # prefix");
	
	// Test without '#' prefix
	assert_color_equals(color4_from_hex("FF0000"), 0xFF0000FF, "Red without # prefix");
	assert_color_equals(color4_from_hex("00FF00"), 0x00FF00FF, "Green without # prefix");
	assert_color_equals(color4_from_hex("0000FF"), 0x0000FFFF, "Blue without # prefix");
	
	// Test different lengths
	assert_color_equals(color4_from_hex("FF"), 0xFF0000FF, "Only red component");
	assert_color_equals(color4_from_hex("FFFF"), 0xFFFF00FF, "Red and green components");
	assert_color_equals(color4_from_hex("FFFFFF"), 0xFFFFFFFF, "RGB components");
	assert_color_equals(color4_from_hex("FFFFFF80"), 0xFFFFFF80, "RGBA components");
	
	// Test case insensitivity
	assert_color_equals(color4_from_hex("ff0000"), 0xFF0000FF, "Lowercase hex");
	assert_color_equals(color4_from_hex("FF0000"), 0xFF0000FF, "Uppercase hex");
	assert_color_equals(color4_from_hex("Ff00Aa"), 0xFF00AAFF, "Mixed case hex");
	
	// Test with alpha values
	assert_color_equals(color4_from_hex("#FFFFFF00"), 0xFFFFFF00, "Transparent white");
	assert_color_equals(color4_from_hex("#00000080"), 0x00000080, "Semi-transparent black");
	
	// Edge cases
	assert_color_equals(color4_from_hex(""), 0x0000FF, "Empty string");
	assert_color_equals(color4_from_hex("#"), 0x0000FF, "Only # character");
	
	// Test with invalid characters (should be treated as 0)
	assert_color_equals(color4_from_hex("GG0000"), 0x000000FF, "Invalid hex characters");
}

int main(void) {
	printf("Testing color4_from_hex function...\n");
	test_color4_from_hex();
	printf("Tests completed.\n");
	return 0;
}
