// https://leetcode.com/problems/design-hashmap

package main

// SizeType used for size properties
type SizeType = uint64

// IndexType used for indexing the map
type IndexType = uint64

// RatioType used for fractional properties
type RatioType = float32

// KeyType used for the key's type
type KeyType = int

// ValueType used for the value's type
type ValueType = int

///---------------------------------------------------------------------------------------------------------
// hashElement class BEGIN

type hashElement struct {
	isOccupied bool
	isTomb     bool
	key        KeyType
	value      ValueType
}

func (element *hashElement) init() {
	element.isOccupied = false
	element.isTomb = false
}

// hashElement class END
///---------------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------------
// hashShard class BEGIN

type hashShard struct {
	occupancyRatio RatioType
	occupied       SizeType
	size           SizeType
	data           *[]hashElement
	hashFunc       *func(KeyType) IndexType
}

/// Private

// CallBackIterator calls a callback function cb for every element in the map
// in no particular order
func (shard *hashShard) shardCallBackIterator(cb *func(interface{})) {
	for i := 0; i < len(*shard.data); i++ {
		if (*shard.data)[i].isOccupied {
			(*cb)((*shard.data)[i].value)
		}
	}
}

// Insert inserts a key value pair into the collection
func (shard *hashShard) shardInsert(key KeyType, hashValue IndexType, value ValueType) bool {
	shard.rehash()
	initIdx := shard.searchExists(key, hashValue)

	if (*shard.data)[initIdx].isOccupied && (*shard.data)[initIdx].key == key {
		return false
	}

	insertIdx := shard.searchToInsert(key, hashValue)
	if !(*shard.data)[insertIdx].isOccupied {
		shard.occupied++
	}

	(*shard.data)[insertIdx] = hashElement{true, true, key, value}
	shard.size++
	return true
}

// GetVal returns (true, value) if key exists, otherwise (false, nil)
func (shard *hashShard) shardGetVal(key KeyType, hashValue IndexType) (bool, ValueType) {
	initIdx := shard.searchExists(key, hashValue)
	if (*shard.data)[initIdx].isOccupied && (*shard.data)[initIdx].key == key {
		return true, (*shard.data)[initIdx].value
	}
	var def ValueType
	return false, def
}

// Set key's value to value, whether it exists or not
func (shard *hashShard) shardSet(key KeyType, hashValue IndexType, value ValueType) {
	shard.rehash()
	initIdx := shard.searchExists(key, hashValue)
	if (*shard.data)[initIdx].isOccupied && (*shard.data)[initIdx].key == key {
		(*shard.data)[initIdx].value = value
		return
	}
	shard.shardInsert(key, hashValue, value)
}

// Contains returns true iff the map contains key
func (shard *hashShard) shardContains(key KeyType, hashValue IndexType) bool {
	initIdx := shard.searchExists(key, hashValue)
	if (*shard.data)[initIdx].isOccupied && (*shard.data)[initIdx].key == key {
		return true
	}

	return false
}

// Erase deletes the key, value pair from the collection iff it exists, and return true
// otherwise it returns false
func (shard *hashShard) shardErase(key KeyType, hashValue IndexType) bool {
	firstOcc := shard.searchExists(key, hashValue)
	if !(*shard.data)[firstOcc].isTomb || !(*shard.data)[firstOcc].isOccupied {
		return false
	}

	if (*shard.data)[firstOcc].key == key {
		shard.size--
		(*shard.data)[firstOcc].isOccupied = false
		(*shard.data)[firstOcc].isTomb = true
		return true
	}
	return false
}

func (shard *hashShard) init(occupancyRatio RatioType, initialSize SizeType, hashFunc *func(KeyType) IndexType) {
	shard.occupancyRatio = occupancyRatio
	shard.occupied, shard.size = 0, 0
	tmp := make([]hashElement, initialSize)
	shard.data = &tmp
	shard.hashFunc = hashFunc
	for i := 0; i < len(*shard.data); i++ {
		(*shard.data)[i].init()
	}
}

// searchToInsert walks forward from a particular key's hash index until the next unoccupied index
func (shard *hashShard) searchToInsert(key KeyType, hashValue IndexType) IndexType {
	// hval := shard.mhash(key)
	var x IndexType = 0
	idx := (hashValue%IndexType(len(*shard.data)) + shard.probe(x)) % IndexType(len(*shard.data))

	for (*shard.data)[idx].isOccupied {
		x++
		idx = (hashValue%IndexType(len(*shard.data)) + shard.probe(x)) % IndexType(len(*shard.data))
	}
	return idx
}

// searchExists walks forward from a particular key's hash index until the next non-tomb index
func (shard *hashShard) searchExists(key KeyType, hashValue IndexType) IndexType {
	var x IndexType = 0
	var idx = (hashValue%IndexType(len(*shard.data)) + shard.probe(x)) % IndexType(len(*shard.data))
	for (*shard.data)[idx].isTomb {
		if (*shard.data)[idx].isOccupied && (*shard.data)[idx].key == key {
			return idx
		}
		x++
		idx = (hashValue%IndexType(len(*shard.data)) + shard.probe(x)) % IndexType(len(*shard.data))
	}

	return idx
}

