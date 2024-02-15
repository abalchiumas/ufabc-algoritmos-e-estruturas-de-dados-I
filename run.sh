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

mkdir -p out

filename=$(basename "$relativePath")
filenameNoExtension="${filename%.*}"

if [ -f "out/$filenameNoExtension" ]; then
    rm "out/$filenameNoExtension"
fi

gcc "$relativePath" -o "out/$filenameNoExtension" -lm

if [ $? -eq 0 ]; then
    "./out/$filenameNoExtension"
	echo    
    rm "out/$filenameNoExtension"
else
    echo "Compilation failed"
fi