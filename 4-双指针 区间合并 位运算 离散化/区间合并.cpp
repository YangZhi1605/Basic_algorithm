#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> PII;
int n;//n个区间
vector<PII> segs;

//可以先按左端点排序，再维护一个区间，与后面一个个区间进行三种情况的比较，存储到数组里去。
void merge(vector<PII> &segs){ //因为使用的是方法，这个取地址符就一定不能省略。不然不能修改结果了，其实也可以不写成方法 
	vector<PII> res;
	sort(segs.begin(),segs.end());
	
	int st = -2e9,ed = -2e9;
	for(auto seg:segs){
		if(ed < seg.first){ // 情况1：两个区间无法合并 	倘若一个区间的终点小于另一个区间的起点，这就是不相交 
			//在区间1的起点不是初始起点的情况下，保存结果 
			if(st != -2e9) res.push_back({st,ed}); //区间1放进res数组
			st = seg.first;  //维护区间2
			ed = seg.second;
		}
		//现在是两个区间有交点的情况，就需要把右交点更新为较长的那个。 
		else if(ed < seg.second) ed = max(ed,seg.second); 
		//(实际上也有情况3：区间1包含区间2，此时不需要任何操作，可以省略)
	}
	//这块是对区间2 的再次处理，上面处理两个区间无法合并的时候，比如if(ed < seg.first)是最后一次循环了 
	//第一次把区间1存到结果中了， 同时对st,ed更新为区间2的，此时就需要最后补存一下 
	if(st != -2e9)  res.push_back({st,ed});
	segs = res;
}

int main(){
	
	cin >> n;
	for(int i = 0; i < n;i++){
		int l,r;
		cin >> l >> r;
		segs.push_back({l,r});
	}
	
	//合并区间 
	merge(segs);
	//输出
	cout << segs.size()  << endl;
	
	return 0;
}
