#!/bin/bash
ifconfig  \
| grep ether \
| awk '{print $2}'

# ifconfig -a used to display all interfaces
# grep ether to only get the line with the mac adress
# using the awk print $2 to get the second value after the separator
