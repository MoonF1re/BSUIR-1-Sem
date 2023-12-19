#include <string>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1_PPOIS/Set.h"
#include "../Lab1_PPOIS/CantorSet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetUnitTest
{
	TEST_CLASS(SetUnitTest)
	{
	public:

		TEST_METHOD(TestConstructWithElement)
		{
			Set set{ "{a}" };
			Assert::AreEqual(static_cast<size_t>(1), set.cardinality());
		}
		TEST_METHOD(TestConstrucWithVector)
		{
			std::vector<char> testVector = {'a','b','c'};
			Set set(testVector);
			Assert::AreEqual<size_t>(1, set.cardinality());
		}

		TEST_METHOD(TestAddElement)
		{
			Set set("{a}");
			set.addElement("b");
			Assert::AreEqual<size_t>(2, set.cardinality());
		}

		TEST_METHOD(TestRemoveElement)
		{
			Set set("{a, b}");
			set.removeElement("b");
			Assert::AreEqual<size_t>(1, set.cardinality());
		}

		TEST_METHOD(TestUnionOperator)
		{
			Set set1("{a}");
			Set set2("{b}");
			Set resultSet = set1 + set2;
			Assert::AreEqual<size_t>(2, resultSet.cardinality());
		}

		TEST_METHOD(TestIntersectionOperator)
		{
			Set set1("{a}");
			Set set2("{a}");
			Set resultSet = set1 * set2;
			Assert::AreEqual<size_t>(1, resultSet.cardinality());
		}

		TEST_METHOD(TestDifferenceOperator)
		{
			Set set1("{a}");
			Set set2("{a}");
			Set resultSet = set1 - set2;
			Assert::AreEqual<size_t>(0, resultSet.cardinality());
		}

		TEST_METHOD(TestIndexOperator)
		{
			Set set("{a}");
			set.addElement("b");
			set.addElement("c");
			Set resultSet = set["c"];
			Assert::AreEqual<size_t>(1, resultSet.cardinality());
		}

		TEST_METHOD(TestBooleanSet)
		{
			Set set("{a}");
			set.addElement("b");
			Set resultSet = set.booleanSet(set);
			Assert::AreEqual<size_t>(4, resultSet.cardinality()); //{},{a},{b},{a,b}
		}
		TEST_METHOD(TestContainsElement)
		{
			Set set("a");
			bool cont = true;
			Assert::AreEqual(set.contains("a"), true);
		}
	};
}
