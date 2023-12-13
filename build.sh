#!/usr/bin/env bash

cwd=$PWD

cd "$cwd/library"
chalet --distribution-dir dist/Debug -c Debug bundle
chalet --distribution-dir dist/Release -c Release bundle

cd "$cwd/box"
chalet --output-dir ../build --distribution-dir ../dist -c Debug build
chalet --output-dir ../build --distribution-dir ../dist -c Release bundle
