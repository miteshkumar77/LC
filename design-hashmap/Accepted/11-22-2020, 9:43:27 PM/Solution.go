// https://leetcode.com/problems/design-hashmap

type sizeType = uint64
type indexType = uint64
type ratioType = float32
type keyType = int
type valueType = int

///---------------------------------------------------------------------------------------------------------
// hashElement class BEGIN

type hashElement struct {
	isOccupied bool
	isTomb     bool
	key        keyType
	value      valueType
}

func (element *hashElement) init() {
	element.isOccupied = false
	element.isTomb = false
}

// hashElement class END
///---------------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------------
// HashMap class BEGIN

// HashMap is a thread safe key value O(1) look up data structure
type HashMap struct {
	occupancyRatio ratioType
	occupied       sizeType
	size           sizeType
	data           *[]hashElement
	hashFunc       *func(keyType) indexType
}

/// Public

// CreateNewHashMap creates a new empty hashmap
func CreateNewHashMap(occupancyRatio ratioType,
	initialSize sizeType,
	hashFunc func(keyType) indexType) HashMap {
	ret := HashMap{}
	ret.init(occupancyRatio, initialSize, hashFunc)
	return ret
}

// CallBackIterator calls a callback function cb for every element in the map
// in no particular order
func (table *HashMap) CallBackIterator(cb func(interface{})) {
	for i := 0; i < len(*table.data); i++ {
		if (*table.data)[i].isOccupied {
			cb((*table.data)[i].value)
		}
	}
}

// Insert inserts a key value pair into the collection
func (table *HashMap) Insert(key keyType, value valueType) bool {
	table.rehash()
	initIdx := table.searchExists(key)

	if (*table.data)[initIdx].isOccupied && (*table.data)[initIdx].key == key {
		return false
	}

	insertIdx := table.searchToInsert(key)
	if !(*table.data)[insertIdx].isOccupied {
		table.occupied++
	}

	(*table.data)[insertIdx] = hashElement{true, true, key, value}
	table.size++
	return true
}

// GetVal returns (true, value) if key exists, otherwise (false, nil)
func (table *HashMap) GetVal(key keyType) (bool, valueType) {
	initIdx := table.searchExists(key)
	if (*table.data)[initIdx].isOccupied && (*table.data)[initIdx].key == key {
		return true, (*table.data)[initIdx].value
	}
	var def valueType
	return false, def
}

// Set key's value to value, whether it exists or not
func (table *HashMap) Set(key keyType, value keyType) {
	table.rehash()
	initIdx := table.searchExists(key)
	if (*table.data)[initIdx].isOccupied && (*table.data)[initIdx].key == key {
		(*table.data)[initIdx].value = value
		return
	}
	table.Insert(key, value)
}

// Contains returns true iff the map contains key
func (table *HashMap) Contains(key keyType) bool {
	initIdx := table.searchExists(key)
	if (*table.data)[initIdx].isOccupied && (*table.data)[initIdx].key == key {
		return true
	}

	return false
}

// Erase deletes the key, value pair from the collection iff it exists, and return true
// otherwise it returns false
func (table *HashMap) Erase(key keyType) bool {
	firstOcc := table.searchExists(key)
	if !(*table.data)[firstOcc].isTomb || !(*table.data)[firstOcc].isOccupied {
		return false
	}

	if (*table.data)[firstOcc].key == key {
		table.size--
		(*table.data)[firstOcc].isOccupied = false
		(*table.data)[firstOcc].isTomb = true
		return true
	}
	return false
}

/// Private

// searchToInsert walks forward from a particular key's hash index until the next unoccupied index
func (table *HashMap) searchToInsert(key keyType) indexType {
	hval := table.mhash(key)
	var x indexType = 0
	idx := (hval%indexType(len(*table.data)) + table.probe(x)) % indexType(len(*table.data))

	for (*table.data)[idx].isOccupied {
		x++
		idx = (hval%indexType(len(*table.data)) + table.probe(x)) % indexType(len(*table.data))
	}
	return idx
}

// searchExists walks forward from a particular key's hash index until the next non-tomb index
func (table *HashMap) searchExists(key keyType) indexType {
	hval := table.mhash(key)
	var x indexType = 0
	var idx = (hval%indexType(len(*table.data)) + table.probe(x)) % indexType(len(*table.data))
	for (*table.data)[idx].isTomb {
		if (*table.data)[idx].isOccupied && (*table.data)[idx].key == key {
			return idx
		}
		x++
		idx = (hval%indexType(len(*table.data)) + table.probe(x)) % indexType(len(*table.data))
	}

	return idx
}

func (table *HashMap) init(occupancyRatio ratioType, initialSize sizeType, hashFunc func(keyType) indexType) {
	table.occupancyRatio = occupancyRatio
	table.occupied, table.size = 0, 0
	tmp := make([]hashElement, initialSize)
	table.data = &tmp
	table.hashFunc = &hashFunc
	for i := 0; i < len(*table.data); i++ {
		(*table.data)[i].init()
	}
}

func (table *HashMap) mhash(key keyType) indexType {
	return (*table.hashFunc)(key)
}

func (table *HashMap) probe(x indexType) indexType {
	return x
}

func (table *HashMap) rehash() {
	if ratioType(table.occupied)/ratioType(len(*table.data)) < table.occupancyRatio {
		return
	}

	tmp := make([]hashElement, len(*table.data)*2)
	nData := &tmp

	for i := 0; i < len(*nData); i++ {
		(*nData)[i].init()
	}

	nData, table.data = table.data, nData
	table.size = 0
	table.occupied = 0

	for i := 0; i < len(*nData); i++ {
		if (*nData)[i].isOccupied {
			table.Insert((*nData)[i].key, (*nData)[i].value)
		}
	}
}

// HashMap class END
///---------------------------------------------------------------------------------------------------------



type MyHashMap struct {
    // m_hm HashMap
    m_hm map[int]int
}

func hs(s interface{}) indexType {
        
        b := make([]byte, 8)
    binary.LittleEndian.PutUint64(b, uint64(s.(int)))
        h := fnv.New64()
        h.Write([]byte(b))
        return indexType(h.Sum64())
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
    // var m MyHashMap
    // m.m_hm = CreateNewHashMap(0.7, 100, func(key interface{}) indexType {
    //     return hs(key)
    // })
    // return m
    
    return MyHashMap{make(map[int]int)}
}


/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int)  {
    // this.m_hm.Set(key, value)
    this.m_hm[key] = value
}


/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
    // exists, val := this.m_hm.GetVal(key)
    // if exists {
    //     return val.(int)
    // }
    // return -1
    
    value, exists := this.m_hm[key]
    if exists {
        return value
    }
    return -1
}


/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int)  {
    // this.m_hm.Erase(key)
    delete(this.m_hm, key)
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */