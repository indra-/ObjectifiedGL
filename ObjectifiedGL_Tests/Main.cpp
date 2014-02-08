#include <UnitTest++.h>
#include <iostream>

  int main()
  {
    UnitTest::RunAllTests();
	std::cout << "Press any key to continue . . ." << std::endl;
	std::getchar();
	
	return 0;
  }