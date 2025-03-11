#include "../inc/Manager.hpp"
#include "../inc/ProjectList.hpp"

void Runtime::Manager::selectPID(unsigned short idSelect) {

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
        std::cout << "Multiple Arguments Detected" << std::endl;
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
        this->addrs[i] = proj_ll;
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
        unsigned short n_PID = (unsigned short)std::stoi(this->getArgV()[1]) - 1;
        // default to last project
        selectedPID = n_PID;
        std::cout << "In Branch." << std::endl;
        Node* id_result = this->checkKey(selectedPID);
        if(id_result != nullptr) {
            std::cout << "Current Project ID is: " << id_result->data->getID() << std::endl;
            id_result->data->run();
        }
    }   // simple test complete.
    Node* node = new Node;
    this->pushNode(node);

    return;
}
// checks if key is in map, faster than iterating through linked list. (especially as n gets large.)
Runtime::Node* Runtime::Application::checkKey(int id) {
    auto it = this->addrs.find(id);
    return it != this->addrs.end() ? it->second : nullptr;
}

void Runtime::Application::pushNode(Node* n_node) {
    std::cout << "Test reached" << std::endl;/*
    std::prev(this->addrs.end())->second->n_pointer = &n_node;
    n_node.data = std::make_unique<Runtime::Project>(std::prev(this->addrs.end())->second->data->getID() + 1);
    this->addrs.insert(std::make_pair(n_node.data->getID(), &n_node));
    this->ll_tail = std::prev(this->addrs.end())->second;*/
    return;
}

Runtime::Application::~Application() {
    Node* current_node = this->ll_head;
    Node* next_node = nullptr;
    // delete linked list
    while (current_node != nullptr) {
        next_node = current_node->n_pointer;
        std::cout << "DELETING NODE " << current_node->data->getName() << "\t Node Address:\t" << current_node << std::endl;
        delete current_node;

        // current_node->data is unique_ptr and will auto destruct

        current_node = next_node;
    }
    //std::cout << "ALL NODES DELETED" << std::endl;
    this->ll_head = nullptr;
    this->addrs.clear();

    if (this->addrs.empty()) this->m_size = addrs.size();
}


unsigned short Runtime::Project::getID() {
    return this->PID;
}

void Runtime::Project::setID(unsigned short id) {
    this->PID = id;
    return;
}

int Runtime::Project::run() {
    return 0;
}

Runtime::Project::~Project() {
    //std::cout << "Destructor called!" << std::endl;
    this->PID = 0;
}
