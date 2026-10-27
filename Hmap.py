#!/usr/bin/env python3

class entry:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None

class table:
    def __init__(self, bucket, num_buck):
        self.bucket = bucket
        self.num_bucket = num_buck
        self.size = 0

def hash(string, size):
    hashval = 0
    i = 0
    while string[i] != '\0':
        hashval = string[i] * 31 + hashval
        i = i + 1
    return hashval % size
