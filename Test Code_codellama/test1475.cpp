#include <iostream>

struct _IO_COUNTERS
{
    unsigned __int64 ReadOperationCount;
    unsigned __int64 WriteOperationCount;
};

void updateReadCount(_IO_COUNTERS& ioCounters, int readCount)
{
    ioCounters.ReadOperationCount += readCount;
}

void updateWriteCount(_IO_COUNTERS& ioCounters, int writeCount)
{
    ioCounters.WriteOperationCount += writeCount;
}

void displayIOCount(const _IO_COUNTERS& ioCounters)
{
    std::cout << "Read Operations: " << ioCounters.ReadOperationCount << std::endl;
    std::cout << "Write Operations: " << ioCounters.WriteOperationCount << std::endl;
}

int main()
{
    _IO_COUNTERS ioCounters = {0, 0};

    updateReadCount(ioCounters, 5);
    updateWriteCount(ioCounters, 3);
    displayIOCount(ioCounters);

    return 0;
}
