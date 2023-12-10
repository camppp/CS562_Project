void configureBillboardRendering(osg::Node* m_pTrans) {
    // Set the rendering bin details to ensure proper ordering
    m_pTrans->getOrCreateStateSet()->setRenderBinDetails(-100001, "RenderBin");

    // Set the render order for nested rendering
    m_pTrans->setRenderOrder(osg::Camera::NESTED_RENDER);

    // Set the compute near/far mode using bounding volumes
    m_pTrans->setComputeNearFarMode(osg::CullSettings::COMPUTE_NEAR_FAR_USING_BOUNDING_VOLUMES);

    // Create and configure the billboard
    osg::ref_ptr<osg::Billboard> bd = new osg::Billboard;
    bd->setMode(osg::Billboard::POINT_ROT_EYE);

    // Add the billboard to the node's state set
    m_pTrans->getOrCreateStateSet()->setAttributeAndModes(bd, osg::StateAttribute::ON);
}
