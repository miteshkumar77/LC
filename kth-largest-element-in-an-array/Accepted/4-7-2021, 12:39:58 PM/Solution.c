// https://leetcode.com/problems/kth-largest-element-in-an-array

typedef int elem;

elem swapvar;
void swap(elem* a, elem* b) {
	swapvar = *a;
	*a = *b;
	*b = swapvar;
}

int cmp(elem* a, elem* b) {
	if (*a > *b) {
		return -1;
	} else if (*a < *b) {
		return 1;
	} else {
		return 0;
	}
}

elem* partition(elem* l, elem* r, elem pivot) {
    
    elem* c = l;
    
    while(c <= r) {
        if (cmp(l, &pivot) == -1) {
            ++l;
            if (c < l) {
                c = l;
            }
            continue;
        }
        if (cmp(r, &pivot) == 1) {
            --r;
            continue;
        }
        if (c < l) {
            c = l;
            continue;
        }
        if (cmp(c, &pivot) == -1) {
            swap(c, l); ++l; continue;
        } 
        if (cmp(c, &pivot) == 1) {
            swap(c, r);
            --r;
            continue;
        }
        ++c;
    }
    return r;
}


elem findKth(elem* l, elem* r, size_t k) {
	elem* piv;
	while(l < r) {
		piv = rand() % (r - l) + l;
		piv = partition(l, r, *piv);
		if ((piv - l + 1) > k) {
			r = piv - 1;
		} else if ((piv - l + 1) < k) {
			k -= (piv - l + 1);
			l = piv + 1;
		} else {
			return *piv;
		}
	}
	// if (k != 0) {
	// 	fprintf(stderr, "ERROR: undefined sequence k = %ld <> 0\n", k);
	// 	exit(EXIT_FAILURE);
	// }
	return *l;
}

int findKthLargest(int* nums, int numsSize, int k){
    elem* l = nums;
    elem* r = nums + numsSize - 1;
    return findKth(l, r, k);
}