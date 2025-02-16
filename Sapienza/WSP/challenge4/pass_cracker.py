#!/usr/bin/python

import hashlib

for password in open("rockyou.txt", "r"):
    if hashlib.md5((password.strip() + "yhbG").encode()).hexdigest() == "f2b31b3a7a7c41093321d0c98c37f5ad":
        print("[+] password is {}".format(password.strip()))
        exit(0)
        
print("Done")
