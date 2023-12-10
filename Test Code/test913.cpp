void DetachSim()
{
    if (m_BodyRef)
    {
        m_BodyRef->DetachSim();
        m_BodyRef = nullptr;
    }
}
