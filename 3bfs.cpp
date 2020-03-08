#include<bits/stdc++.h>
using namespace std;
int minPathLength(vector<vector<int> > grids, int sr, int sc, int tr, int tc);
int main(){
	int T; cin>>T;
	for(int j=0; j<T; j++){
		int n, m; cin>>n>>m;
		vector<vector<int> > v;
		for(int i=0; i<n; i++){
			vector<int> v1(m);
			for(int j=0; j<m; j++){
				char c; cin>>c;
				if(c=='.'){
					v1[j] = 1;
				}
				else {
					v1[j] = 0;
				}
			}
			v.push_back(v1);
		}
		
		int x1, x2, x3, y1, y2, y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		int res1 = minPathLength(v, x1-1, y1-1, x2-1, y2-1); //cout<<res;
		int res2 = 0;
		if(res1 == -1) {
			cout<<res1<<endl;
			continue;
		}
		
		else { res2 = minPathLength(v, x2-1, y2-1, x3-1, y3-1); //cout<<res;
			if(res2 == -1) {
				cout<<res2<<endl;
				continue;
			}
		}
		
		cout<<res1+res2<<endl;
	}
	return 0;
}

int minPathLength(vector<vector<int> > grids, int sr, int sc, int tr, int tc){

	if (grids.empty())
		return -1;
	//定义方向：右移、左移、上移、下移
	int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	int m = grids.size(), n = grids[0].size();//行列数
//		for(int i=0; i<n; i++){
//			for(int j=0; j<m; j++){
//				cout<<grids[i][j]<<" "; 
//			}
//			cout<<endl;
//		}
	//queue存储接下来要遍历的点
	queue<pair<int, int> > queue_point;
	//首先将0,0点入队列
	queue_point.push(pair<int, int>(sr, sc));
	int pathLength = 0;
	while (!queue_point.empty())
	{
		
		int size = queue_point.size();
		pathLength++;
		//cout<<"pathlength:"<<pathLength<<endl;
		while (size-- > 0)
		{
			pair<int, int> cur = queue_point.front();
			queue_point.pop();
			for (int i=0; i<4; i++) 
			{
				
				int nr = cur.first + d[i][0], nc = cur.second + d[i][1];//下一行、列
//				cout<<"当前点："<<cur.first<<","<<cur.second<<endl;
				pair<int, int> next(nr, nc);
				
				if (next.first < 0 || next.second < 0
					||next.first >= m || next.second >= n)
				{
					continue;
				}
				
				if(grids[next.first][next.second] == 0)
					continue;
				//cout<<"dian："<<nr<<","<<nc<<endl;
				grids[next.first][next.second] = 0;//标记
				if (next.first == tr && next.second == tc)
					return pathLength;
				queue_point.push(next);
			}
		}
	}
	return -1;
}
