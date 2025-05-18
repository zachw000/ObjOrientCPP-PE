#include <Manager.hpp>
#include <iostream>
/**
 * An example implementation of this library.
 */
int main(int argc, char **argv) {
	// Application timer
	unsigned long timer_start = clock();

	int RET_CODE = 0;
	// theory: use a unique pointer to manage memory, and custom linked list implementation
	// will de-allocate upon loss of scope. during the execution process heap-allocate all
	// project data for larger memory store; meanwhile use std::unordered_map in conjunction
	// with the doubly-linked list to store a hash map of the addresses of each node for access
	// speed.
	{
	    std::unique_ptr<Runtime::Application> app =
			std::make_unique<Runtime::Application>(argc, argv);
		app->processCMDs();

		try {
			app->run();
			RET_CODE = app ? 0 : 1;
		} catch (std::bad_alloc e) {
			std::cerr << "Insufficient Memory" << std::endl;
			RET_CODE = 2;
		} catch (std::exception e) {
			std::cerr << "Unknown Runtime Exception: " << e.what() <<
				std::endl << &e << std::endl;
			RET_CODE = -1;
		}
		// if ret_code is nonzero end operation (exit with error)
		if (RET_CODE)	return RET_CODE;

		// create unordered map of addresses (done)
		// TODO: Implement getter for addresses of ll_head/ll_tail (done)
		// TODO: Implement iterator function for iterating through ll (done)

		std::cout << "Done." << std::endl;
	}	// end of scope

	std::cout << "Application ran for " << static_cast<float>(clock() - timer_start) / CLOCKS_PER_SEC << " seconds." << std::endl;

	return RET_CODE;
}