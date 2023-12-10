//Destructor
Queue::~Queue()
{
    delete this->list;
    this->list = nullptr;
}

//Makes an empty Queue
void Queue::MakeEmpty()
{
    this->list->makeEmpty();
}

// Other methods to be implemented
