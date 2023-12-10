void configureBillboardRendering(osg::Node* m_pTrans)
{
    // Create a new state set for the billboard
    osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;

    // Set the render bin details for the billboard
    stateSet->setRenderBinDetails( -100001, "RenderBin" );

    // Set the render order for the billboard
    m_pTrans->setRenderOrder(osg::Camera::NESTED_RENDER);

    // Set the compute near far mode for the billboard
    m_pTrans->setComputeNearFarMode(osg::CullSettings::COMPUTE_NEAR_FAR_USING_BOUNDING_VOLUMES);

    // Create a new billboard node
    osg::ref_ptr<osg::Billboard> bd = new osg::Billboard;

    // Set the mode for the billboard
    bd->setMode(osg::Billboard::POINT_ROT_EYE);

    // Add the billboard to the state set
    stateSet->addChild(bd);

    // Set the state set for the billboard
    m_pTrans->setStateSet(stateSet);
}
