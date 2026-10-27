#!/usr/bin/env python3

class entry:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None

class table:
    def __init__(self, num_b):
        self.bucket = [None] * num_b
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
    entry = table.bucket[idx]
    while entry is not None:
        if entry.key == key:
            return entry
        entry = entry.next
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
mymap = table(tabnum)
map_put(mymap, "Rhema", 17)
map_put(mymap, "Frank", 14)
#this works with no errors whatsoever, so
#we need to verify it the HashMap ACTUALLY works
#so we will now implement map_get
value_for_rhema = map_get(mymap, "Rhema") #this should return 17, please
print(f"The value the the entry with key 'Rhema' is {value_for_rhema}")
