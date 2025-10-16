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

echo "Enter the line in the file THAT needs to be replaced"
read str1

if [ -z "$str1" ] || ! grep -q "$str1" "$route"; then
    echo "The line is empty or does not exist in the file"
    exit 1
fi

echo "Enter the line  that needs to be inserted into the file"
read str2

if [ -z "$str2" ]; then
    echo "The line is empty"
    exit 1
fi
sed -i '' "s/$str1/$str2/g" $route

filepath=$(realpath "$route")
filesize=$(stat -f "%z" "$route")
datetime=$(date "+%Y-%m-%d %H:%M")
sha=$(shasum -a 256 "$route" | cut -d' ' -f1)

echo "$small_route - $filesize - $datetime - $sha - sha256" >> src/files.log