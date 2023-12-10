class CChatterDetectionSystem
{
public:
    CChatterDetectionSystem();
    ~CChatterDetectionSystem();
    void Run(double measurement, double spindleSpeed);

private:
    KalmanFilter* m_kalmanFilter;
    BandpassFilters* m_bandpassFilters;
    NEO* m_neo;
    MeanFilter* m_meanFilter;
    ChatterDetection* m_chatterDetection;
};

CChatterDetectionSystem::CChatterDetectionSystem()
{
    m_kalmanFilter = new KalmanFilter();
    m_bandpassFilters = new BandpassFilters();
    m_neo = new NEO();
    m_meanFilter = new MeanFilter();
    m_chatterDetection = new ChatterDetection();
}

CChatterDetectionSystem::~CChatterDetectionSystem()
{
    delete m_kalmanFilter;
    delete m_bandpassFilters;
    delete m_neo;
    delete m_meanFilter;
    delete m_chatterDetection;
}

void CChatterDetectionSystem::Run(double measurement, double spindleSpeed)
{
    // Use the measurement and spindle speed to perform chatter detection
    // using the various components of the system.
    // For example:
    m_kalmanFilter->Filter(measurement);
    m_bandpassFilters->Filter(measurement);
    m_neo->Detect(measurement, spindleSpeed);
    m_meanFilter->Filter(measurement);
    m_chatterDetection->Detect(measurement, spindleSpeed);
}
