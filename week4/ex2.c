// Here we have exponential increasing number of processes.
// After first iteration of the loop we have 2^1 processes,
// after second iteration 2^2, and so on up to 2^5 processes.


int main(void){
    for (int i = 0; i < 5; i++){
        fork();
    	sleep(5);
    }
    return 0;
}
