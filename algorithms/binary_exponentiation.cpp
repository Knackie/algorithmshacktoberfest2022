ll binPow(ll fst, ll scnd){
    ll ans=1;
    while(scnd>0){
        if(scnd&1)ans = ans*fst%mod;
        fst = fst*fst%mod;
        scnd>>=1;
    }
    return ans;
}
