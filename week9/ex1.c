#include <stdio.h>
#include <stdlib.h>

//counter 1000 0000 0000 0000
#define COUNTER_MAX 32768
#define COUNTER_BITS 16

// structure for single frame - it's page id and current counter
struct page{
    int pageId;
    int counter;
};

/* function for page processing.
function can remove old pages and update counters for all pages.
return 1 if hit happens, 0 otherwise.
*/
int process_page(struct page* pages, int pageFramesNum, int processPageId){
    int hit = 0; // flag
    for(int i = 0; i < pageFramesNum; i++){
        if(pages[i].pageId == processPageId){
            // hit situation. counter of hitted page increases
            pages[i].counter |= 1 << (COUNTER_BITS - 1);
            hit = 1;
        } else {
            // counter decrease for unused pages
            pages[i].counter >>= 1;
        }
    }
    if (!hit){
        /* If the hit did not happen we have to
        delete the page with the lower counter */
        int page_index_to_update = 0;
        // finding page index with minimum counter (or empty slot eith pageId == -1)
        for(int i = 0; i < pageFramesNum; i++){
            if(pages[i].counter < pages[page_index_to_update].counter || pages[i].pageId == -1){
                page_index_to_update = i;
            }
        }
        //replacing page
        pages[page_index_to_update].pageId = processPageId;
        pages[page_index_to_update].counter = COUNTER_MAX;
    }
    return hit;
}

int main(){
    // entering number of frames
    printf("Enter number of page frames:\n");
    int pageFramesNum;
    scanf("%d", &pageFramesNum);
    if (pageFramesNum < 1){
        printf("Error. Enter valid number greater than 0.\n");
        return 0;
    }

    // allocating memory and filling page frames with initial values
    struct page* pages = (struct page*)malloc(pageFramesNum * sizeof(struct page));
    for(int i = 0; i < pageFramesNum; i++){
        pages[i].pageId = -1; // -1 means no page assigned yet to that frame
        pages[i].counter = 0;
    }

    //opening file
    FILE* f = fopen("Lab 09 input.txt","r");
    if (f < 0){
        printf("File not found\n");
        return 0;
    }

    int currentPageId, hits = 0, misses = 0;
    //reading pages from file one by one
    while(fscanf(f, "%d ", &currentPageId) > 0 ){
        printf("current page is %d\n\n", currentPageId);
        // processing page and counting hits and misses
        if (process_page(pages, pageFramesNum, currentPageId)){
            hits++;
        } else {
            misses++;
        }
        //printing snapshot of all frames
        for(int i = 0; i < pageFramesNum; i++){
            printf("t = %d id = %d %d\n", i, pages[i].pageId, pages[i].counter);
        }

    }
    printf("hits: %d, misses: %d, hit ratio = %f", hits, misses, (double )hits/(misses + hits));
    return 0;
}

/*
 Results on given data:
 input = 10, ratio = 0.010
 input = 50, ratio = 0.051
 input = 100, ratio = 0.093
 */

