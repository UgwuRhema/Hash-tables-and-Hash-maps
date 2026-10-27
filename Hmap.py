#!/usr/bin/env python3

class entry:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None

class table:
    def __init__(self, bucket, num_b):
        self.bucket = bucket
        self.num_bucket = num_b
        self.size = 0

def hash(string, size):
    hashval = 0
    i = 0
    for ch in string:
        hashval = ord(ch) * 31 + hashval
    return hashval % size

def lookup(table, key):
    idx = hash(key, table.num_bucket)
    for entry in table.bucket[idx]:
        if entry is not None and entry.key == key:
            return entry
    return None

def map_put(table, key, value):
    hashval = hash(key, table.num_bucket)
    found = lookup(table, key)
    if found is not None:
        found.val = value
    else:
        new_entry = entry(key, value)
        new_entry.next = table.bucket[hashval]
        table.bucket[hashval] = new_entry #insert at head of list
        table.size = table.size + 1

def map_get(table, key):
    if table is None:
        return -1 #negative 1 on errors
    found = lookup(table, key)
    if found is not None:
        return found.val #return the value from the found entry
    else:
        print("Not Found")
        return -1

#main function:
tabnum = 2
hashtab = [[] for _ in range(tabnum)]
mymap = table(hashtab, tabnum)
map_put(mymap, "Rhema", 17)
map_put(mymap, "Frank", 14)
#this works with no errors whatsoever, so
#we need to verify it the HashMap ACTUALLY works
#so we will now implement map_get