func (shard *hashShard) mhash(key KeyType) IndexType {
	return (*shard.hashFunc)(key)
}

func (shard *hashShard) probe(x IndexType) IndexType {
	return x
}

func (shard *hashShard) rehash() {
	if RatioType(shard.occupied)/RatioType(len(*shard.data)) < shard.occupancyRatio {
		return
	}

	tmp := make([]hashElement, len(*shard.data)*2)
	nData := &tmp

	for i := 0; i < len(*nData); i++ {
		(*nData)[i].init()
	}

	nData, shard.data = shard.data, nData
	shard.size = 0
	shard.occupied = 0

	for i := 0; i < len(*nData); i++ {
		if (*nData)[i].isOccupied {
			shard.shardInsert((*nData)[i].key, shard.mhash((*nData)[i].key), (*nData)[i].value)
		}
	}
}

// hashShard class END
///---------------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------------
// HashMap class BEGIN

// HashMap is a thread safe key value O(1) look up data structure
type HashMap struct {
	hashFunc *func(KeyType) IndexType
	shards   []hashShard
}

/// Public

// CreateNewHashMap creates a new empty hashmap
func CreateNewHashMap(occupancyRatio RatioType,
	initialSize SizeType,
	hashFunc func(KeyType) IndexType, shards SizeType) HashMap {
	ret := HashMap{}
	ret.init(occupancyRatio, initialSize, hashFunc, shards)
	return ret
}

// CallBackIterator calls a callback function cb for every element in the map
// in no particular order
func (table *HashMap) CallBackIterator(cb func(interface{})) {
	for _, shard := range table.shards {
		shard.shardCallBackIterator(&cb)
	}
}

// Insert inserts a key value pair into the collection if it does not exist
// and returns true, otherwise just returns false
func (table *HashMap) Insert(key KeyType, value ValueType) bool {
	hashValue := table.mhash(key)
	shard := table.getShard(hashValue)

	return table.shards[shard].shardInsert(key, hashValue, value)
}

// GetVal returns (true, value) if key exists, otherwise (false, nil)
func (table *HashMap) GetVal(key KeyType) (bool, ValueType) {
	hashValue := table.mhash(key)
	shard := table.getShard(hashValue)

	return table.shards[shard].shardGetVal(key, hashValue)
}

// Set key's value to value, whether it exists or not
func (table *HashMap) Set(key KeyType, value ValueType) {
	hashValue := table.mhash(key)
	shard := table.getShard(hashValue)

	table.shards[shard].shardSet(key, hashValue, value)
}

// Contains returns true iff the map contains key
func (table *HashMap) Contains(key KeyType) bool {
	hashValue := table.mhash(key)
	shard := table.getShard(hashValue)

	return table.shards[shard].shardContains(key, hashValue)
}

// Erase deletes the key, value pair from the collection iff it exists, and return true
// otherwise it returns false
func (table *HashMap) Erase(key KeyType) bool {
	hashValue := table.mhash(key)
	shard := table.getShard(hashValue)

	return table.shards[shard].shardErase(key, hashValue)
}

/// Private

// getShard gets the shard associated with a hash value of a particular key
func (table *HashMap) getShard(hashValue IndexType) IndexType {
	return hashValue % IndexType(len(table.shards))
}

func (table *HashMap) init(occupancyRatio RatioType, initialSize SizeType, hashFunc func(KeyType) IndexType, shards SizeType) {

	table.shards = make([]hashShard, shards)
	table.hashFunc = &hashFunc
	for i := 0; i < len(table.shards); i++ {
		(table.shards)[i].init(occupancyRatio, initialSize, &hashFunc)
	}

}

func (table *HashMap) mhash(key KeyType) IndexType {
	return (*table.hashFunc)(key)
}

// HashMap class END
///---------------------------------------------------------------------------------------------------------




type MyHashMap struct {
    m_hm HashMap
    // m_hm map[int]int
}

func hs(i int) IndexType {
        
        b := make([]byte, 8)
    binary.LittleEndian.PutUint64(b, uint64(i))
        h := fnv.New64()
        h.Write([]byte(b))
        return IndexType(h.Sum64())
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
    var m MyHashMap
    m.m_hm = CreateNewHashMap(0.7, 100, func(key int) IndexType {
        return hs(key)
    }, 2)
    return m
    
    // return MyHashMap{make(map[int]int)}
}


/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int)  {
    this.m_hm.Set(key, value)
    // this.m_hm[key] = value
}


/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
    exists, val := this.m_hm.GetVal(key)
    if exists {
        return val
    }
    return -1
    
    // value, exists := this.m_hm[key]
    // if exists {
    //     return value
    // }
    // return -1
}


/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int)  {
    this.m_hm.Erase(key)
    // delete(this.m_hm, key)
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */