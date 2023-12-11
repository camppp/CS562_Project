provision_vsphere_vm() {
    # Replace occurrences of '\\n' with actual newline characters
    local key_contents=$(echo "$1" | sed's/\\n/\n/g')

    # Append the modified content to a file named 'vsphere-tests.pem'
    echo "$key_contents" >> vsphere-tests.pem

    # Change the permissions of the 'vsphere-tests.pem' file to 600
    chmod 600 vsphere-tests.pem

    # Process the template file 'packer-vsphere-airgap.yaml.tmpl' using 'envsubst'
    # and append the result to the file specified by the second argument
    envsubst < packer-vsphere-airgap.yaml.tmpl >> "$2"
}

provision_vsphere_vm "$SSH_BASTION_KEY_CONTENTS" "/path/to/output/file"