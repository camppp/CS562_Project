size_t Output_Buffers::peek(byte output[], size_t length, Pipe::message_id msg)
{
    // Check if the queue associated with the given message ID exists
    if (queues.find(msg) != queues.end())
    {
        // Read up to 'length' bytes of data from the queue and store it in the 'output' array
        size_t bytes_read = queues[msg]->read(output, length);

        // Return the number of bytes read
        return bytes_read;
    }
    else
    {
        // Return 0 if the queue does not exist
        return 0;
    }
}
