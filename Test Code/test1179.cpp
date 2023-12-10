size_t SizeInBytes() const
{
    // Calculate the size of the hash table in bytes based on the number of items and the given configuration
    return (size * 11.7 / 8) + 100;
}
