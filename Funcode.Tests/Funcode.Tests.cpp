#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FuncodeTests
{
	TEST_CLASS(FuncodeTests)
	{
	public:

		TEST_METHOD(isPerfectSquar)
		{
			Assert::IsTrue(isPerfectSquare(4));
			Assert::IsTrue(isPerfectSquare(9));
			Assert::IsTrue(isPerfectSquare(16));
			Assert::IsTrue(isPerfectSquare(25));
			Assert::IsFalse(isPerfectSquare(30));
			Assert::IsFalse(isPerfectSquare(123456789));

		}

		TEST_METHOD(mergeSortedLists1) {
			std::vector<int>v = mergeSortedLists({ 1, 3, 5, 7 }, { 2, 4, 6, 8 });
			std::vector<int>exp = { 1, 2, 3, 4, 5, 6, 7, 8 };
			Assert::AreEqual(exp.size(), v.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v[j]);
			}

			std::vector<int>v1 = mergeSortedLists({ 1, 2,3 }, { 4,5,6 });
			exp = { 1, 2, 3, 4, 5, 6 };
			Assert::AreEqual(exp.size(), v1.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v1[j]);
			}

			std::vector<int>v2 = mergeSortedLists({ 1,3,5,7 }, { 2,4,6 });
			exp = { 1, 2, 3, 4, 5, 6,7 };
			Assert::AreEqual(exp.size(), v2.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v2[j]);
			}

			std::vector<int>v3 = mergeSortedLists({ }, { 2,4,6,8 });
			exp = { 2,4,6,8 };
			Assert::AreEqual(exp.size(), v3.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v3[j]);
			}
		}

		TEST_METHOD(areBracketsBalance)
		{
			Assert::IsTrue(areBracketsBalanced(""));
			Assert::IsTrue(areBracketsBalanced("()"));
			Assert::IsTrue(areBracketsBalanced("()[]{}"));
			Assert::IsTrue(areBracketsBalanced("({[]})"));
			Assert::IsFalse(areBracketsBalanced("("));
			Assert::IsFalse(areBracketsBalanced(")"));
			Assert::IsFalse(areBracketsBalanced("([)]"));
			Assert::IsFalse(areBracketsBalanced("{{}"));
		}

		TEST_METHOD(removeLastDuplicate) {
			std::vector<int>v = removeLastDuplicates({ 1,2,3,4 });
			std::vector<int>exp = { 1,2,3,4 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}
			v = removeLastDuplicates({ 1,2,2,3,3,3 });
			exp = { 1,2,3 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = removeLastDuplicates({ 1,1,1 });
			exp = { 1 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = removeLastDuplicates({ 1 });
			exp = { 1 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = removeLastDuplicates({ });
			exp = { };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}
		}
		TEST_METHOD(addString)
		{
			std::string a = addStrings("0", "0");
			std::string exp = "0";
			Assert::AreEqual(exp, a);
			std::string b = addStrings("0", "1234");
			exp = "1234";
			Assert::AreEqual(exp, b);
			std::string c = addStrings("456", "0");
			exp = "456";
			Assert::AreEqual(exp, c);
			std::string d = addStrings("123", "456");
			exp = "579";
			Assert::AreEqual(exp, d);
			std::string e = addStrings("1001", "999");
			exp = "2000";
			Assert::AreEqual(exp, e);
		}

		TEST_METHOD(squareSorted11) {
			std::vector<int>v = squareSorted13({ -5, -3, 0, 2, 8 });
			std::vector<int>exp = { 0, 4, 9, 25, 64 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v[j]);
			}
			std::vector<int>v1 = squareSorted13({ -2, 0, 1, 3 });
			exp = { 0, 1, 4, 9 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v1[j]);
			}
			std::vector<int>v2 = squareSorted13({ -9, -7, -3, -1, 2, 3, 7, 9 });
			exp = { 1, 4, 9, 9,49, 49, 81, 81 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v2[j]);
			}


		}

		TEST_METHOD(sum_of_number) {
			Assert::AreEqual(11, sum_of_numbers("hello5world6"));
			Assert::AreEqual(579, sum_of_numbers("abc123def456"));
			Assert::AreEqual(21, sum_of_numbers("1a2b3c4d5e6f"));
			Assert::AreEqual(0, sum_of_numbers("no_numbers_here"));

		}
		TEST_METHOD(fourSum1)
		{
			std::vector<int>v = { 1, 2, 3, 4, 5 };
			bool a = fourSum(v, 10);
			Assert::IsTrue(a);
			std::vector<int>v1 = { 2, 4, 6, 8 };
			bool b = fourSum(v1, 20);
			Assert::IsTrue(b);
			std::vector<int>v2 = { 1,2,3,4,5 };
			bool c = fourSum(v2, 20);
			Assert::IsFalse(c);
			std::vector<int>v3 = { 1,2,3 };
			bool d = fourSum(v3, 10);
			Assert::IsFalse(d);
		}

		TEST_METHOD(reverseWord) {
			std::string a = reverseWords("hello world");
			std::string exp = "world hello";
			Assert::AreEqual(exp, a);
			std::string b = reverseWords("the sky is blue");
			exp = "blue is sky the";
			Assert::AreEqual(exp, b);
			std::string c = reverseWords("");
			exp = "";
			Assert::AreEqual(exp, c);
		}

		TEST_METHOD(toBase3a) {
			std::string a = toBase3(1);
			std::string exp = "1";
			Assert::AreEqual(exp, a);
			std::string b = toBase3(8);
			exp = "22";
			Assert::AreEqual(exp, b);
			std::string c = toBase3(5);
			exp = "12";
			Assert::AreEqual(exp, c);

		}
		TEST_METHOD(maxOperation) {
			std::vector<int>v = { 1,2,3,4,5 };
			Assert::AreEqual(2, maxOperations(v, 6));

			std::vector<int>v1 = { 3,1,3,4,3 };
			Assert::AreEqual(1, maxOperations(v1, 6));

			std::vector<int>v2 = { 1,1,1,1,1 };
			Assert::AreEqual(2, maxOperations(v2, 2));
		}
		TEST_METHOD(mergeSortedArrays11) {
			std::vector<int>v = mergeSortedArrays1({ 1, 2, 4, 6, 8 }, { 3, 5, 7, 9 });
			std::vector<int>exp = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			Assert::AreEqual(exp.size(), v.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v[j]);
			}


			std::vector<int>v1 = mergeSortedArrays1({ 1, 3, 5, 7 }, { 2, 4, 6, 8, 9, 10 });
			exp = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Assert::AreEqual(exp.size(), v1.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v1[j]);
			}

			std::vector<int>v2 = mergeSortedArrays1({ 1 }, { 2 });
			exp = { 1, 2 };
			Assert::AreEqual(exp.size(), v2.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v2[j]);
			}

			std::vector<int>v3 = mergeSortedArrays1({ 3,4,5 }, { 1,2 });
			exp = { 1,2,3,4,5 };
			Assert::AreEqual(exp.size(), v3.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v3[j]);
			}

			std::vector<int>v4 = mergeSortedArrays1({  }, {  });
			exp = {  };
			Assert::AreEqual(exp.size(), v4.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v4[j]);
			}
		}

		TEST_METHOD(squareSorted14) {
			std::vector<int>v = squareSorted({ -5, -3, 0, 2, 8 });
			std::vector<int>exp = { 0, 4, 9, 25, 64 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v[j]);
			}
			std::vector<int>v1 = squareSorted({ -2, 0, 1, 3 });
			exp = { 0, 1, 4, 9 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v1[j]);
			}
			std::vector<int>v2 = squareSorted({ -9, -7, -3, -1, 2, 3, 7, 9 });
			exp = { 1, 4, 9, 9,49, 49, 81, 81 };
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v2[j]);
			}


		}
		TEST_METHOD(primeFactor) {
			std::vector<int>v = primeFactors(2);
			std::vector<int>exp = { 2 };
			for (int i = 0; i < exp.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = primeFactors(3);
			exp = { 3 };
			for (int i = 0; i < exp.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = primeFactors(10);
			exp = { 2 ,5 };
			for (int i = 0; i < exp.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = primeFactors(30);
			exp = { 2,3,5 };
			for (int i = 0; i < exp.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = primeFactors(27);
			exp = { 3,3,3 };
			for (int i = 0; i < exp.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}


		}

		TEST_METHOD(addStringa)
		{
			std::string a = addStrings4("0", "0");
			std::string exp = "0";
			Assert::AreEqual(exp, a);
			std::string b = addStrings4("0", "1234");
			exp = "1234";
			Assert::AreEqual(exp, b);
			std::string c = addStrings4("456", "0");
			exp = "456";
			Assert::AreEqual(exp, c);
			std::string d = addStrings4("123", "456");
			exp = "579";
			Assert::AreEqual(exp, d);
			std::string e = addStrings4("1001", "999");
			exp = "2000";
			Assert::AreEqual(exp, e);
		}

		TEST_METHOD(toBase3b) {
			std::string a = toBase34(1);
			std::string exp = "1";
			Assert::AreEqual(exp, a);
			std::string b = toBase34(8);
			exp = "22";
			Assert::AreEqual(exp, b);
			std::string c = toBase34(5);
			exp = "12";
			Assert::AreEqual(exp, c);

		}

		TEST_METHOD(isPerfectSquart)
		{
			Assert::IsTrue(isPerfectSquare1(4));
			Assert::IsTrue(isPerfectSquare1(9));
			Assert::IsTrue(isPerfectSquare1(16));
			Assert::IsTrue(isPerfectSquare1(25));
			Assert::IsFalse(isPerfectSquare1(30));
			Assert::IsFalse(isPerfectSquare1(123456789));

		}
		TEST_METHOD(largestCommonDivisors) {
			int a = largestCommonDivisor({ 10, 20, 30, 40, 50 });
			Assert::AreEqual(10, a);
			int b = largestCommonDivisor({ 13,26,39,52,65 });
			Assert::AreEqual(13, b);
			int c = largestCommonDivisor({ 25, 125, 250, 375, 500 });
			Assert::AreEqual(25, c);
		}

		TEST_METHOD(sumOfLeftLeave) {

			std::shared_ptr<TreeNode> root1 = std::make_shared<TreeNode>(1);
			root1->left = std::make_shared<TreeNode>(2);
			root1->right = std::make_shared<TreeNode>(3);
			root1->left->left = std::make_shared<TreeNode>(4);
			root1->left->right = std::make_shared<TreeNode>(5);
			root1->right->left = std::make_shared<TreeNode>(6);
			root1->right->right = std::make_shared<TreeNode>(7);
			Assert::AreEqual(10, sumOfLeftLeaves(root1));
		}
		TEST_METHOD(only235PrimeFactors12) {
			Assert::IsTrue(only235PrimeFactors1(2));
			Assert::IsTrue(only235PrimeFactors1(3));
			Assert::IsTrue(only235PrimeFactors1(5));
			Assert::IsTrue(only235PrimeFactors1(6));
			Assert::IsTrue(only235PrimeFactors1(8));
			Assert::IsTrue(only235PrimeFactors1(10));
			Assert::IsTrue(only235PrimeFactors1(15));
			Assert::IsTrue(only235PrimeFactors1(30));

			Assert::IsFalse(only235PrimeFactors1(1));
			Assert::IsFalse(only235PrimeFactors1(7));
			Assert::IsFalse(only235PrimeFactors1(13));
			Assert::IsFalse(only235PrimeFactors1(21));
			Assert::IsFalse(only235PrimeFactors1(23));
			Assert::IsFalse(only235PrimeFactors1(29));

		}
		TEST_METHOD(binaryListToInt1) {
			std::shared_ptr<ListNode> head1 = std::make_shared<ListNode>(1);
			head1->next = std::make_shared<ListNode>(0);
			head1->next->next = std::make_shared<ListNode>(1);
			Assert::AreEqual(5, binaryListToInt(head1));

			std::shared_ptr<ListNode> head2 = std::make_shared<ListNode>(1);
			head2->next = std::make_shared<ListNode>(1);
			head2->next->next = std::make_shared<ListNode>(0);
			head2->next->next->next = std::make_shared<ListNode>(1);
			Assert::AreEqual(13, binaryListToInt(head2));
		}
		TEST_METHOD(maxUniqueSublistSum12) {

			Assert::AreEqual(11, maxUniqueSublistSum1({ 5, 2, 1, 3, 2, 4, 1 }));
			Assert::AreEqual(15, maxUniqueSublistSum1({ 5, 4, 3, 2, 1 }));
			Assert::AreEqual(15, maxUniqueSublistSum1({ 1,2,3,4,5 }));
			Assert::AreEqual(6, maxUniqueSublistSum1({ 1,2,3,2,1 }));
			Assert::AreEqual(1, maxUniqueSublistSum1({ 1,1,1,1,1 }));
			Assert::AreEqual(0, maxUniqueSublistSum1({ }));
			Assert::AreEqual(0, maxUniqueSublistSum1({ 0 }));

		}

		TEST_METHOD(relativeRanking1) {
			std::vector<int>v = ranking({ 5, 4, 3, 2, 1 });
			std::vector<int>exp = { 0, 1, 2, 3, 4 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}

			v = ranking({ 10, 3, 8, 9, 4 });
			exp = { 0, 4, 2, 1, 3 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}


			v = ranking({ 10, 10, 9, 8, 8 });
			exp = { 0, 0, 1, 2, 2 };
			for (int i = 0; i < v.size(); i++) {
				Assert::AreEqual(exp[i], v[i]);
			}
		}

		TEST_METHOD(largestCommonDivisorsa) {
			int a = largestCommonDivisor11({ 10, 20, 30, 40, 50 });
			Assert::AreEqual(10, a);
			int b = largestCommonDivisor11({ 13,26,39,52,65 });
			Assert::AreEqual(13, b);
			int c = largestCommonDivisor11({ 25, 125, 250, 375, 500 });
			Assert::AreEqual(25, c);
		}

		TEST_METHOD(isPerfectSquart12)
		{
			Assert::IsTrue(isPerfectSquare2(4));
			Assert::IsTrue(isPerfectSquare2(9));
			Assert::IsTrue(isPerfectSquare2(16));
			Assert::IsTrue(isPerfectSquare2(25));
			Assert::IsFalse(isPerfectSquare2(30));
			Assert::IsFalse(isPerfectSquare2(123456789));

		}


		TEST_METHOD(isPerfectSquart22)
		{
			Assert::IsTrue(isPerfectSquare4(4));
			Assert::IsTrue(isPerfectSquare4(9));
			Assert::IsTrue(isPerfectSquare4(16));
			Assert::IsTrue(isPerfectSquare4(25));
			Assert::IsFalse(isPerfectSquare4(30));
			Assert::IsFalse(isPerfectSquare4(123456789));

		}

		TEST_METHOD(sumTree2) {
			std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(10);
			root->left = std::make_shared<TreeNode>(5);
			root->right = std::make_shared<TreeNode>(15);
			root->left->left = std::make_shared<TreeNode>(3);
			root->left->right = std::make_shared<TreeNode>(7);
			root->right->left = std::make_shared < TreeNode>(13);
			root->right->right = std::make_shared<TreeNode>(18);
			int a = sumTree(root);
			Assert::AreEqual(71, a);
		}
		TEST_METHOD(findMiddleNode1) {
			std::shared_ptr<ListNode> head1 = std::make_shared<ListNode>(1);
			head1->next = std::make_shared<ListNode>(2);
			head1->next->next = std::make_shared<ListNode>(3);
			head1->next->next->next = std::make_shared < ListNode>(4);
			head1->next->next->next->next = std::make_shared<ListNode>(5);
			Assert::AreEqual(3, findMiddleNode(head1));


			std::shared_ptr<ListNode> head2 = std::make_shared<ListNode>(1);
			head2->next = std::make_shared<ListNode>(2);
			head2->next->next = std::make_shared<ListNode>(3);
			head2->next->next->next = std::make_shared<ListNode>(4);
			head2->next->next->next->next = std::make_shared<ListNode>(5);
			head2->next->next->next->next->next = std::make_shared<ListNode>(6);
			Assert::AreEqual(4, findMiddleNode(head2));

			std::shared_ptr<ListNode> head3 = std::make_shared<ListNode>(1);
			Assert::AreEqual(1, findMiddleNode(head3));

		}
		TEST_METHOD(sumTree1) {
			std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(10);
			root->left = std::make_shared<TreeNode>(5);
			root->right = std::make_shared<TreeNode>(15);
			root->left->left = std::make_shared<TreeNode>(3);
			root->left->right = std::make_shared<TreeNode>(7);
			root->right->left = std::make_shared < TreeNode>(13);
			root->right->right = std::make_shared<TreeNode>(18);
			int a = sumTree(root);
			Assert::AreEqual(71, a);
		}

		TEST_METHOD(isPalindrome14) {
			std::shared_ptr<ListNode> l1 = nullptr;
			bool a = (isPalindrome(l1));
			Assert::IsTrue(a);

			std::shared_ptr<ListNode> l2 = std::make_shared<ListNode>(1);
			bool b = (isPalindrome(l2));
			Assert::IsTrue(b);


			std::shared_ptr<ListNode> l3 = std::make_shared<ListNode>(1);
			l3->next = std::make_shared<ListNode>(2);
			l3->next->next = std::make_shared<ListNode>(1);
			bool c = isPalindrome(l3);
			Assert::IsTrue(c);

			std::shared_ptr<ListNode> l4 = std::make_shared<ListNode>(1);
			l4->next = std::make_shared<ListNode>(2);
			l4->next->next = std::make_shared<ListNode>(3);
			bool d = isPalindrome(l4);
			Assert::IsFalse(d);


			std::shared_ptr<ListNode> l5 = std::make_shared<ListNode>(1);
			l5->next = std::make_shared<ListNode>(2);
			l5->next->next = std::make_shared<ListNode>(2);
			l5->next->next->next = std::make_shared<ListNode>(1);
			bool e = isPalindrome(l5);
			Assert::IsTrue(e);

			std::shared_ptr<ListNode> l6 = std::make_shared<ListNode>(1);
			l6->next = std::make_shared<ListNode>(2);
			l6->next->next = std::make_shared<ListNode>(3);
			l6->next->next->next = std::make_shared<ListNode>(4);
			bool f = isPalindrome(l6);
			Assert::IsFalse(f);

		}
		TEST_METHOD(sum_of_number13) {
			Assert::AreEqual(11, sum_of_numbers1("hello5world6"));
			Assert::AreEqual(579, sum_of_numbers1("abc123def456"));
			Assert::AreEqual(21, sum_of_numbers1("1a2b3c4d5e6f"));
			Assert::AreEqual(0, sum_of_numbers1("no_numbers_here"));

		}

		TEST_METHOD(maxUniqueSublistSum13) {

			Assert::AreEqual(11, maxUniqueSublistSum({ 5, 2, 1, 3, 2, 4, 1 }));
			Assert::AreEqual(15, maxUniqueSublistSum({ 5, 4, 3, 2, 1 }));
			Assert::AreEqual(15, maxUniqueSublistSum({ 1,2,3,4,5 }));
			Assert::AreEqual(6, maxUniqueSublistSum({ 1,2,3,2,1 }));
			Assert::AreEqual(1, maxUniqueSublistSum({ 1,1,1,1,1 }));
			Assert::AreEqual(0, maxUniqueSublistSum({ }));
			Assert::AreEqual(0, maxUniqueSublistSum({ 0 }));

		}

		TEST_METHOD(maxSumSublist1) {
			Assert::AreEqual(10, maxSumSublist({ 1,2,3,2,5 }));
			Assert::AreEqual(1, maxSumSublist({ 1,1,1,1,1 }));
			Assert::AreEqual(15, maxSumSublist({ 1,2,3,4,5 }));
			Assert::AreEqual(0, maxSumSublist({ 0 }));
			Assert::AreEqual(2, maxSumSublist({ 2,2,2,2,2 }));
			Assert::AreEqual(15, maxSumSublist({ 1,2,3,4,5,1,2,3,4,5 }));
		}
		TEST_METHOD(maxPathSum1) {

			std::shared_ptr<TreeNode> root3 = std::make_shared<TreeNode>(1);
			root3->left = std::make_shared<TreeNode>(2);
			root3->right = std::make_shared<TreeNode>(3);
			Assert::AreEqual(6, maxPathSum(root3));

			std::shared_ptr<TreeNode> root2 = std::make_shared<TreeNode>(1);
			root2->left = std::make_shared<TreeNode>(9);
			root2->right = std::make_shared<TreeNode>(20);
			root2->right->left = std::make_shared<TreeNode>(15);
			root2->right->right = std::make_shared<TreeNode>(7);
			Assert::AreEqual(45, maxPathSum(root2));
		}
		TEST_METHOD(binaryToDecimal12) {
			std::shared_ptr<ListNode> head1 = std::make_shared<ListNode>(1);
			head1->next = std::make_shared<ListNode>(0);
			head1->next->next = std::make_shared<ListNode>(1);
			head1->next->next->next = nullptr;
			int b = binaryToDecimal1(head1);
			Assert::AreEqual(5, b);

			std::shared_ptr<ListNode> head2 = std::make_shared<ListNode>(1);
			head2->next = std::make_shared<ListNode>(1);
			head2->next->next = std::make_shared<ListNode>(1);
			head2->next->next->next = nullptr;
			int a = binaryToDecimal1(head2);
			Assert::AreEqual(7, a);
		}
		TEST_METHOD(addString14)
		{
			std::string a = addStrings12("0", "0");
			std::string exp = "0";
			Assert::AreEqual(exp, a);
			std::string b = addStrings12("0", "1234");
			exp = "1234";
			Assert::AreEqual(exp, b);
			std::string c = addStrings12("456", "0");
			exp = "456";
			Assert::AreEqual(exp, c);
			std::string d = addStrings12("123", "456");
			exp = "579";
			Assert::AreEqual(exp, d);
			std::string e = addStrings12("1001", "999");
			exp = "2000";
			Assert::AreEqual(exp, e);
		}
		TEST_METHOD(merge12) {
			std::vector<int>v = merge({ 1, 3, 5, 7, 9 }, { 2, 4, 6, 8, 10 });
			std::vector<int>exp = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Assert::AreEqual(exp.size(), v.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v[j]);
			}


			std::vector<int>v1 = merge({ 1, 3, 5, 7, 9 }, { 0, 2, 4, 6, 8 });
			exp = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			Assert::AreEqual(exp.size(), v1.size());
			for (int j = 0; j < exp.size(); j++) {
				Assert::AreEqual(exp[j], v1[j]);
			}
		}

		TEST_METHOD(binaryToDecimal11) {
			std::shared_ptr<ListNode> head1 = std::make_shared<ListNode>(1);
			head1->next = std::make_shared<ListNode>(0);
			head1->next->next = std::make_shared<ListNode>(1);
			head1->next->next->next = nullptr;
			int b = getDecimalValue(head1);
			Assert::AreEqual(5, b);

			std::shared_ptr<ListNode> head2 = std::make_shared<ListNode>(1);
			head2->next = std::make_shared<ListNode>(1);
			head2->next->next = std::make_shared<ListNode>(1);
			head2->next->next->next = nullptr;
			int a = getDecimalValue(head2);
			Assert::AreEqual(7, a);
		}

		TEST_METHOD(deleteConsecutiveDuplicate) {
			std::string a = deleteConsecutiveDuplicates("");
			std::string exp = "";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("abcdefg");
			exp = "abcdefg";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("aab");
			exp = "b";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("aabbcc");
			exp = "";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("aabbaacc");
			exp = "";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("aabbaaccd");
			exp = "d";
			Assert::AreEqual(exp, a);

			a = deleteConsecutiveDuplicates("aaaaaa");
			exp = "";
			Assert::AreEqual(exp, a);
		}

		TEST_METHOD(evaluate1) {
			std::string a = evaluate("true ? true : false");
			std::string exp = "true";
			Assert::AreEqual(exp, a);
			a = evaluate("true ? true ? false : true : true");
			exp = "false";
			Assert::AreEqual(exp, a);
		}
		TEST_METHOD(toBase3c) {
			std::string a = toBase31(1);
			std::string exp = "1";
			Assert::AreEqual(exp, a);
			std::string b = toBase31(8);
			exp = "22";
			Assert::AreEqual(exp, b);
			std::string c = toBase31(5);
			exp = "12";
			Assert::AreEqual(exp, c);

		}

		TEST_METHOD(only235PrimeFactors13) {
			Assert::IsTrue(only235PrimeFactors(2));
			Assert::IsTrue(only235PrimeFactors(3));
			Assert::IsTrue(only235PrimeFactors(5));
			Assert::IsTrue(only235PrimeFactors(6));
			Assert::IsTrue(only235PrimeFactors(8));
			Assert::IsTrue(only235PrimeFactors(10));
			Assert::IsTrue(only235PrimeFactors(15));
			Assert::IsTrue(only235PrimeFactors(30));

			Assert::IsFalse(only235PrimeFactors(1));
			Assert::IsFalse(only235PrimeFactors(7));
			Assert::IsFalse(only235PrimeFactors(13));
			Assert::IsFalse(only235PrimeFactors(21));
			Assert::IsFalse(only235PrimeFactors(23));
			Assert::IsFalse(only235PrimeFactors(29));

		}

		TEST_METHOD(maxOperation14) {
			std::vector<int>v = { 1,2,3,4,5 };
			Assert::AreEqual(2, maxOperations1(v, 6));

			std::vector<int>v1 = { 3,1,3,4,3 };
			Assert::AreEqual(1, maxOperations1(v1, 6));

			std::vector<int>v2 = { 1,1,1,1,1 };
			Assert::AreEqual(2, maxOperations1(v2, 2));
		}
		TEST_METHOD(isPalindrome1) {

			std::shared_ptr<ListNode> l1 = nullptr;
			bool a = (isPalindrome(l1));
			Assert::IsTrue(a);

			std::shared_ptr<ListNode> l2 = std::make_shared<ListNode>(1);
			bool b = (isPalindrome(l2));
			Assert::IsTrue(b);

			std::shared_ptr<ListNode> l3 = std::make_shared<ListNode>(1);
			l3->next = std::make_shared<ListNode>(2);
			l3->next->next = std::make_shared<ListNode>(1);
			bool c = isPalindrome(l3);
			Assert::IsTrue(c);

			std::shared_ptr<ListNode> l4 = std::make_shared<ListNode>(1);
			l4->next = std::make_shared<ListNode>(2);
			l4->next->next = std::make_shared<ListNode>(3);
			bool d = isPalindrome(l4);
			Assert::IsFalse(d);

			std::shared_ptr<ListNode> l5 = std::make_shared<ListNode>(1);
			l5->next = std::make_shared<ListNode>(2);
			l5->next->next = std::make_shared<ListNode>(2);
			l5->next->next->next = std::make_shared<ListNode>(1);
			bool e = isPalindrome(l5);
			Assert::IsTrue(e);

			std::shared_ptr<ListNode> l6 = std::make_shared<ListNode>(1);
			l6->next = std::make_shared<ListNode>(2);
			l6->next->next = std::make_shared<ListNode>(3);
			l6->next->next->next = std::make_shared<ListNode>(4);
			bool f = isPalindrome(l6);
			Assert::IsFalse(f);

		}
		TEST_METHOD(evaluate2) {
			std::string a = evaluate11("true ? true : false");
			std::string exp = "true";
			Assert::AreEqual(exp, a);
			a = evaluate11("true ? true ? false : true : true");
			exp = "false";
			Assert::AreEqual(exp, a);
		}

	};
}