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

func main(){
	var num uint = 2
	var mymap *HashTable = newTable(num)
	fmt.Println(mymap)
}
