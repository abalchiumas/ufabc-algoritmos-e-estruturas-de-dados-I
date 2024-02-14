#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <relative_path>"
    exit 1
fi

relativePath="$1"

if [ ! -f "$relativePath" ]; then
    echo "File not found: $relativePath"
    exit 1
fi

filename=$(basename "$relativePath")
filenameNoExtension="${filename%.*}"

if [ -f "$filenameNoExtension" ]; then
    rm "$filenameNoExtension"
fi

gcc "$relativePath" -o "$filenameNoExtension"

if [ $? -eq 0 ]; then
    "./$filenameNoExtension"
    
    rm "$filenameNoExtension"
else
    echo "Compilation failed"
fi