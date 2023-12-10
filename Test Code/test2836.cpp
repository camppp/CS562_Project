/**
*  @brief
*    Copy operator
*/
inline Line &Line::operator =(const Line &cSource)
{
    // Check for self-assignment
    if (this != &cSource) {
        // Perform deep copy of data
        vStart = cSource.vStart;
        vEnd = cSource.vEnd;
    }
    // Return this
    return *this;
}
