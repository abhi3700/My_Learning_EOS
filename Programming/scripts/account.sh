#!/bin/bash

# Creates a new account with self delegated resources

if [ "$#" -ne 2 ]; then
    echo "Usage: account.sh <EXIST_ACCOUNT_NAME> <ACCOUNT_NAME> <STAKE_NET> <STAKE_CPU> <RAM_KB> <OWNER_PUBLIC_KEY> <ACTIVE_PUBLIC_KEY>
    
    Subcommands:
    EXIST_ACCOUNT_NAME      Existing EOS account name
    ACCOUNT_NAME            New EOS account name
    STAKE_NET               NET Stake amount e.g. "0.2 EOS"
    STAKE_CPU               CPU Stake amount e.g. "0.2 EOS"
    RAM_KB                  RAM (in KB) amount e.g. 8
    OWNER_PUBLIC_KEY        Owner public key
    ACTIVE_PUBLIC_KEY       Active public key
    "
    exit 1
fi

EXIST_ACCOUNT_NAME=$1
ACCOUNT_NAME=$2
STAKE_NET=$3
STAKE_CPU=$4
RAM_KB=$5
OWNER_PUBLIC_KEY=$6
ACTIVE_PUBLIC_KEY=$7
       
cleos system newaccount --stake-net $3 --stake-cpu $4 --buy-ram-kbytes $5 $1 $2 $6 $7 -p $1
