#!/bin/bash

find . -name "*.sh" -printf "%f\n" | sed 's/\.[^.]*$//'
