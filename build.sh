#!/usr/bin/env bash

cwd=$PWD

cd "$cwd/library"
chalet --distribution-dir dist/Debug -c Debug bundle
chalet --distribution-dir dist/Release -c Release bundle

cd "$cwd/box"
chalet -c Debug build
chalet -c Release bundle
