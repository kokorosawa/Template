void Prime_Number_Table(long long  n){
        for (long long i=0; i<n+1; i++){
            prime[i]=1;
        }
        prime[0]=0;
        prime[1]=0;
        for(long long i=2; i<=n+1; i++){
            if(prime[i]==1){
                for(long long j=i*i; j<1000001; j+=i){
                    prime[j]=0;
                }
            }
        }
        for(long long  i=2; i<n+1; i++){
            if(prime[i]){
                prime1.push_back(i);
            }
        }
}
