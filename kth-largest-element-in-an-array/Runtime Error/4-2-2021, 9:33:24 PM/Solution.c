// https://leetcode.com/problems/kth-largest-element-in-an-array

void swep(int* a, int* b) {
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

int cmp(int* a, int* b) {
    if (*a > *b) {
        return -1;
    } else if (*a < *b) {
        return 1;
    } else {
        return 0;
    }
}

int* partition(int* l, int* r, int pivot) {
    int* c = l;
    
    while(l < r && c <= r) {
        if (cmp(l, &pivot) == -1) {
            ++l;
            continue;
        }
        if (cmp(r, &pivot) == 1) {
            --r;
            continue;
        }
        if (c < l) {
            c = l;
        }
        
        if (cmp(c, &pivot) == -1) {
            swep(c, l);
            ++l;
            continue;
        } 
        if (cmp(c, &pivot) == 1) {
            swep(c, r);
            --r;
            continue;
        }
        ++c;
    }
    return r + 1;
}


int findKthLargest(int* nums, int numsSize, int k){
    int* l = nums;
    int* r = nums + numsSize - 1;
    int* piv;
   
    while(l < r) {
        piv = rand() % (r - l) + l; 
        
        printf("PIVOT: %d ==> ", *piv);
        int p = piv;
        piv = partition(l, r, *piv);
        
        for (int* x = l; x <= r; ++x) {
            printf("%d ", *x);
        }
        
        printf(" VAL: %d K: %d\n",*piv, k);
        
        if ((piv - l + 1) > k) {
            r = piv - 1;
        } else if ((piv - l + 1) < k) {
            k -= (piv - l + 1);
            l = piv + 1;
        } else {
            return *piv;
        }
    }
    return *l;
}