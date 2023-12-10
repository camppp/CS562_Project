// CScope_Impl.h
class CScope_Impl {
public:
    CScope_Impl();
    ~CScope_Impl();

    // ... other methods ...
};

// CHeapScope.h
class CHeapScope {
public:
    CHeapScope();
    ~CHeapScope();

    CScope_Impl* GetImpl();
    CScope* GetScope();

private:
    CScope_Impl* m_pImpl;
};

// CScope_Impl.cpp
#include "CScope_Impl.h"

CScope_Impl::CScope_Impl() {
    // ... constructor implementation ...
}

CScope_Impl::~CScope_Impl() {
    // ... destructor implementation ...
}

// CHeapScope.cpp
#include "CHeapScope.h"

CHeapScope::CHeapScope() {
    m_pImpl = new CScope_Impl();
}

CHeapScope::~CHeapScope() {
    delete m_pImpl;
}

CScope_Impl* CHeapScope::GetImpl() {
    return m_pImpl;
}

CScope* CHeapScope::GetScope() {
    return m_pImpl->GetScope();
}
