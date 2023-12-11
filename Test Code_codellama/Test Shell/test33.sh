provision_vsphere_vm() {
  local ssh_bastion_key_contents="$1"
  local output_file="$2"

  # Replace occurrences of \n with actual newline characters
  ssh_bastion_key_contents=$(echo "$ssh_bastion_key_contents" | sed 's/\\n/\n/g')

  # Append the modified content to a file named vsphere-tests.pem
  echo "$ssh_bastion_key_contents" >> vsphere-tests.pem

  # Change the permissions of the vsphere-tests.pem file to 600
  chmod 600 vsphere-tests.pem

  # Process the template file packer-vsphere-airgap.yaml.tmpl using envsubst
  envsubst < packer-vsphere-airgap.yaml.tmpl >> "$output_file"
}