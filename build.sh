#!/usr/bin/env bash

cwd=$PWD

cd $cwd/library
chalet -c Debug build
chalet -c Release build

cd $cwd/box
chalet -c Debug build
chalet -c Release bundle
