void UltrasoundPointerBasedCalibration::AddCorrespondingPoints(const mitk::Point3D& ultrasoundPoint, const mitk::Point3D& sensorPoint)
{
  // Add corresponding points to the point sets
  m_UltrasoundImagePoints->InsertPoint(m_UltrasoundImagePoints->GetSize(), ultrasoundPoint);
  m_SensorPoints->InsertPoint(m_SensorPoints->GetSize(), sensorPoint);

  // Perform calibration using the added points
  if (m_UltrasoundImagePoints->GetSize() >= 3 && m_SensorPoints->GetSize() >= 3)
  {
    // Calculate transformation matrix using the added corresponding points
    vtkSmartPointer<vtkLandmarkTransform> landmarkTransform = vtkSmartPointer<vtkLandmarkTransform>::New();
    vtkSmartPointer<vtkPoints> ultrasoundVtkPoints = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkPoints> sensorVtkPoints = vtkSmartPointer<vtkPoints>::New();

    // Convert mitk::PointSet to vtkPoints
    for (int i = 0; i < m_UltrasoundImagePoints->GetSize(); i++)
    {
      mitk::Point3D ultrasoundPt = m_UltrasoundImagePoints->GetPoint(i);
      mitk::Point3D sensorPt = m_SensorPoints->GetPoint(i);
      ultrasoundVtkPoints->InsertNextPoint(ultrasoundPt[0], ultrasoundPt[1], ultrasoundPt[2]);
      sensorVtkPoints->InsertNextPoint(sensorPt[0], sensorPt[1], sensorPt[2]);
    }

    landmarkTransform->SetSourceLandmarks(ultrasoundVtkPoints);
    landmarkTransform->SetTargetLandmarks(sensorVtkPoints);
    landmarkTransform->SetModeToRigidBody();
    landmarkTransform->Update();

    // Update the calibration transformation matrix
    vtkMatrix4x4* calibrationMatrix = landmarkTransform->GetMatrix();
    m_RigidBodyMatrix->DeepCopy(calibrationMatrix);
  }
}
