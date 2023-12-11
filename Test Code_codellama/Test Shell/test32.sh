#!/bin/bash

# Set the WORKDIR, TTL, MAGIC, and UTXO_KEY_FILE variables
WORKDIR=$1
TTL=$2
MAGIC=$3
UTXO_KEY_FILE=$4

# Generate the transaction body file
cardano-cli transaction build --work-dir $WORKDIR --ttl $TTL --magic $MAGIC --out-file tx.body

# Construct the cardano-cli command to sign the transaction
cardano-cli transaction sign --tx-body-file tx.body --signing-key-file $UTXO_KEY_FILE --out-file tx.signed

# Execute the cardano-cli command to sign the transaction and produce the signed transaction file
$cardano-cli transaction sign --tx-body-file tx.body --signing-key-file $UTXO_KEY_FILE --out-file tx.signed