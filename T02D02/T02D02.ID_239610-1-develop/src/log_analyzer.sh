#!/bin/bash
full=$(git rev-parse --show-toplevel)
echo "Enter the file path WITHOT the root folder of the repository:"
read small_route
route="$full/$small_route"
echo "$route"

if ! test -r "$route"; then
    echo "The file does not exisit"
    exit 1
fi

stroki=$(cat "$route"|wc -l)
files=$(cat "$route" | cut -d'-' -f1 | uniq | wc -l)
sha=$(cat "$route" | cut -d' ' -f1,8 | uniq | wc -l)

echo $stroki $files $(($sha-$files))