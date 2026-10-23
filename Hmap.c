#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct entry;
struct hash_map_t;
static uint32_t hash(const char *, size_t);
static struct hash_map_t *new_table(struct entry **, size_t);
static struct entry * lookup(const char *, struct hash_map_t *);
void map_put(struct hash_map_t *, const char *, const int);
static int map_get(const struct hash_map_t **, const char *);/*we could use a void pointer for this but our current hashmaps value is an integer*/
void destroy_map(struct hash_map_t *);

/*HashMap entry*/
struct entry
{
	char *key;
	int value;
	struct entry *next;
};

struct hash_map_t
{
	struct entry **bucket;/*an array of entries*/
	size_t num_buckets;
	size_t size;
};

#define HASH_SIZE 2
static struct entry *bucket[HASH_SIZE];

int
main(int argc, char *argv[])
{
	struct hash_map_t *mymap = new_table(bucket, HASH_SIZE);	
	map_put(mymap, "Frank", 13);
	map_put(mymap, "Frank", 14);/*replaces the value at key "Frank" to 14(hopefully)*/
	map_put(mymap, "Rhema", 17);
	destroy_map(mymap);
	return 0;
}

static uint32_t hash(const char *s, size_t bucketsize)
{
	uint32_t hashval;
	for (hashval = 0; *s; ++s)
		hashval = *(unsigned char *)s + 31 * hashval;
	return hashval % bucketsize;
}

#define DEFT (sizeof(struct hash_map_t))

static struct hash_map_t *
new_table(struct entry **bucket, size_t bucket_size)
{
	if (!bucket)
		return NULL;
	struct hash_map_t *ntable = (struct hash_map_t *)malloc(DEFT);
	if (!ntable)
	{
		fprintf(stderr, "ntable malloc failed!\n");
		return NULL;
	}
	ntable->bucket = bucket;
	ntable->num_buckets = bucket_size;
	ntable->size = 0;
	return ntable;
}

static struct entry *
lookup(const char *s, struct hash_map_t *map)
{
	struct entry *curr;
	for (curr = map->bucket[hash(s, map->num_buckets)]; curr; curr = curr->next)
		if (strcmp(s, curr->key) == 0)
			return curr;
	return NULL;
}

#define SOE (sizeof(struct entry))

void
map_put(struct hash_map_t *map, const char *key, const int value)
{
	if (!map || !key)
	{
		fprintf(stderr, "Inputs are NULL\n");
		return;
	}
	struct entry *found = lookup(key, map);
	if (found)/*if found just update in-place*/
	{
		found->value= value;
		return;
	}
	uint32_t hashvalue = hash(key, map->num_buckets);
	struct entry *ne = (struct entry *)malloc(SOE);
	if (!ne){
		fprintf(stderr, "Entry malloc failed!\n");
		return;
	}
	ne->key = strdup(key);
	if (!ne->key){
		free(ne);
		return;
	}
	ne->value = value;
	ne->next = map->bucket[hashvalue];
	map->bucket[hashvalue] = ne;
	map->size++;
}

/*returns -1 on error, and the value on success*/
static int
map_get(const struct hash_map_t **map, const char *key)
{
	if (!map || !key)
		return -1;
	struct hash_map_t *temp_map = *map;
	struct entry *f = lookup(key, temp_map);
	if (f)
		return f->value;
	return -1;
}

void
destroy_map(struct hash_map_t *map)
{
	if (map)
	{
		for (size_t i=0;i<map->num_buckets;++i)
		{
			if (map->bucket[i]->key)
				free((void *)map->bucket[i]->key);
			free((void *)map->bucket[i]);
		}
		free(map);
	}
	return;
}
