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
			int shoots = 60000000;
			float check = 0, tmp = 0;
			std::string s;
			for (int hunters = 1; hunters <= 12; hunters++) {
				tmp = create_threads(hunters, shoots);
				if (hunters > 1) {
					s = "Test thread " + std::to_string(hunters - 1) + " and " + std::to_string(hunters) + "\n";
					Logger::WriteMessage(s.c_str());
					Assert::IsTrue(tmp < check);
					Logger::WriteMessage("Pass\n\n");
				}
				check = tmp;
			}
		}
	};
}
