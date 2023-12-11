#!/bin/bash

# Unset any existing AWS environment variables
unset AWS_ACCESS_KEY_ID
unset AWS_SECRET_ACCESS_KEY
unset AWS_SESSION_TOKEN

# Ensure the script exits immediately if any command exits with a non-zero status
set -e

# Determine the directory of the script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Read the stack prefix from the conf.json file
STACK_PREFIX=$(jq -r '.stack_prefix' "$DIR/../conf.json")

# Construct the role name
ROLE_NAME="$STACK_PREFIX-deployer"

# Obtain the AWS account ID
ACCOUNT_ID=$(aws sts get-caller-identity --query 'Account' --output text)

# Assume the role
TEMP_ROLE=$(aws sts assume-role --role-arn "arn:aws:iam::$ACCOUNT_ID:role/$ROLE_NAME" --role-session-name "my-session")

# Extract the temporary AWS access key ID
AWS_ACCESS_KEY_ID=$(echo $TEMP_ROLE | jq -r '.Credentials.AccessKeyId')

# Export the temporary AWS access key ID as an environment variable
export AWS_ACCESS_KEY_ID

# Output the temporary AWS access key ID
echo "Temporary AWS access key ID: $AWS_ACCESS_KEY_ID"