#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1 parallel/Lab1 parallel.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1parallel
{
	TEST_CLASS(ParallelTimeTest)
	{
	public:
		
		TEST_METHOD(TestTime)
		{
			int shoots = 50000000;
			float check = 0, tmp = 0;
			for (int hunters = 1; hunters < 12; hunters++) {
				tmp = create_threads(hunters, shoots);
				//std::cout << "Test " << hunters << ": " << tmp;
				Logger::WriteMessage("Test ");
				if (hunters > 1) {
					Assert::IsTrue(tmp < check);
				}
				check = tmp;
			}
		}
	};
}
