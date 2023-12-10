size_t Output_Buffers::peek(byte output[], size_t length, Pipe::message_id msg)
{
   SecureQueue* q = get(msg); // Assume get(msg) returns the SecureQueue associated with the given message ID
   if(q)
      return q->read(output, length); // Read up to 'length' bytes of data from the queue and store it in the 'output' array
   return 0; // Return 0 if the queue associated with the given message ID does not exist
}
