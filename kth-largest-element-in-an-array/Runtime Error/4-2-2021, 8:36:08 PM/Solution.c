// https://leetcode.com/problems/kth-largest-element-in-an-array

void swep(int* a, int* b) {
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

int cmp(int* a, int* b) {
    if (*a < *b) {
        return -1;
    } else if (*a > *b) {
        return 1;
    } else {
        return 0;
    }
}

int* partition(int* l, int* r, int pivot) {
    int* c = l;
    int swap;
    while(l < r && c < r) {
        if (cmp(l, &pivot) == 1) {
            swep(l, c);
            ++l;
        } else if (cmp(l, &pivot) == -1) {
            swep(c, r);
            --r;
        } else {
            ++c;
        } 
    }
    return c; 
}


int findKthLargest(int* nums, int numsSize, int k){
    int* l = nums;
    int* r = nums + numsSize - 1;
    int* piv;
    printf("%d\n", 10 % 3);
    while(l < r) {
        piv = rand() % (r - l) + r; 
        
        piv = partition(l, r, *piv);
         
        
        if ((piv - l) > k) {
            r = piv - 1;
        } else if ((piv - l) < k) {
            k -= (piv - l);
            l = piv + 1;
        } else {
            return *piv;
        }
    }
    return *l;
}