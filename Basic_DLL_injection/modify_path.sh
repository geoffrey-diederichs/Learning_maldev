#!/bin/bash

echo "Please enter the path to the DLL :"
read path
code="char DLL [] = \"${path}\";"
sed -i "23s/.*/${code}/" launcher.cpp
echo "launcher.exe has been modified accordingly."
