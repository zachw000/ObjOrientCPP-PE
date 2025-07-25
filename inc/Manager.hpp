#pragma once
#include <memory>
#include <string_view>
#include <string>
#include <unordered_map>


#ifndef RUNTIME_MANAGER
#define RUNTIME_MANAGER

namespace Runtime {
    class Manager {
    protected:
        //  Processes CMD line inputs
        int argc;
        char **argv;
        unsigned short currentPID{};
        static constexpr unsigned short maxPID = 0x4;
    public:
        virtual int processCMDs() = 0;  // Returns integer exit code; Default = 0
        Manager(const int Argc, char **Argv) : argc(Argc), argv(Argv) {}
        Manager() : argc(0), argv(static_cast<char**>(nullptr)), currentPID(0)
        {
        }

        virtual ~Manager() = default;

        void selectPID(unsigned short  idSelect);
        int getArgc();
        char** getArgV();

        virtual void run() = 0;
    };

    class Project {
    private:
        unsigned short PID;
        std::string p_name = "Default Project";
    public:
        explicit Project(const int id) : PID(id) {}
        Project() : PID(0) {}
        virtual ~Project();
        virtual int run();
        [[nodiscard]] virtual std::string_view getName() const {
            return this->p_name;
        }

        void setID(unsigned short id);

        virtual unsigned short getID();
    };

    typedef struct Node {
        Node* n_pointer;
        Node* p_pointer;
        std::unique_ptr<Runtime::Project> data;
    } Node;
    // Linked List Node Structure

    class Application : private Manager {
    private:
        Node* ll_head = nullptr;
        Node* ll_tail = nullptr;
        // map integers to node* to create quick access to any node
        std::unordered_map<int, Node*> addrs;
        ssize_t m_size = 0;
        Node* checkKey(int id);
        void queueNode(Node* n_node); // adds node to the end of the linked list
        void dequeueNode(); // removes node from the end of the linked list
        void pushNode(Node* n_node); // adds node to the beginning of the linked list
        void popNode(); // Pops the first node from the beginning of the linked list
        void insertNode(Node* n_node, Node* prev_node); // inserts node after prev_node
        void removeNode(Node* n_node); // removes node from the linked list
        void insertNode(int id, Node* n_node); // inserts node after node with id
        void removeNode(int id); // removes node from the linked list by id
    public:
        Project* getProjectByID(size_t id);

        int processCMDs() override;
        void run() override;

        Application(int Argc, char **Argv) : Manager(Argc, Argv) {};
        Application() : Manager() {}
        ~Application() override;
    };

};
#endif
