#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP3.3E/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest32
{
	TEST_CLASS(UnitTest32)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Object obj;
			Assert::AreEqual(obj.getI(), 1);
		}
	};
}