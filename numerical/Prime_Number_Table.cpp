vector<long long> Prime_Number_Table(long long  n){
    bool prime[n];
    vector <long long> prime1;
    for (long long i=0; i<n+1; i++){
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
    for(long long i=2; i<=n+1; i++){
        if(prime[i]==1){
            for(long long j=i*i; j<n+1; j+=i){
                prime[j]=0;
            }
        }
    }
    for(long long  i=2; i<n+1; i++){
        if(prime[i]){
            prime1.push_back(i);
        }
    }
    return prime1;
}