vi par;
vi rankk;

bool compare(vi x,vi y){
    return x[2]<y[2];
}

void makeSet(int i){
    par[i]=i;
    rankk[i]=1;
}

int findSet(int i){
    if(i==par[i]){
        return i;
    }
    return par[i]=findSet(par[i]); 
}

void unionSet(int a,int b){
    a=findSet(a);
    b=findSet(b);
    if(a!=b){
        if(rankk[a]<rankk[b])
            swap(a,b);
        par[b]=a;
        rankk[a]+=rankk[b];
    }
} 

void kruskal(int s){
    par.resize(n+3);
    rankk.resize(n+3);
    forr(i,0,n-1)makeSet(i); 
    sort(e.begin(),e.end(),compare);
    int cnt=0,totalweight=0;
    for(auto i:e){
        if(findSet(i[0]) != findSet(i[1])){
            cout<<i[0]<<"connectedTo"<<i[1]<<"havingWeight"<<i[2]<<endl;
            totalweight+=i[2];
            cnt++;
            unionSet(i[0],i[1]);
        }

    }
    if(cnt!=n-1-s){cout<<"No MST";}
}
