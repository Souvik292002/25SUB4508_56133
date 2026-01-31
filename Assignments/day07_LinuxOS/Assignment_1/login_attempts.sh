#!/bin/bash 
grep "Failed password" /var/log/auth.log | \ 
sed  's/.*Failed password for //' | \ 
awk '{print "User:" $1 ", Error:" "Failed password"}' > failed_logins.txt