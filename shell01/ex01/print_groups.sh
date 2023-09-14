#!/bin/bash
id -Gn $FT_USER \
| tr " " "," \
| tr -d "\n"

# get the groups of FN_USER
# replace every spaces with comas
# remove every return to lign 
