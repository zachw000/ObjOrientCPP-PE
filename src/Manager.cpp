#include "../inc/Manager.hpp"
#include "../inc/ProjectList.hpp"
#include <iostream>
#include "Manager.hpp"

void Runtime::Manager::selectPID(const unsigned short idSelect) {
    this->currentPID = idSelect;
}

int Runtime::Manager::getArgc() const {
    return this->argc;
}

char** Runtime::Manager::getArgV() const {
    // TODO: Tokenize and parse argv

    return this->argv;
}

void Runtime::Application::setProject(unsigned short PID) {
    this->selectPID(PID);
    Node* proj = this->checkKey(PID);
    if (!proj) return;
    proj->data->run();
    return;
}

void Runtime::Application::executeProject(std::unique_ptr<Node> proj_addrs) {
    proj_addrs->data->run();
    return;
}

unsigned int Runtime::Application::processCMDs() {
    const unsigned int arg_count = this->getArgc();
    char ** arg_data = this->getArgV();

    if (arg_count > 1) {
        std::cout << "Multiple Arguments Detected" << std::endl << "Arg Count: " << arg_count << std::endl;
        std::cout << "Arg Data: " << std::endl;
        for (unsigned int i = 0; i < arg_count; i++) {
            std::cout << "Arg " << i << ": " << arg_data[i] << std::endl;
        }   
        return arg_count;
    }

    std::cout << "No Further Args Supplied" << std::endl;


    return 0;
}

void Runtime::Application::run() {
    // Implement Main Application Here
    // Add new ProjectList
    auto pl = std::make_unique<Projects::ProjectList>();

    const short projectCount = Projects::ProjectList::getProjectCount();
    const short PID_L = projectCount;

    // Implement Linked List Containing Project Data
    auto proj_ll = new Node;
    Node* c_pointer = proj_ll;

    proj_ll->data = Projects::ProjectList::getProject(0);

    this->ll_head = proj_ll;

    unsigned short size = 1;

    for (int i = 0; i < PID_L; i++) {
        this->addrs[i + 1] = proj_ll;
        if (i == 0) {
            proj_ll->p_pointer = nullptr;
        }
        // set n_pointer
        if (static_cast<unsigned short>(i) != (PID_L - 1)) {
            proj_ll->n_pointer = new Node;
            proj_ll->n_pointer->data = Projects::ProjectList::getProject(i + 1);
            proj_ll->n_pointer->p_pointer = c_pointer;

            size++;
            // set current pointer to next node
            proj_ll = proj_ll->n_pointer;
        } else {
            proj_ll->n_pointer = nullptr;
        }
        // set current pointer to new project (or ending project)
        c_pointer = proj_ll;
    }

    this->m_size = size;

    this->ll_tail = proj_ll;

    // an unordered_map is important to use because this will speed up data access by
    // pointing directly to each address, and an unordered map does not need to be sorted
    // which is also important because nodes may be inserted or deleted at any point
    // and the Nodes are found via project ID. This map will be used as the main traversal
    // method.

    // TODO: Replace the below code with an application loop.
    if (this->getArgc() > 1) {
        // default to 2nd project
        unsigned short selectedPID = 2;
        // get 2nd argument
        const unsigned short n_PID = static_cast<unsigned short>(std::stoi(this->getArgV()[1]));
        selectedPID = n_PID > 0 && n_PID <= PID_L ? n_PID : selectedPID;
        std::cout << "In Branch." << std::endl;
        if (const Node* id_result = this->checkKey(selectedPID)) {
            std::cout << "Current Project ID is: " << id_result->data->getID() << std::endl;
            id_result->data->run();
        }
    }
}

void Runtime::Application::pushNode(Node* n_node) {
    // Adds node to the beginning of the linked list
    if (!this->ll_head) {
        this->ll_head = n_node;
        this->ll_tail = n_node;
    } else {
        n_node->n_pointer = this->ll_head;
        this->ll_head->p_pointer = n_node;
        this->ll_head = n_node;
    }
}

void Runtime::Application::dequeueNode() {
    // Removes node from the end of the linked list
    if (!this->ll_head) return;
    if (!this->ll_tail) return;
    const Node* temp = this->ll_tail;

    this->ll_tail = this->ll_tail->p_pointer;

    if (this->ll_tail) {
        this->ll_tail->n_pointer = nullptr;
    }
    delete temp;
}

