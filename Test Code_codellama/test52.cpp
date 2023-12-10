void UltrasoundPointerBasedCalibration::AddCorrespondingPoints(const mitk::Point3D& ultrasoundPoint, const mitk::Point3D& sensorPoint)
{
    // Store the corresponding points in the m_UltrasoundImagePoints and m_SensorPoints point sets
    m_UltrasoundImagePoints->InsertPoint(ultrasoundPoint);
    m_SensorPoints->InsertPoint(sensorPoint);

    // Update the calibration transformation matrix
    mitk::Point3D sensorPointInImageCoordinates = m_SensorPoints->GetPoint(m_SensorPoints->GetNumberOfPoints() - 1);
    mitk::Point3D ultrasoundPointInImageCoordinates = m_UltrasoundImagePoints->GetPoint(m_UltrasoundImagePoints->GetNumberOfPoints() - 1);
    mitk::Point3D translationVector = sensorPointInImageCoordinates - ultrasoundPointInImageCoordinates;
    m_CalibrationTransformationMatrix->SetTranslation(translationVector);
}
