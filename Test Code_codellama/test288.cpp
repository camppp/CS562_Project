class DataBuffer {
private:
    // Member variables
    vector<int> idx_buffer_;
    vector<Tensor*> global_buffer_;
    int batch_size_;
    int working_signal_;
    int num_of_each_dataset_member_;
    string dataset_;

public:
    // Constructor
    DataBuffer(int batch_size, int working_signal, int num_of_each_dataset_member, string dataset) {
        this->batch_size_ = batch_size;
        this->working_signal_ = working_signal;
        this->num_of_each_dataset_member_ = num_of_each_dataset_member;
        this->dataset_ = dataset;
    }

    // Methods
    vector<int>* GetIdxSetFromIdxBuffer() {
        return &idx_buffer_;
    }

    Tensor* Concatenate(queue<Tensor*> tensor_queue) {
        // Concatenate the tensors in the queue
        Tensor* concatenated_tensor = new Tensor(tensor_queue.size());
        for (int i = 0; i < tensor_queue.size(); i++) {
            concatenated_tensor->Add(tensor_queue.front());
            tensor_queue.pop();
        }
        return concatenated_tensor;
    }

    void Push2GlobalBuffer(vector<Tensor*> tensor_vector) {
        // Add the tensor vector to the global buffer
        for (int i = 0; i < tensor_vector.size(); i++) {
            global_buffer_.push_back(tensor_vector[i]);
        }
    }

    vector<Tensor*> GetDataFromGlobalBuffer() {
        // Retrieve the data from the global buffer
        return global_buffer_;
    }

    int GetBatchSize() {
        return batch_size_;
    }

    int GetWorkingSignal() {
        return working_signal_;
    }

    int GetNumOfEachDatasetMember() {
        return num_of_each_dataset_member_;
    }

    string GetDataset() {
        return dataset_;
    }
};
