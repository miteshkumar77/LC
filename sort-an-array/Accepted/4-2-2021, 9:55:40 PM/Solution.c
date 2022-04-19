// https://leetcode.com/problems/sort-an-array


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
    return r;
}

void qsurt(int* l, int* r) {
    if (l >= r) { return; }
    int* piv = rand() % (r - l) + l;
    piv = partition(l, r, *piv);
    qsurt(l, piv - 1);
    qsurt(piv + 1, r);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    qsurt(nums, nums + numsSize - 1);
    *returnSize = numsSize;
    return nums;
}