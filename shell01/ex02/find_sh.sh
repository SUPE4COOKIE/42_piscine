#!/bin/bash
find . -name "*.sh" -printf "%f\n"  \
| sed 's/.sh$//'

# find used to get all the .sh files and then -printf is used to format to get only file name
# using sed with substitution to replace the .sh with nothing
