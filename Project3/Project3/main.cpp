#include <iostream>

using namespace std;

void swap(int*a, int*b) {
	*a = *a - *b; //*a = *a^*b
	*b = *a + *b; //*b = *a^*b
	*a = *b - *a; //*a = *a^*b
}

int main(void) {

}