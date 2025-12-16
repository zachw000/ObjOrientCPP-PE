//
// Created by Zachary Waldron on 9/28/25.
//
#include <Manager.hpp>
#include <iostream>
/**
 * An example implementation of this library.
 */
int main(int argc, char **argv) {
    // Application timer
    const unsigned long timer_start = clock();

    int RET_CODE = 0;
    // theory: use a unique pointer to manage memory, and custom linked list implementation
    // will de-allocate upon loss of scope. during the execution process heap-allocate all
    // project data for larger memory store; meanwhile use std::unordered_map in conjunction
    // with the doubly-linked list to store a hash map of the addresses of each node for access
    // speed.
    {
        using namespace Runtime;
        const auto app = std::make_unique<Application>(argc, argv);
        app->processCMDs();

        try {
            bool running = true;
            app->run();
            while (running) {
                std::cout << "Process Finished. Execute another? Enter a project number 1-6: " << std::endl;
                std::string proj;
                std::cin >> proj;
                if (std::stoi(proj) < 1 || std::stoi(proj) > 6) running = false;
                std::cout << "Selecting Project #" << proj << std::endl;
                std::cout << "Continuing. . ." << std::endl;
                unsigned short PID = std::stoi(proj);
                app->setProject(PID);
            }
            RET_CODE = app ? 0 : 1;
            std::cout << "Application Created Successfully" << std::endl;
        } catch (std::bad_alloc &e) {
            std::cerr << "Insufficient Memory" << e.what() << std::endl;
            RET_CODE = 2;
        } catch (std::invalid_argument &e) {
            std::cerr << "Quitting Application. . ." << std::endl;
        } catch (std::out_of_range &e) {
            std::cerr << "Quitting Application. . ." << std::endl;
        } catch (std::exception &e) {
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

    std::cout << "Calculation ran for " << static_cast<float>(clock() - timer_start) / CLOCKS_PER_SEC << " second(s)!"
        << std::endl;

    return RET_CODE;
}