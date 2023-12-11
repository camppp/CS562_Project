int createAndCheckVlanMember(int vlanId1, int vlanId2, VlanApi* vlanApi) {
  // Check if the VLAN IDs are distinct
  if (vlanId1 == vlanId2) {
    return -1;
  }

  // Create a VLAN member for the second VLAN ID
  VlanApiParameters::MemberAttributes attributes;
  attributes.vlanId = VlanId(vlanId2);
  attributes.bridgePortId = BridgePortId(0);
  int memberId = vlanApi->createMember(attributes, 0);

  // Check if the VLAN member was created successfully
  if (memberId < 0) {
    return -1;
  }

  // Check if the VLAN member exists for the given VLAN ID and member ID
  if (!checkVlanMember(vlanId2, memberId)) {
    return -1;
  }

  return 0;
}