void Runtime::Application::removeNode(const Node* n_node) {
    const int map_id = n_node->data->getID();
    if(n_node == this->ll_head) {
        this->ll_head = n_node->n_pointer;
    }
    if(n_node == this->ll_tail) {
        this->ll_tail = n_node->p_pointer;
    }
    if(n_node->p_pointer != nullptr) {
        n_node->p_pointer->n_pointer = n_node->n_pointer;
    }
    if(n_node->n_pointer != nullptr) {
        n_node->n_pointer->p_pointer = n_node->p_pointer;
    }
    delete n_node;

    // Delete the node from the map
    this->addrs.erase(map_id);
}

void Runtime::Application::insertNode(int id, Node* n_node) {
    std::cout << id << std::endl;
    std::cout << n_node->data->getID() << std::endl;
}

Runtime::Project* Runtime::Application::getProjectByID(unsigned short id)
{
    return this->checkKey(id)->data.get();
}

void Runtime::Application::removeNode(const int id) {
    if(const Node* node = this->checkKey(id); node != nullptr) {
        this->removeNode(node);
    }
}

void Runtime::Application::validateMap() {
    // check if addrs is not empty before clearing
    // NOTE: Not expected to execute during normal operation
    if (!this->addrs.empty()) {
        printf("\x1B[31mAssertion(s) Failed, Node(s) detected outside LL\033[0m\t\t\n");
        std::cout << "Clearing addrs map..." << std::endl;

        for (auto& [fst, snd] : this->addrs) {
            std::cout << "Deleting Node with ID: " << fst << "\t Address: " << snd << std::endl;
            delete snd; // delete the Node pointer
        }

        this->addrs.clear();

        if (this->addrs.empty()) this->m_size = addrs.size();
    }
}

void Runtime::Application::queueNode(Node* n_node) {
    std::cout << "Test reached" << std::endl;
    // Purpose of this function is to add a new node to the end of the linked list.
    this->ll_tail->n_pointer = n_node;
    n_node->n_pointer = nullptr;

    // If the project in the node is null, create a new project with an ID based on the size of the address map.
    if (!n_node->data) {
        n_node->data = std::make_unique<Runtime::Project>(this->addrs.size() + 1);
    }

    this->addrs.insert(std::make_pair(n_node->data->getID(), n_node));
    this->ll_tail = n_node;
}

void Runtime::Application::popNode() {
    if (this->ll_head == nullptr) return;

    const Node* temp = this->ll_head;
    this->ll_head = this->ll_head->n_pointer;
    this->addrs.erase(temp->data->getID());
    delete temp;
    this->m_size--;
}

// inserts new node (n_node) after prev_node
void Runtime::Application::insertNode(Runtime::Node* n_node, Runtime::Node* prev_node) {
    if (prev_node == nullptr) {
        std::cerr << "Error: prev_node is null, node cannot be inserted!" << std::endl;
        return;
    }
    n_node->n_pointer = prev_node->n_pointer;
    prev_node->n_pointer = n_node;
    n_node->p_pointer = prev_node;

    if (n_node->n_pointer != nullptr) {
        n_node->n_pointer->p_pointer = n_node;
    }
    prev_node->n_pointer = n_node;
    n_node->p_pointer = prev_node;
    // add to map
    this->addrs.insert(std::make_pair(n_node->data->getID(), n_node));
    // increment size   
    this->m_size++;
}

// checks if key is in map, faster than iterating through linked list. (especially as n gets large.)
Runtime::Node* Runtime::Application::checkKey(const int id) {
    const auto it = this->addrs.find(id);
    return it != this->addrs.end() ? it->second : nullptr;
}

Runtime::Application::~Application() {
    const Node* current_node = this->ll_head;
    const Node* next_node = nullptr;
    // delete linked list
    while (current_node != nullptr) {
        next_node = current_node->n_pointer;
        // remove from map by ID
        this->addrs.erase(current_node->data->getID());
        // delete the node
        // Note: current_node->data is a unique_ptr, so it will be automatically destruct
        // when current_node is deleted.
        std::cout << "DELETING NODE " << current_node->data->getName() << "\t Node Address:\t" << current_node << std::endl;
        delete current_node;

        // current_node->data is unique_ptr and will auto destruct

        current_node = next_node;
    }
    // All nodes deleted
    this->ll_head = nullptr;
    this->ll_tail = nullptr;
    this->validateMap();

    printf("\x1B[32mNodes cleared.\033[0m\t\t\n");

    this->addrs.clear();

    if (this->addrs.empty()) this->m_size = addrs.size();
}


unsigned short Runtime::Project::getID() {
    return this->PID;
}

void Runtime::Project::setID(const unsigned short id) {
    this->PID = id;
}

int Runtime::Project::run() {
    return 0;
}

Runtime::Project::~Project() {
    // Reset Project ID to 0
    this->PID = 0;
}

Runtime::Node::~Node()
{

}