#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct S {
  int x;
  struct S* left;
  struct S* right;
};

typedef struct S S;

S setupAns1() {
	// Make the contents of ans1 correspond to picture 1 in the writeup
	struct S ans1;
	ans1.x = 42;
	struct S circle;
	struct S triangle;
	circle.x = 33;
	circle.right = &triangle;
	circle.left = &triangle;
	triangle.x = 55;
	triangle.left = &circle;
	triangle.right = NULL;
	ans1.left = &circle;
	ans1.right = &triangle;
  	return ans1;
}


struct S* ans2;

S* setupAns2() {
	// Make the contents of ans2 correspond to picture 2 in the writeup
	S* ans2;
	S triangle;
	S circle[3];
	triangle.x = 66;
	triangle.right = NULL;
	triangle.left = &circle;
	circle[0].x = 33;
	circle[0].left = NULL;
	circle[0].right = &triangle;
	circle[1].x = 44;
	circle[1].left = NULL;
	circle[1].right = &triangle;
	circle[2].x = 55;
	circle[2].left = &circle;
	circle[2].right = NULL;
	ans2 = &triangle;
	return ans2;
}


int main(void) {

	// Don't change this main below here. Feel free to change above here
	// to print out other debugging information that's helpful
	
	S s1 = setupAns1();
	bool ans1OK =
		(s1.x == 42) &&
		(s1.left->x == 33) &&
		(s1.right->x == 55) &&
		(s1.left != s1.right) &&
		(s1.left->left == s1.right) &&
		(s1.left->right == s1.right) &&
		(s1.right->left == s1.left) &&
		(s1.right->right == NULL);
	if(ans1OK) { printf("You got ans1!\n"); }
	else { printf("ans1 didn't match\n"); }

	S* ans2 = setupAns2();
	bool ans2OK =
		(ans2->x == 66) &&
		(ans2->left != ans2) &&
		(ans2->right == NULL) &&
		(ans2->left[0].x == 33) &&
		(ans2->left[1].x == 44) &&
		(ans2->left[2].x == 55) &&
		(ans2->left[0].right == ans2) &&
		(ans2->left[1].right == ans2) &&
		(ans2->left[2].right == NULL) &&
		(ans2->left[0].left == NULL) &&
		(ans2->left[1].left == NULL) &&
		(ans2->left[2].left == ans2->left);
	if(ans2OK) { printf("You got ans2!\n"); }
	else { printf("ans2 didn't match\n"); }
		

}
