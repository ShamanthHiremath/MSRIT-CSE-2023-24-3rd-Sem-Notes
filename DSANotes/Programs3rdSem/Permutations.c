void perm(int index, char* str, int n){
    if(index>=n){
        for(int j =0; j<n; j++){
            printf("%c", str[j]);
        }
        //print the string completely
        printf("/n");
    }
    //n =size of str
    for(int i=index; i<n; i++){
        swap(str[i], str[index]);
        perm(index+1, &str, int n);
        swap(str[i], str[index]);
    }
}