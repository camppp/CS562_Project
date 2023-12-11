#!/bin/bash

# Check if all required parameters are provided
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 WORKDIR TTL MAGIC UTXO_KEY_FILE"
    exit 1
fi

WORKDIR=$1
TTL=$2
MAGIC=$3
UTXO_KEY_FILE=$4

# Generate the transaction body file
cardano-cli transaction build-raw \
    --tx-in <UTXO> \
    --tx-out <RECEIVER_ADDRESS>+<AMOUNT> \
    --ttl $TTL \
    --fee 0 \
    --out-file $WORKDIR/tx.raw

# Sign the transaction
cardano-cli transaction sign \
    --tx-body-file $WORKDIR/tx.raw \
    --signing-key-file $UTXO_KEY_FILE \
    --testnet-magic $MAGIC \
    --out-file $WORKDIR/tx.signed