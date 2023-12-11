#!/bin/bash

usage() {
    echo "usage: $0 [options] <username> <groupname>"
    exit 1
}

while getopts ":u:g:d:c:h" opt; do
    case $opt in
        u)
            uid=$OPTARG
            ;;
        g)
            gid=$OPTARG
            ;;
        d)
            home=$OPTARG
            ;;
        c)
            shell=$OPTARG
            ;;
        h)
            usage
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            usage
            ;;
    esac
done

shift $((OPTIND-1))

if [ $# -ne 2 ]; then
    usage
fi

username=$1
groupname=$2

if [ -n "$uid" ]; then
    usermod -u $uid $username
fi

if [ -n "$gid" ]; then
    usermod -g $gid $username
fi

if [ -n "$home" ]; then
    usermod -d $home $username
fi

if [ -n "$shell" ]; then
    usermod -s $shell $username
fi

groupadd $groupname
usermod -G $groupname $username