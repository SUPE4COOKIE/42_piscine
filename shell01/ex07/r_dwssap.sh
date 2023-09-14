#!/bin/bash
cat /etc/passwd | awk 'BEGIN { FS = ":" } ; {print $1}' | sed -n "${FT_LINE1},${FT_LINE2}p" | awk 'NR%2==0'| rev | sort -r | perl -p -e 's/\n/, /' | sed 's/,.$/./'


# cat the etc/passwd
# get only the corresponding lines
# get 1 line out of 2
# reverse the strings
# reverse alphabet sort
# replace return to the lign by , 
# replace the last , by a point
