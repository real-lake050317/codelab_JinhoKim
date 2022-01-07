#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> Array;
vector<int> MinTree_Array;
vector<int> MaxTree_Array;
vector<pair<int, int> > Cmd;

int Min(int A, int B){
	if (A < B) return A;
	return B;
}

int Bigger(int A, int B){
	if (A > B) return A;
	return B;
}

void Input(){
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		int a;
		cin >> a;
		Array.push_back(a);
	}	
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		Cmd.push_back(make_pair(a, b));
	}
}

int Make_SegTree(int Node, int Start, int End, bool T){
	if (Start == End){
		if (T == false){
			return MinTree_Array[Node] = Array[Start];
		}
		else{
			return MaxTree_Array[Node] = Array[Start];
		}
	}
	
	int Mid = (Start + End) / 2;
	int Left_Result = Make_SegTree(Node * 2, Start, Mid, T);
	int Right_Result = Make_SegTree(Node*2 + 1, Mid+1, End, T);
	
	if (T == false){
		MinTree_Array[Node] = Min(Left_Result, Right_Result);
		return MinTree_Array[Node];
	}
	else {
		MaxTree_Array[Node] = Bigger(Left_Result, Right_Result);
		return MaxTree_Array[Node];
	}
}

int Query(int Node, int Start, int End, int Left, int Right, bool T){
	if (Left > End || Right < Start) {
		if (T == false) return 2e9;
		else return -2e9;
	}
	if (Left <= Start && End <= Right){
		if (T == false) return MinTree_Array[Node];
		else return MaxTree_Array[Node];
	}
	int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right, T);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right, T);
 
    if (T == false) return Min(Left_Result, Right_Result);
    else return Bigger(Left_Result, Right_Result);
}
 
void Solution()
{
    int Tree_Height = ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    MinTree_Array.resize(Tree_Size);
    MaxTree_Array.resize(Tree_Size);
 
    Make_SegTree(1, 0, N - 1, false);
    Make_SegTree(1, 0, N - 1, true);
 
    for (int i = 0; i < Cmd.size(); i++)
    {
        int Index = Cmd[i].first - 1;
        int Index2 = Cmd[i].second - 1;
        
        int Min_Result = Query(1, 0, N - 1, Index, Index2, false);
        int Max_Result = Query(1, 0, N - 1, Index, Index2, true);
 
        cout << Min_Result << " " << Max_Result << endl;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;	
}
