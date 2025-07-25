#include "../inc/Manager.hpp"
#include "../inc/ProjectList.hpp"
#include <iostream>

void Runtime::Manager::selectPID(unsigned short idSelect) {
    this->currentPID = idSelect;
}

int Runtime::Manager::getArgc() {
    return this->argc;
}

char** Runtime::Manager::getArgV() {
    // TODO: Tokenize and parse argv

    return this->argv;
}

int Runtime::Application::processCMDs() {
    unsigned int argcount = this->getArgc();
    char ** argdata = this->getArgV();

    if (argcount > 1) {
        std::cout << "Multiple Arguments Detected" << std::endl << "Arg Count: " << argcount << std::endl;
        std::cout << "Arg Data: " << std::endl;
        for (unsigned int i = 0; i < argcount; i++) {
            std::cout << "Arg " << i << ": " << argdata[i] << std::endl;
        }   
        return argcount;
    } else {
        std::cout << "No Further Args Supplied" << std::endl;
    }

    return 0;
}

void Runtime::Application::run() {
    // Implement Main Application Here
    // Add new ProjectList
    std::unique_ptr<Projects::ProjectList> pl = std::make_unique<Projects::ProjectList>();

    int projectCount = pl->getProjectCount();

    const short PID_L = projectCount;
    unsigned short selectedPID = 2;

    // Implement Linked List Containing Project Data
    Node* proj_ll = new Node;
    Node* c_pointer = proj_ll;

    proj_ll->data = pl->getProject(0);

    const Node* proj_list_head = proj_ll;

    this->ll_head = proj_ll;

    unsigned short size = 1;

    for (int i = 0; i < PID_L; i++) {
        this->addrs[i + 1] = proj_ll;
        if (i == 0) {
            proj_ll->p_pointer = nullptr;
        }
        // set n_pointer
        if ((unsigned short)i != (PID_L - 1)) {
            proj_ll->n_pointer = new Node;
            proj_ll->n_pointer->data = pl->getProject(i + 1);
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

    // reset linked list pointer
    proj_ll = (Node*)proj_list_head;

    // an unordered_map is important to use because this will speed up data access by
    // pointing directly to each address, and an unordered map does not need to be sorted
    // which is also important because nodes may be inserted or deleted at any point
    // and the Nodes are found via project ID. This map will be used as the main traversal
    // method.

    if (this->getArgc() > 1) {
        // get 2nd argument
        const unsigned short n_PID = static_cast<unsigned short>(std::stoi(this->getArgV()[1]));
        // default to last project
        selectedPID = n_PID;
        std::cout << "In Branch." << std::endl;
        if (const Node* id_result = this->checkKey(selectedPID)) {
            std::cout << "Current Project ID is: " << id_result->data->getID() << std::endl;
            id_result->data->run();
        }
    }

    }

void Runtime::Application::pushNode(Node* node) {
    // Adds node to the beginning of the linked list
    if (!this->ll_head) {
        this->ll_head = node;
        this->ll_tail = node;
    } else {
        node->n_pointer = this->ll_head;
        this->ll_head->p_pointer = node;
        this->ll_head = node;
    }
}

void Runtime::Application::dequeueNode() {
    // Removes node from the end of the linked list
    if (!this->ll_head) return;
    if (!this->ll_tail) return;
    Node* temp = this->ll_tail;

    this->ll_tail = this->ll_tail->p_pointer;

    if (this->ll_tail) {
        this->ll_tail->n_pointer = nullptr;
    }
    delete temp;
}

void Runtime::Application::removeNode(Node* n_node) {
    int map_id = n_node->data->getID();
    if (!n_node) {
        return;
    }
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

void Runtime::Application::removeNode(const int id) {
    if(Node* node = this->checkKey(id); node != nullptr) {
        this->removeNode(node);
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
    //std::cout << "ALL NODES DELETED" << std::endl;
    this->ll_head = nullptr;
    this->ll_tail = nullptr;

    // check if addrs is not empty before clearing
    if (!this->addrs.empty()) {
        std::cout << "Clearing addrs map..." << std::endl;

        for (auto& [fst, snd] : this->addrs) {
            std::cout << "Deleting Node with ID: " << fst << "\t Address: " << snd << std::endl;
            delete snd; // delete the Node pointer
        }
    }


    this->addrs.clear();

    if (this->addrs.empty()) this->m_size = addrs.size();
}


unsigned short Runtime::Project::getID() {
    return this->PID;
}

void Runtime::Project::setID(unsigned short id) {
    this->PID = id;
}

int Runtime::Project::run() {
    return 0;
}

Runtime::Project::~Project() {
    //std::cout << "Destructor called!" << std::endl;
    this->PID = 0;
}
