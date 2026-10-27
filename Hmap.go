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

//func map_put(table *HashTable, ){
//	
//}

func main(){
	var num uint = 2
	var mymap *HashTable = newTable(num)
	fmt.Println(mymap)
}
