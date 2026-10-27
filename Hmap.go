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

func hash(key string) uint {
	
}

func main(){
	var num uint = 2
	var mymap *HashTable = newTable(num)
	var entry1 *Entry = &Entry{key: "Rhema", val: 17, next: nil}
	fmt.Println(mymap)
}
