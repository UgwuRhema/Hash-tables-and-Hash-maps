package main

import "fmt"

type Entry struct{
	key string
	val int
	next *Entry
}

type HashTable struct{
	hashtab []*Entry
	tabnum uint
	size uint
}

func newTable(tabnum uint) *HashTable {
	return &HashTable{
		hashtab: make([]*Entry, tabnum),
		tabnum: tabnum,
		size: 0,
	}
}

func hash(key string, size uint) uint {
	var hashval uint = 0
	for i := 0; i < len(key); i++{
		hashval = uint(key[i]) * 31 + hashval
	}
	return hashval % size
}

func lookup(table *HashTable, key string) *Entry {
	if table == nil {
		return nil
	}
	var hval uint = hash(key, table.tabnum)
	for ent := table.hashtab[hval]; ent != nil; ent = ent.next {
		if ent.key == key {
			return ent
		}
	}
	return nil
}

func map_put(table *HashTable, key string, value int){
	if table == nil {
		fmt.Println("Table is nil")
	}
	var hval uint = hash(key, table.tabnum)
	var found *Entry = lookup(table, key)
	if found != nil {
		found.val = value
	} else {
		var new_entry *Entry = &Entry{key: key, val: value, next: nil}
		new_entry.next = table.hashtab[hval]
		table.hashtab[hval] = new_entry //insert at head
		table.size++
	}
}

func map_get(table *HashTable, key string) int {
	if table == nil {
		return -1 //return negative one on errors
	}
	var found *Entry = lookup(table, key)
	if found != nil {
		return found.val
	}
	fmt.Println("Not Found")
	return -1
}

func main(){
	var num uint = 2
	var mymap *HashTable = newTable(num)
	map_put(mymap, "Rhema", 17)
	map_put(mymap, "Frank", 14)
	var val_for_rhema int = map_get(mymap, "Rhema")
	fmt.Println(mymap)
	fmt.Printf("The Value for key Rhema is %v", val_for_rhema)
}
