#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_01rec/Lab_07_01rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0701rec
{
	TEST_CLASS(UnitTest0701rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowcount = 7;
			int colcount = 6;

			int** a = new int* [rowcount];
			for (int i = 0; i < rowcount; i++)
				a[i] = new int[colcount];

			Generate(a, rowcount, colcount, 1, 1, 0, 0);
			Assert::AreEqual(a[1][1], 1);
		}
	};
}
