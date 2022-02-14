#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pii;
 
pii arr1[3010101];
pii arr2[3010101];
long long arr[40];
long long asz[40];
long long brr[40];
long long bsz[40];
string s;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    long long n1 = n/2;
    long long n2 = n - n1;
    for(int i = 0; i<n1; i++){
        cin >> s;
        long long mul = 1LL<<40;
        long long chk = 1;
        for(int j=0; j<s.size();j++){
            if(j && s[j] != s[j-1]) chk = 0;
            if(chk == 0) mul /= 2;
            if(s[j]=='B') arr[i] += mul;
            else arr[i] -= mul;
        }
        asz[i] = s.size();
    }
    for(int i = 0; i<n2; i++){
        cin >> s;
        long long mul = 1LL<<40;
        long long chk = 1;
        for(int j = 0; j<s.size(); j++){
            if(j&&s[j] != s[j-1]) chk = 0;
            if(chk == 0) mul /= 2;
            if(s[j] == 'B') brr[i] += mul;
            else brr[i] -= mul;
        }
        bsz[i] = s.size();
    }
    long long bn1 = (1LL<<n1);
    long long bn2 = (1LL<<n2);
 
    for(int i = 1; i<=bn1; i++){
        long long now = 0;
        long long now2 = 0;
        for(int j = 0; j<n1; j++){
            if((1LL<<j)&i){
                now += arr[j];    
                now2 += asz[j];
            }
    	}
        arr1[i] = {now, now2};
    }
    for(int i = 1; i<=bn2; i++){
        long long now=0;
        long long now2=0;
        for(int j = 0; j<n2; j++) {
            if((1LL<<j)&i){
                now += brr[j];
                now2 += bsz[j]; 
			}
        }
        arr2[i]={now, now2};
    }
    sort(arr1+1,arr1+1+bn1);
    sort(arr2+1,arr2+1+bn2);
    long long ans=0;
    for(int i = 1; i<=bn1; i++){
        if(i != bn1 && arr1[i].first == arr1[i+1].first) continue;
        pii k = {-arr1[i].first+1, -1e18};
        long long idx = lower_bound(arr2+1,arr2+1+bn2,k)-arr2-1;
        if((arr1[i].first+arr2[idx].first) == 0) ans = max(ans, arr1[i].second + arr2[idx].second);
    }
    
    cout << ans;
}
